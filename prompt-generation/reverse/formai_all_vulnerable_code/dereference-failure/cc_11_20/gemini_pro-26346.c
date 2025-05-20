//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char** argv) {
    // Check for proper arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    // Open source file
    FILE* source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Open destination file
    FILE* destination_file = fopen(argv[2], "w");
    if (destination_file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind socket to address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        perror("accept");
        exit(1);
    }

    // Send file to client
    char buf[BUFSIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buf, 1, BUFSIZE, source_file)) > 0) {
        if (write(client_sockfd, buf, bytes_read) != bytes_read) {
            perror("write");
            exit(1);
        }
    }
    if (ferror(source_file)) {
        perror("fread");
        exit(1);
    }

    // Close source file
    fclose(source_file);

    // Close client socket
    close(client_sockfd);

    // Close server socket
    close(sockfd);

    // Return success
    return 0;
}