//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *username = "your_username";
    char *password = "your_password";

    if (argc!= 3) {
        printf("Usage:./pop3_client <server_address> <port>\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Invalid server address.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    send(sockfd, "USER ", strlen("USER "), 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error: Failed to receive data.\n");
            exit(1);
        }

        printf("Received: %s", buffer);

        if (strstr(buffer, "+OK")) {
            send(sockfd, "PASS ", strlen("PASS "), 0);
            send(sockfd, password, strlen(password), 0);
            send(sockfd, "\r\n", strlen("\r\n"), 0);
        } else if (strstr(buffer, "+OK")) {
            printf("Authentication successful.\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}