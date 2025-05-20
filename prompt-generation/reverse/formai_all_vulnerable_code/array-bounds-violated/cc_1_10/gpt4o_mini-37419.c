//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

void handle_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // Null-terminate the received string
    printf("Server: %s", buffer);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Client: %s", command);
    handle_response(sockfd);
}

int main(void) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with FTP server IP

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    handle_response(sockfd); // Initial server greeting

    // Login to FTP server
    send_command(sockfd, "USER anonymous\r\n");
    send_command(sockfd, "PASS guest@example.com\r\n");

    // List files
    send_command(sockfd, "PASV\r\n");
    char buffer[BUFFER_SIZE];
    int p1, p2;
    sscanf(buffer, "%d,%d", &p1, &p2); // Extract passive port from response
    int data_port = p1 * 256 + p2;

    // Create data socket
    int data_sockfd;
    struct sockaddr_in data_addr;

    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        perror("Unable to create data socket");
        exit(EXIT_FAILURE);
    }

    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with FTP server IP

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Data socket connection failed");
        close(data_sockfd);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    send_command(sockfd, "LIST\r\n");

    // Receive file list
    int bytes_received;
    while ((bytes_received = recv(data_sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("Error receiving file list");
    }

    close(data_sockfd); // Close data socket

    send_command(sockfd, "QUIT\r\n"); // Close FTP session
    close(sockfd); // Close main socket
    printf("FTP session ended.\n");

    return 0;
}