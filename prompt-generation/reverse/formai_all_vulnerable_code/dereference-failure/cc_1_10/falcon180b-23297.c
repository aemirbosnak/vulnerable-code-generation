//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    struct hostent *server;
    int addrlen;

    if (argc!= 4) {
        printf("Usage:./client <server> <username> <password>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such server\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(110);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    addrlen = sizeof(cli_addr);
    getsockname(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
    printf("Client IP: %s\n", inet_ntoa(cli_addr.sin_addr));
    printf("Client Port: %d\n", ntohs(cli_addr.sin_port));

    char username[50];
    char password[50];
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    char *p = strtok(buffer, "\r\n");
    while (p!= NULL) {
        printf("%s", p);
        p = strtok(NULL, "\r\n");
    }

    close(sockfd);
    return 0;
}