//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage:./smtp_client <server_ip> <port> <username> <password>\n");
        return 1;
    }

    char *server_ip = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char *response = NULL;
    while (1) {
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        send(sockfd, buffer, strlen(buffer), 0);

        response = calloc(1, BUFFER_SIZE);
        memset(response, 0, BUFFER_SIZE);

        int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving response\n");
            break;
        }

        printf("Response: %s", response);
        free(response);
    }

    close(sockfd);
    return 0;
}