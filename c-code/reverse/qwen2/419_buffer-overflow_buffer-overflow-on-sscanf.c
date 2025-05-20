#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_LINE_LENGTH 256

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd) {
    char buffer[MAX_LINE_LENGTH];
    while (1) {
        int bytes_read = read(sockfd, buffer, sizeof(buffer) - 1);
        if (bytes_read <= 0) break;
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // Receive initial greeting
    receive_response(sockfd);

    // Authenticate
    send_command(sockfd, "USER username");
    receive_response(sockfd);
    send_command(sockfd, "PASS password");
    receive_response(sockfd);

    // Get message statistics
    send_command(sockfd, "STAT");
    receive_response(sockfd);

    // List message sizes
    send_command(sockfd, "LIST");
    receive_response(sockfd);

    close(sockfd);
    return 0;
}
