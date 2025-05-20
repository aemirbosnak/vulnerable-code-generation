//FormAI DATASET v1.0 Category: Client Server Application ; Style: dynamic
// This is a sample program for a client-server application that calculates the square of a number
// The server accepts connections from clients, receives an integer number from them and sends back the square of that number
// The server can handle multiple clients at the same time
// The communication between the client and server is done using sockets
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    // Create a socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server to its address
    int bind_ret = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_ret == -1) {
        perror("Could not bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listen_ret = listen(server_fd, 5);
    if (listen_ret == -1) {
        perror("Could not listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept a connection from a client
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Could not accept connection");
            exit(EXIT_FAILURE);
        }

        // Receive an integer number from the client
        int num;
        int recv_ret = recv(client_fd, &num, sizeof(num), 0);
        if (recv_ret == -1) {
            perror("Could not receive data from client");
            exit(EXIT_FAILURE);
        }

        // Calculate the square of the number
        int square = num * num;

        // Send back the square of the number to the client
        int send_ret = send(client_fd, &square, sizeof(square), 0);
        if (send_ret == -1) {
            perror("Could not send data to client");
            exit(EXIT_FAILURE);
        }

        // Close the connection to the client
        close(client_fd);
    }

    return 0;
}