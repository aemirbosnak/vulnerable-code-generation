//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_TRIES 3

int main() {
    int sockfd, new_sockfd, num, i;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *message = "NUMBER:";
    char *response = "RESPONSE:";

    // Initialize sockets
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection error");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server\n");

    while (1) {
        // Generate a random number between 1 and 100
        num = rand() % 100 + 1;

        // Send the number to the server
        sprintf(buffer, "%s%d", message, num);
        send(sockfd, buffer, strlen(buffer), 0);
        printf("Sent number: %d\n", num);

        // Receive the response from the server
        memset(buffer, 0, BUFFER_SIZE);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("Received response: %s\n", buffer);

        // Parse the response and print the square of the number sent
        sscanf(buffer, "%s%d", response, &i);
        printf("The square of %d is %d\n", num, i * i);

        // Check for user input to quit
        if (getchar() == 'q' || getchar() == 'Q') {
            break;
        }

        // Reconnect to the server if connection is lost
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) <= 0) {
            perror("Error in receiving data from server");
            if (++i >= MAX_TRIES) {
                perror("Failed to reconnect to server after multiple attempts");
                close(sockfd);
                exit(EXIT_FAILURE);
            }
            printf("Trying to reconnect to server...\n");
            sleep(2);
            if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("Failed to reconnect to server");
                close(sockfd);
                exit(EXIT_FAILURE);
            }
            printf("Reconnected to the server\n");
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}