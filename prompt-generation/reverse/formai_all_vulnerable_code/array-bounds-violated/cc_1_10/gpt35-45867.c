//FormAI DATASET v1.0 Category: Socket programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFF 1024
#define PORT 8888

int main() {
    int sockfd, newsockfd, client_len, recv_len;
    char buffer[MAX_BUFF];
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    listen(sockfd, 5);
    puts("Waiting for clients...");

    // Accept incoming connection
    client_len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);
    if (newsockfd < 0) {
        perror("Could not accept connection");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    char welcome_msg[MAX_BUFF] = "Greetings traveler, welcome to the kingdom of Socket.\n";
    send(newsockfd, welcome_msg, strlen(welcome_msg), 0);

    // Receive message from client
    int count = 0;
    while ((recv_len = recv(newsockfd, buffer, MAX_BUFF, 0)) > 0) {
        buffer[recv_len] = '\0';
        printf("Received Message: %s", buffer);

        // Send response
        if (count == 0) {
            char response[MAX_BUFF] = "Ahoy there! What brings ye to our kingdom?\n";
            send(newsockfd, response, strlen(response), 0);
            count++;
        } else if (count == 1) {
            char response[MAX_BUFF] = "A quest ye say? We have plenty to choose from.\n";
            send(newsockfd, response, strlen(response), 0);
            count++;
        } else {
            char response[MAX_BUFF] = "Fare thee well, adventurer!\n";
            send(newsockfd, response, strlen(response), 0);
            break;
        }
    }

    // Close sockets
    close(sockfd);
    close(newsockfd);

    return 0;
}