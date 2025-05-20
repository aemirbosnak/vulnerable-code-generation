//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAXLINE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLINE];

    if (argc < 3) {
        printf("Usage:./pop3-client <server-name> <port-number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)server->h_addr), &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(0);
    }

    printf("Connected to server\n");

    while (TRUE) {
        printf("Enter command (quit to exit): ");
        fgets(buffer, MAXLINE, stdin);
        n = strlen(buffer);
        if (n > 0 && buffer[n - 1] == '\n') {
            buffer[--n] = '\0';
        }
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        send(sockfd, buffer, n, 0);
        bzero(buffer, MAXLINE);
        n = recv(sockfd, buffer, MAXLINE, 0);
        if (n <= 0) {
            printf("Error: Connection closed\n");
            exit(0);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}