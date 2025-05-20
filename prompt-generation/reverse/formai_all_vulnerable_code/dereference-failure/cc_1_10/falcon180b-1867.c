//Falcon-180B DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit program
void error_message(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error_message("socket");
    }

    // Set socket options
    int opt = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Create address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error_message("inet_pton");
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_message("connect");
    }

    // Send data to server
    char send_buffer[BUFFER_SIZE];
    strcpy(send_buffer, "Hello, World!");
    int bytes_sent = send(socket_fd, send_buffer, strlen(send_buffer), 0);
    if (bytes_sent == -1) {
        error_message("send");
    }

    // Receive data from server
    char receive_buffer[BUFFER_SIZE];
    int bytes_received = recv(socket_fd, receive_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        error_message("recv");
    }
    receive_buffer[bytes_received] = '\0';
    printf("Received: %s\n", receive_buffer);

    // Close socket
    close(socket_fd);
    return 0;
}