//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server_address;
    struct hostent *server;

    char buffer[MAXSIZE];
    int bytes_received;

    // Check if user provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port_number\n", argv[0]);
        exit(1);
    }

    // Get hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host exist\n");
        exit(1);
    }

    // Set up server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error: Unable to create socket");
        exit(1);
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error: Unable to connect to server");
        exit(1);
    }

    // Receive message from server
    bytes_received = recv(socket_fd, buffer, MAXSIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Error: Unable to receive message");
        exit(1);
    }

    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}