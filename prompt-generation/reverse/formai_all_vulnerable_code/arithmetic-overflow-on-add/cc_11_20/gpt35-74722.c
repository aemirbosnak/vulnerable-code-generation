//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024];
    fd_set read_fds;

    // Creating server file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, 
        sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);

    // Set new_socket to non-blocking mode
    if (fcntl(new_socket, F_SETFL, O_NONBLOCK) < 0) {
        perror("fcntl failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Clear read_fds
        FD_ZERO(&read_fds);

        // Add the server socket to read_fds
        FD_SET(server_fd, &read_fds);

        // Select for incoming connection or incoming data
        if (select(server_fd+1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            // Accept incoming connection
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                (socklen_t*)&addrlen))<0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            printf("New connection accepted.\n");

            // Set new_socket to non-blocking mode
            if (fcntl(new_socket, F_SETFL, O_NONBLOCK) < 0) {
                perror("fcntl failed");
                exit(EXIT_FAILURE);
            }
        } else if (new_socket > 0 && FD_ISSET(new_socket, &read_fds)) {
            // Read incoming data
            valread = read( new_socket , buffer, 1024);
            buffer[valread] = '\0';
            printf("Received data: %s\n", buffer);

            // Echo received data back to client
            send(new_socket , buffer , strlen(buffer) , 0 );
            printf("Data sent back to client.\n");
        }
    }

    return 0;
}