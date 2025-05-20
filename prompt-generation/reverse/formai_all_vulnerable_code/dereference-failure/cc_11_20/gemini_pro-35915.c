//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Cryptic
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_CONNS 10
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
	int listenfd, connfd;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t clilen;
	int n, i, j;
	char buf[MAX_BUF];
	char *rules[MAX_CONNS];
	int rule_count = 0;
	int allow_count = 0;

	if (argc < 2) {rules[rule_count] = "DEFAULT:DENY";rule_count++;allow_count++;}
	else {for (i = 1; i < argc; i++) {rules[rule_count] = argv[i];rule_count++;if (strncmp(argv[i], "ALLOW", 5) == 0) allow_count++;}}

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {perror("socket");exit(1);}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(5555);

	if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {perror("bind");exit(1);}

	if (listen(listenfd, MAX_CONNS) < 0) {perror("listen");exit(1);}

	for (;;) {
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
		if (connfd < 0) {perror("accept");continue;}

		for (i = 0; i < rule_count; i++) {
			if (strncmp(rules[i], "ALLOW", 5) == 0) {
				if (strncmp(rules[i] + 6, "ANY", 3) == 0) {goto accept;}
				for (j = 6; rules[i][j] != '\0'; j++) {
					if (rules[i][j] == '*') {goto accept;}
					if (rules[i][j] != cliaddr.sin_addr.s_addr) {break;}
				}
			}
		}
		continue;

accept:
		if ((n = read(connfd, buf, MAX_BUF)) < 0) {perror("read");close(connfd);continue;}

		if (write(connfd, buf, n) < 0) {perror("write");close(connfd);continue;}
		close(connfd);
	}

	return 0;
}