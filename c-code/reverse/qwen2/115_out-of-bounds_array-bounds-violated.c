#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void download_file(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        fwrite(buffer, 1, bytes_received, file);
    }

    if (bytes_received == -1) {
        perror("Error receiving data from server");
    } else {
        printf("File downloaded successfully\n");
    }

    fclose(file);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    // Server address configuration
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // Send command to list files
    send(sockfd, "LIST\r\n", 6, 0);

    // Receive response
    char buffer[BUFFER_SIZE];
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s\n", buffer);

    // Download a file
    download_file(sockfd, "example.txt");

    close(sockfd);
    return 0;
}
