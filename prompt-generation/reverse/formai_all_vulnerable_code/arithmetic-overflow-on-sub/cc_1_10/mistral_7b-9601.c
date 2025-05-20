//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_CLIENTS 5

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_fd, NUM_CLIENTS);

    printf("Server started on port %d\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();

        if (pid == 0) { // Child process
            close(server_fd); // Close listening socket
            int read_size;

            // Receive data from client and calculate speed
            while ((read_size = recv(new_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                clock_t start = clock();
                send(new_socket, buffer, read_size, 0);
                clock_t end = clock();
                double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                double speed = (double)read_size / time_taken;
                printf("Client %s: Speed %f bytes/sec\n",
                       inet_ntoa(address.sin_addr), speed);
            }

            close(new_socket); // Close client socket
            exit(EXIT_SUCCESS);
        } else { // Parent process
            close(new_socket); // Close accepted socket
        }
    }

    return 0;
}