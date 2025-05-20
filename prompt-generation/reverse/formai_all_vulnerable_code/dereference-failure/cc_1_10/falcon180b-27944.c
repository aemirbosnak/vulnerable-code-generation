//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    char *user = "user";
    char *pass = "password";
    char *cmd = "STAT\r\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server = gethostbyname("pop3.example.com");
    if (server == NULL) {
        printf("Error: Failed to resolve hostname\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, user, strlen(user), 0);
    send(sockfd, pass, strlen(pass), 0);

    while (1) {
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error: Failed to receive data\n");
            exit(1);
        }

        buffer[n] = '\0';
        printf("Received: %s", buffer);

        if (strstr(buffer, "+OK")) {
            send(sockfd, cmd, strlen(cmd), 0);
        }
    }

    close(sockfd);
    return 0;
}