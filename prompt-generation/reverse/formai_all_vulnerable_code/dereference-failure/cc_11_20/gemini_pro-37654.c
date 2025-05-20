//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <port> <destination_ip>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *destination_ip = argv[2];

    // Create a listening socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        perror("socket");
        return 1;
    }

    // Set up the listening socket address
    struct sockaddr_in listening_address;
    memset(&listening_address, 0, sizeof(listening_address));
    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(port);
    listening_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the listening socket to the address
    if (bind(listening_socket, (struct sockaddr *)&listening_address, sizeof(listening_address)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(listening_socket, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections and forward them to the destination
    while (1) {
        // Accept an incoming connection
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a socket to connect to the destination
        int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (destination_socket == -1) {
            perror("socket");
            close(client_socket);
            continue;
        }

        // Set up the destination socket address
        struct sockaddr_in destination_address;
        memset(&destination_address, 0, sizeof(destination_address));
        destination_address.sin_family = AF_INET;
        destination_address.sin_port = htons(80);
        destination_address.sin_addr.s_addr = inet_addr(destination_ip);

        // Connect to the destination
        if (connect(destination_socket, (struct sockaddr *)&destination_address, sizeof(destination_address)) == -1) {
            perror("connect");
            close(client_socket);
            close(destination_socket);
            continue;
        }

        // Forward data between the client and destination
        char buffer[BUFFER_SIZE];
        while (1) {
            // Read data from the client
            int bytes_read = read(client_socket, buffer, BUFFER_SIZE);
            if (bytes_read == 0) {
                break;
            } else if (bytes_read == -1) {
                perror("read");
                break;
            }

            // Write data to the destination
            if (write(destination_socket, buffer, bytes_read) == -1) {
                perror("write");
                break;
            }
        }

        // Close the client and destination sockets
        close(client_socket);
        close(destination_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}