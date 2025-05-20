//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAXLINE 1024
#define PORT 587
#define SERVER "imap.gmail.com"

// Message structure
struct message {
    char *subject;
    char *body;
};

// Player structure
struct player {
    int sockfd;
    char *name;
    struct message **messages;
    int num_messages;
};

// Global variables
int server_sockfd;
struct player *players[10];
int num_players = 0;

// Function to handle incoming messages
void *handle_incoming(void *arg) {
    struct player *player = (struct player *)arg;
    char buffer[MAXLINE];

    while (recv(player->sockfd, buffer, MAXLINE, 0) > 0) {
        // Parse the message
        char *command = strtok(buffer, " ");
        char *args = strtok(NULL, "\0");

        // Handle the command
        if (strcmp(command, "JOIN") == 0) {
            // Join the game
            player->name = strdup(args);
            players[num_players++] = player;
            
            // Send a welcome message to the player
            sprintf(buffer, "Welcome, %s!\n", player->name);
            send(player->sockfd, buffer, strlen(buffer), 0);
            
            // Broadcast a message to all other players
            sprintf(buffer, "%s has joined the game.", player->name);
            for (int i = 0; i < num_players; i++) {
                if (players[i] != player) {
                    send(players[i]->sockfd, buffer, strlen(buffer), 0);
                }
            }
        } else if (strcmp(command, "LEAVE") == 0) {
            // Leave the game
            for (int i = 0; i < num_players; i++) {
                if (players[i] == player) {
                    players[i] = players[num_players - 1];
                    num_players--;
                    break;
                }
            }

            // Send a goodbye message to the player
            sprintf(buffer, "Goodbye, %s!\n", player->name);
            send(player->sockfd, buffer, strlen(buffer), 0);

            // Broadcast a message to all other players
            sprintf(buffer, "%s has left the game.", player->name);
            for (int i = 0; i < num_players; i++) {
                send(players[i]->sockfd, buffer, strlen(buffer), 0);
            }

            // Close the player's socket
            close(player->sockfd);

            // Free the player's memory
            free(player->name);
            for (int i = 0; i < player->num_messages; i++) {
                free(player->messages[i]->subject);
                free(player->messages[i]->body);
                free(player->messages[i]);
            }
            free(player);
            
            return NULL;
        } else if (strcmp(command, "SEND") == 0) {
            // Send a message to another player
            char *recipient = strtok(args, " ");
            char *message = strtok(NULL, "\0");

            // Find the recipient player
            struct player *recipient_player = NULL;
            for (int i = 0; i < num_players; i++) {
                if (strcmp(players[i]->name, recipient) == 0) {
                    recipient_player = players[i];
                    break;
                }
            }

            // If the recipient player was found, send the message
            if (recipient_player != NULL) {
                sprintf(buffer, "[%s] %s", player->name, message);
                send(recipient_player->sockfd, buffer, strlen(buffer), 0);
            } else {
                // If the recipient player was not found, send an error message
                sprintf(buffer, "Player not found: %s\n", recipient);
                send(player->sockfd, buffer, strlen(buffer), 0);
            }
        } else if (strcmp(command, "LIST") == 0) {
            // List the player's messages
            for (int i = 0; i < player->num_messages; i++) {
                sprintf(buffer, "%d. %s\n", i + 1, player->messages[i]->subject);
                send(player->sockfd, buffer, strlen(buffer), 0);
            }
        } else if (strcmp(command, "READ") == 0) {
            // Read a message
            int message_num = atoi(args);

            // If the message number is valid, send the message to the player
            if (message_num > 0 && message_num <= player->num_messages) {
                sprintf(buffer, "%s\n", player->messages[message_num - 1]->body);
                send(player->sockfd, buffer, strlen(buffer), 0);
            } else {
                // If the message number is invalid, send an error message
                sprintf(buffer, "Invalid message number: %d\n", message_num);
                send(player->sockfd, buffer, strlen(buffer), 0);
            }
        } else {
            // Send an error message
            sprintf(buffer, "Invalid command: %s\n", command);
            send(player->sockfd, buffer, strlen(buffer), 0);
        }
    }

    return NULL;
}

int main() {
    

    // Create a socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to the address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd;
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            perror("accept");
            exit(1);
        }

        // Create a new player
        struct player *player = (struct player *)malloc(sizeof(struct player));
        player->sockfd = client_sockfd;
        player->name = NULL;
        player->messages = NULL;
        player->num_messages = 0;

        // Create a new thread to handle incoming messages from the player
        pthread_t thread;
        pthread_create(&thread, NULL, handle_incoming, (void *)player);
    }

    // Close the server socket
    close(server_sockfd);

    return 0;
}