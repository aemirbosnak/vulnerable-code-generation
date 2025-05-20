//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_CHAT_MSG_LEN 100

int main() {
    int server_fd, client_fd, i;
    struct sockaddr_in server_addr, client_addr;
    struct sockaddr_in broadcast_addr;
    char client_buffer[MAX_CHAT_MSG_LEN];
    char broadcast_buffer[MAX_CHAT_MSG_LEN];
    char *client_name;

    // Create a TCP socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // Bind the server socket to a specific port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        return 1;
    }

    // Start listening for client connections
    listen(server_fd, MAX_CLIENTS);

    while (1) {
        // Accept a client connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&i)) < 0) {
            perror("ERROR on accept");
            return 1;
        }

        // Get the client's name
        client_name = malloc(MAX_CHAT_MSG_LEN);
        if (read(client_fd, client_name, MAX_CHAT_MSG_LEN) < 0) {
            perror("ERROR reading client name");
            return 1;
        }

        // Create a broadcast group for all connected clients
        memset(&broadcast_addr, 0, sizeof(broadcast_addr));
        broadcast_addr.sin_family = AF_INET;
        broadcast_addr.sin_port = htons(PORT);
        inet_pton(AF_INET, "255.255.255.255", &broadcast_addr.sin_addr);

        // Send a welcome message to the client
        write(client_fd, "Welcome to the chat room!\n", strlen("Welcome to the chat room!"));

        // Send a broadcast message to all clients
        memset(broadcast_buffer, 0, sizeof(broadcast_buffer));
        sprintf(broadcast_buffer, "%s has joined the chat room.\n", client_name);
        sendto(client_fd, broadcast_buffer, strlen(broadcast_buffer), 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr));

        // Start a new process for each client
        if ((i = fork()) < 0) {
            perror("ERROR on fork");
            return 1;
        }
        else if (i == 0) {
            // Child process for client
            close(server_fd);
            close(client_fd);
            while (1) {
                // Receive a message from the client
                if (read(client_fd, client_buffer, MAX_CHAT_MSG_LEN) < 0) {
                    perror("ERROR reading message from client");
                    return 1;
                }

                // Send the message to all connected clients
                memset(broadcast_buffer, 0, sizeof(broadcast_buffer));
                sprintf(broadcast_buffer, "%s: %s\n", client_name, client_buffer);
                sendto(server_fd, broadcast_buffer, strlen(broadcast_buffer), 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr));
            }
        }
        else {
            // Parent process for client
            close(client_fd);

            // Receive a message from the server
            if (read(server_fd, broadcast_buffer, MAX_CHAT_MSG_LEN) < 0) {
                perror("ERROR reading broadcast message");
                return 1;
            }

            // Send the message to the client
            write(client_fd, broadcast_buffer, strlen(broadcast_buffer));

            // Close the client socket
            close(client_fd);

            // Exit the process
            exit(0);
        }
    }

    return 0;
}