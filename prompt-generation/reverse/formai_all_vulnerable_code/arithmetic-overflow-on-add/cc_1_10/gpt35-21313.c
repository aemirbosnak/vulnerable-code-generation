//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *success_msg = "Test completed successfully!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server waiting for incoming connections on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New test request from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Perform speed test
        int packet_size = 1024 * 1024 * 2; // send 2MB packets
        int total_bytes_sent = 0;
        int start_time, end_time;
        start_time = time(NULL);
        while (total_bytes_sent < packet_size) {
            int bytes_sent = send(new_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_sent < 0) {
                perror("send");
                exit(EXIT_FAILURE);
            }
            total_bytes_sent += bytes_sent;
        }
        end_time = time(NULL);

        printf("Test completed in %d seconds\n", end_time - start_time);

        // Send success message to client
        send(new_socket, success_msg, strlen(success_msg), 0);

        // Close socket
        close(new_socket);
    }

    return 0;
}