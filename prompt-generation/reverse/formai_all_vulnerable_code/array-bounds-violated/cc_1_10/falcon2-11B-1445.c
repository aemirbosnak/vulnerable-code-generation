//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int server_socket, new_socket, port_number, n;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    char buffer[1024];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // Set up server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding error");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, 5);

    // Accept incoming connections
    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (new_socket < 0) {
            perror("Accept error");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive data from client
        n = recv(new_socket, buffer, 1024, 0);
        if (n < 0) {
            perror("Recv error");
            exit(1);
        }
        buffer[n] = '\0';

        // Echo back the message
        send(new_socket, buffer, n, 0);

        // Close the socket
        close(new_socket);
    }

    return 0;
}