//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void chat(int client_socket);

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address, client_address;
    int server_socket, client_socket, client_address_length;

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return 1;
    }

    // Setting server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind the socket with the server address
    if (bind(server_socket, (const struct sockaddr *)&server_address,
             sizeof(server_address)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        return 1;
    }

    // Accept incoming connections and start chatting
    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address,
                               (socklen_t *)&client_address_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }
        // Initiate chat in a recursive manner
        chat(client_socket);
    }

    return 0;
}

// Recursive function for chat
void chat(int client_socket) {
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    int read_size;

    // Read incoming message
    if ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Incoming message: %s", buffer);
        // Provide response
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\n")] = '\0'; // Removing newline character
        // Send response
        if (send(client_socket, message, strlen(message), 0) < 0) {
            perror("Error sending message");
            close(client_socket);
            return;
        }
        // Recursively call chat function
        chat(client_socket);
    } else if (read_size == 0) {
        printf("Client disconnected\n");
        close(client_socket);
        return;
    } else {
        perror("Error receiving message");
        close(client_socket);
        return;
    }
}