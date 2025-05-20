//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    // Check the command line arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    // Initialize the variables
    int socket_fd, num_bytes_read;
    struct sockaddr_in server_address;
    char buffer[1024];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a login command
    num_bytes_read = send(socket_fd, "USER username\r\n", 12, 0);
    if (num_bytes_read == -1) {
        perror("send");
        return 1;
    }

    // Receive the server response
    num_bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (num_bytes_read == -1) {
        perror("recv");
        return 1;
    }

    // Check the response
    if (strncmp(buffer, "+OK\r\n", 5)!= 0) {
        fprintf(stderr, "Invalid response: %s\n", buffer);
        return 1;
    }

    // Send a password command
    num_bytes_read = send(socket_fd, "PASS password\r\n", 13, 0);
    if (num_bytes_read == -1) {
        perror("send");
        return 1;
    }

    // Receive the server response
    num_bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (num_bytes_read == -1) {
        perror("recv");
        return 1;
    }

    // Check the response
    if (strncmp(buffer, "+OK\r\n", 5)!= 0) {
        fprintf(stderr, "Invalid response: %s\n", buffer);
        return 1;
    }

    // Send a list command
    num_bytes_read = send(socket_fd, "LIST\r\n", 6, 0);
    if (num_bytes_read == -1) {
        perror("send");
        return 1;
    }

    // Receive the server response
    num_bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (num_bytes_read == -1) {
        perror("recv");
        return 1;
    }

    // Check the response
    if (strncmp(buffer, "+OK\r\n", 5)!= 0) {
        fprintf(stderr, "Invalid response: %s\n", buffer);
        return 1;
    }

    // Receive the list of messages
    num_bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (num_bytes_read == -1) {
        perror("recv");
        return 1;
    }

    // Print the list of messages
    printf("List of messages:\n");
    printf("%s", buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}