//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_SIZE 1024
#define PORT 8080
#define BACKLOG 10

int main() {
    int sockfd, newsockfd, len, n;
    struct sockaddr_in address;
    struct sockaddr_in client_address;
    char buffer[MAX_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        len = sizeof(client_address);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_address, (socklen_t*)&len);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        while (1) {
            memset(buffer, 0, MAX_SIZE);
            n = recv(newsockfd, buffer, MAX_SIZE, 0);
            if (n < 0) {
                perror("recv");
                exit(EXIT_FAILURE);
            }

            if (n == 0) {
                printf("Client disconnected\n");
                close(newsockfd);
                break;
            }

            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);

            if (strcmp(buffer, "QoS") == 0) {
                printf("QoS request received\n");
                // Implement QoS logic here
            }
        }
    }

    return 0;
}