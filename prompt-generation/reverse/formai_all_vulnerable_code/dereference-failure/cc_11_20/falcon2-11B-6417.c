//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE 100
#define MAX_BUF 1000

int main(int argc, char *argv[]) {
    int sockfd, n, ch;
    char buffer[MAX_BUF], line[MAX_LINE], *p, *q;
    struct hostent *hp;
    struct sockaddr_in serv_addr;
    char *host = "example.com";
    int port = 110;

    if (argc > 1) {
        host = argv[1];
    }
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    hp = gethostbyname(host);
    if (hp == NULL) {
        fprintf(stderr, "ERROR: Unknown host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)hp->h_addr, (char *)&serv_addr.sin_addr.s_addr, hp->h_length);
    serv_addr.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    printf("Username: ");
    fgets(line, MAX_LINE, stdin);
    p = strtok(line, "\r\n");
    q = strtok(NULL, "\r\n");

    if (send(sockfd, p, strlen(p), 0) < 0) {
        perror("ERROR sending username");
        return 1;
    }

    if (send(sockfd, "\r\n", 2, 0) < 0) {
        perror("ERROR sending \r\n");
        return 1;
    }

    n = 0;
    while ((ch = getchar())!= EOF) {
        if (ch == '\r' || ch == '\n') {
            break;
        }
        buffer[n++] = ch;
        if (n >= MAX_BUF) {
            perror("ERROR buffer overflow");
            return 1;
        }
    }

    buffer[n] = '\0';

    printf("POP3 server response: %s\n", buffer);

    return 0;
}