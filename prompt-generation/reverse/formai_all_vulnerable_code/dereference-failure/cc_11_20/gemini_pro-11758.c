//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <port> <target>\n", argv[0]);
		return 1;
	}

	int port = atoi(argv[1]);
	char *target = argv[2];

	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		perror("socket");
		return 1;
	}

	struct sockaddr_in listenaddr;
	listenaddr.sin_family = AF_INET;
	listenaddr.sin_addr.s_addr = INADDR_ANY;
	listenaddr.sin_port = htons(port);

	if (bind(listenfd, (struct sockaddr *)&listenaddr, sizeof(listenaddr)) < 0) {
		perror("bind");
		return 1;
	}

	if (listen(listenfd, 10) < 0) {
		perror("listen");
		return 1;
	}

	printf("Proxy listening on port %d...\n", port);

	while (1) {
		int connfd = accept(listenfd, NULL, NULL);
		if (connfd < 0) {
			perror("accept");
			continue;
		}

		char buf[BUF_SIZE];
		int nread = read(connfd, buf, BUF_SIZE);
		if (nread < 0) {
			perror("read");
			close(connfd);
			continue;
		}

		char *host = strtok(buf, "\r\n\n");
		if (!host) {
			close(connfd);
			continue;
		}

		host = strtok(NULL, "\r\n\n");
		if (!host) {
			close(connfd);
			continue;
		}

		host = strtok(host, ":");
		if (!host) {
			close(connfd);
			continue;
		}

		int targetfd = socket(AF_INET, SOCK_STREAM, 0);
		if (targetfd < 0) {
			perror("socket");
			close(connfd);
			continue;
		}

		struct sockaddr_in targetaddr;
		targetaddr.sin_family = AF_INET;
		targetaddr.sin_addr.s_addr = inet_addr(target);
		targetaddr.sin_port = htons(80);

		if (connect(targetfd, (struct sockaddr *)&targetaddr, sizeof(targetaddr)) < 0) {
			perror("connect");
			close(connfd);
			close(targetfd);
			continue;
		}

		write(targetfd, buf, nread);

		char response[BUF_SIZE];
		int nread2 = read(targetfd, response, BUF_SIZE);
		if (nread2 < 0) {
			perror("read");
			close(connfd);
			close(targetfd);
			continue;
		}

		write(connfd, response, nread2);

		close(connfd);
		close(targetfd);
	}

	close(listenfd);

	return 0;
}