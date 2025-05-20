//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_fd, new_socket_fd, portno;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len;
    char buffer[256];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set the port number
    portno = atoi(argv[1]);

    // Set up the server address structure
    memset((char *) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(portno);

    // Bind the socket to the address
    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", portno);

    // Accept an incoming connection
    client_len = sizeof(client_address);
    new_socket_fd = accept(socket_fd, (struct sockaddr *) &client_address, &client_len);
    if (new_socket_fd < 0) {
        perror("accept failed");
        exit(1);
    }

    // Read data from the client
    while (1) {
        bzero(buffer, 256);
        read(new_socket_fd, buffer, 255);
        printf("Received: %s\n", buffer);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        // Send the response back to the client
        write(new_socket_fd, "Hello, client!", 14);
    }

    // Close the socket
    close(new_socket_fd);
    close(socket_fd);
    return 0;
}