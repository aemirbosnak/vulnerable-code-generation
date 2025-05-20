//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(client_address);
    char buffer[BUFFER_SIZE];
    int n;

    // Create a TCP socket.
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options.
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to the address.
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections.
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept connections.
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Receive data from the client.
        n = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (n == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }
        
        // Reverse the data.
        int i, j;
        for (i = 0, j = n - 1; i < j; i++, j--) {
            char temp = buffer[i];
            buffer[i] = buffer[j];
            buffer[j] = temp;
        }

        // Send the data back to the client.
        if (send(client_socket, buffer, n, 0) == -1) {
            perror("send");
            close(client_socket);
            continue;
        }

        // Close the client socket.
        close(client_socket);
    }

    // Close the server socket.
    close(server_socket);

    return EXIT_SUCCESS;
}