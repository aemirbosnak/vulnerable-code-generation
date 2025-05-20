//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

// Function to print error message and exit
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error binding socket");
    }

    if (listen(sockfd, 5) < 0) {
        error("Error listening on socket");
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        clientlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clientlen);
        if (newsockfd == -1) {
            error("Error accepting connection");
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    return 0;
}