//FormAI DATASET v1.0 Category: Chat server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int serverSocket, clientSocket[MAX_CLIENTS];
    struct sockaddr_in address;
    int opt = 1;
    char buffer[BUFFER_SIZE] = {0};
    int connectedClients = 0;

    // Creating server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Setting server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to address
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error binding socket to address");
        exit(EXIT_FAILURE);
    }

    // Listening on server socket
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        perror("Error listening on server");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        fd_set readfds;
        int max_sd = 0;

        // Set file descriptors for server and clients
        FD_ZERO(&readfds);
        FD_SET(serverSocket, &readfds);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clientSocket[i] > 0) {
                FD_SET(clientSocket[i], &readfds);
                if (clientSocket[i] > max_sd) {
                    max_sd = clientSocket[i];
                }
            }
        }

        // Wait for activity on any socket
        int result = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (result < 0) {
            perror("Error selecting sockets to read");
            exit(EXIT_FAILURE);
        }

        // Handle new connection request
        if (FD_ISSET(serverSocket, &readfds)) {
            int newClientSocket;
            struct sockaddr_in clientAddress;
            int clientAddressLength = sizeof(clientAddress);

            if ((newClientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, (socklen_t *)&clientAddressLength)) < 0) {
                perror("Error accepting new client");
                exit(EXIT_FAILURE);
            }

            char* welcomingMessage = "Welcome to the Happy Chat Room!\nPlease introduce yourself:\n";
            send(newClientSocket, welcomingMessage, strlen(welcomingMessage), 0);

            // Add new client socket to list of connected clients
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clientSocket[i] == 0) {
                    clientSocket[i] = newClientSocket;
                    connectedClients++;
                    printf("New client connected\n");
                    break;
                }
            }
        }

        // Handle messages from clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(clientSocket[i], &readfds)) {
                int readBytes;
                if ((readBytes = read(clientSocket[i], buffer, BUFFER_SIZE)) == 0) {
                    // Connection closed by client, remove client from list
                    close(clientSocket[i]);
                    clientSocket[i] = 0;
                    connectedClients--;
                    printf("Client disconnected\n");
                } else {
                    // Send message to all connected clients except current
                    buffer[readBytes] = '\0';
                    printf("Received message: %s", buffer);
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (clientSocket[j] > 0 && clientSocket[j] != clientSocket[i]) {
                            char formattedMessage[BUFFER_SIZE + 32];
                            char clientName[20];
                            sprintf(clientName, "Client %d", i+1);
                            time_t currentTime;
                            time(&currentTime);
                            char* timeString = ctime(&currentTime);
                            timeString[strlen(timeString)-1] = '\0'; // Remove newline character from ctime string
                            snprintf(formattedMessage, BUFFER_SIZE+32, "[%s] %s: %s", timeString, clientName, buffer);
                            send(clientSocket[j], formattedMessage, strlen(formattedMessage), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}