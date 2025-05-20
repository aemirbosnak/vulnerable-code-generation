//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server> <message>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("Invalid server address");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Socket creation failed");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error("Connection failed");
    }

    printf("Connected to server %s on port %d\n", argv[1], 25);

    send(sockfd, argv[2], strlen(argv[2]), 0);

    while (1) {
        bzero(buffer, BUF_SIZE);
        if (recv(sockfd, buffer, BUF_SIZE, 0) == -1) {
            error("Recv failed");
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}