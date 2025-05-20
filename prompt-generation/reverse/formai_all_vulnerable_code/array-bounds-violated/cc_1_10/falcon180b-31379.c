//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER "localhost"
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./pop3_client <username> <password>\n");
        exit(1);
    }

    char *username = argv[1];
    char *password = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    n = recv(sockfd, response, BUFFER_SIZE, 0);

    if (n < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[n] = '\0';

    printf("Server response: %s\n", response);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);

    if (n < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[n] = '\0';

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}