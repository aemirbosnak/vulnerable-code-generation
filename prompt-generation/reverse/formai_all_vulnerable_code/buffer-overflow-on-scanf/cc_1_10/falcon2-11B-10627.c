//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 8192

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];
    int n;

    // Get the port number from the user
    printf("Enter the port number: ");
    scanf("%d", &portno);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error in creating socket");
        return 1;
    }

    // Bind socket
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error in binding");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error in listening");
        return 1;
    }

    // Accept incoming connections
    while (1) {
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t *)&servaddr)) < 0) {
            perror("Error in accepting");
            continue;
        }

        // Receive data from client
        while ((n = recv(newsockfd, buffer, BUFFER_SIZE, 0)) > 0) {
            printf("Received from client: %s\n", buffer);

            // Send data to server
            if ((send(sockfd, buffer, n, 0) < 0)) {
                perror("Error in sending");
                continue;
            }

            // Receive response from server
            if ((n = recv(newsockfd, buffer, BUFFER_SIZE, 0)) > 0) {
                printf("Received from server: %s\n", buffer);

                // Send response to client
                if ((send(newsockfd, buffer, n, 0) < 0)) {
                    perror("Error in sending");
                    continue;
                }
            }
        }
    }

    close(sockfd);
    close(newsockfd);
    return 0;
}