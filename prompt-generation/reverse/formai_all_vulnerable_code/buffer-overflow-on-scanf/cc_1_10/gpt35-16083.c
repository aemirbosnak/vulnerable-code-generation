//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void receive_message(int sock_fd, char *buffer, size_t buffer_size) {
    memset(buffer, 0, buffer_size);

    ssize_t bytes_received = recv(sock_fd, buffer, buffer_size - 1, 0);
    if (bytes_received == -1) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    printf("Server: %s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *port = argv[2];

    // Get the IP address of the server
    struct addrinfo hints = {0};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *server_address_info;
    int status = getaddrinfo(hostname, port, &hints, &server_address_info);
    if (status) {
        fprintf(stderr, "Error getting address info: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct addrinfo *address_iterator = server_address_info;
    int sock_fd = socket(address_iterator->ai_family, address_iterator->ai_socktype, address_iterator->ai_protocol);

    if (sock_fd == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock_fd, server_address_info->ai_addr, server_address_info->ai_addrlen) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message
    char buffer[BUFFER_SIZE];
    receive_message(sock_fd, buffer, BUFFER_SIZE);

    // Send USER command
    char user_command[BUFFER_SIZE];
    printf("Enter a username: ");
    scanf("%s", user_command);
    sprintf(user_command, "USER %s\n", user_command);
    send(sock_fd, user_command, strlen(user_command), 0);
    receive_message(sock_fd, buffer, BUFFER_SIZE);

    // Send PASS command
    char pass_command[BUFFER_SIZE];
    printf("Enter a password: ");
    scanf("%s", pass_command);
    sprintf(pass_command, "PASS %s\n", pass_command);
    send(sock_fd, pass_command, strlen(pass_command), 0);
    receive_message(sock_fd, buffer, BUFFER_SIZE);

    // Send STAT command
    char stat_command[] = "STAT\n";
    send(sock_fd, stat_command, strlen(stat_command), 0);
    receive_message(sock_fd, buffer, BUFFER_SIZE);

    freeaddrinfo(server_address_info);
    close(sock_fd);

    return 0;
}