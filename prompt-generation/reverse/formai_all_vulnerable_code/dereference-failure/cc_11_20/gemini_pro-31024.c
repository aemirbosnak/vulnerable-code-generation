//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_CLIENTS 2

// Structure to store client information
typedef struct client {
    int sockfd;
    char name[32];
    int score;
} client_t;

// Global variables
int num_clients = 0;
client_t clients[MAX_CLIENTS];

int main() {
    int sockfd, newsockfd, port, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set server address
    port = PORT;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for connections
    listen(sockfd, MAX_CLIENTS);

    // Accept connections
    while (num_clients < MAX_CLIENTS) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            continue;
        }

        // Add client to list of clients
        clients[num_clients].sockfd = newsockfd;
        clients[num_clients].name[0] = '\0';
        clients[num_clients].score = 0;
        num_clients++;

        // Send welcome message to client
        snprintf(buffer, sizeof(buffer), "Welcome to the game!\n");
        send(newsockfd, buffer, strlen(buffer), 0);
    }

    // Game loop
    while (1) {
        // Read input from clients
        for (int i = 0; i < num_clients; i++) {
            bzero(buffer, sizeof(buffer));
            recv(clients[i].sockfd, buffer, sizeof(buffer), 0);

            // Check for quit command
            if (strcmp(buffer, "quit") == 0) {
                close(clients[i].sockfd);
                num_clients--;
                continue;
            }

            // Parse input
            char *command, *argument;
            command = strtok(buffer, " ");
            argument = strtok(NULL, " ");

            // Handle commands
            if (strcmp(command, "name") == 0) {
                // Set client name
                strncpy(clients[i].name, argument, sizeof(clients[i].name));
                snprintf(buffer, sizeof(buffer), "Your name is now %s.\n", argument);
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            } else if (strcmp(command, "score") == 0) {
                // Get client score
                snprintf(buffer, sizeof(buffer), "Your score is %d.\n", clients[i].score);
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            } else if (strcmp(command, "guess") == 0) {
                // Handle guess
                int guess = atoi(argument);
                if (guess == rand() % 10) {
                    // Correct guess
                    clients[i].score++;
                    snprintf(buffer, sizeof(buffer), "Correct! Your score is now %d.\n", clients[i].score);
                    send(clients[i].sockfd, buffer, strlen(buffer), 0);
                } else {
                    // Incorrect guess
                    snprintf(buffer, sizeof(buffer), "Incorrect. Try again.\n");
                    send(clients[i].sockfd, buffer, strlen(buffer), 0);
                }
            } else {
                // Unknown command
                snprintf(buffer, sizeof(buffer), "Unknown command: %s\n", command);
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            }
        }

        // Check for game over
        if (num_clients == 0) {
            break;
        }
    }

    // Close sockets
    close(sockfd);
    for (int i = 0; i < num_clients; i++) {
        close(clients[i].sockfd);
    }

    return 0;
}