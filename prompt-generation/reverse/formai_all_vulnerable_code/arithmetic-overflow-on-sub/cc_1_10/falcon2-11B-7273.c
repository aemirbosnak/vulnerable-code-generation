//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to receive data from the socket
void receive_data(int sockfd, char* buffer, int buflen) {
    int bytes_read = 0;
    ssize_t total_bytes_read = 0;

    while (bytes_read < buflen) {
        total_bytes_read += recv(sockfd, buffer + bytes_read, buflen - bytes_read, 0);
        if (total_bytes_read == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        bytes_read += total_bytes_read;
    }
    printf("Received %d bytes: %s\n", buflen, buffer);
}

// Function to send data over the socket
void send_data(int sockfd, const char* data, int datalen) {
    ssize_t total_bytes_sent = 0;
    while (total_bytes_sent < datalen) {
        total_bytes_sent += send(sockfd, data + total_bytes_sent, datalen - total_bytes_sent, 0);
        if (total_bytes_sent == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }
    printf("Sent %d bytes: %s\n", datalen, data);
}

// Function to close the socket
void close_socket(int sockfd) {
    if (close(sockfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    printf("Socket closed successfully\n");
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    int len = sizeof(server_addr);
    if (connect(sockfd, (struct sockaddr*)&server_addr, len) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    receive_data(sockfd, buffer, sizeof(buffer));
    send_data(sockfd, "Hello, world!", 13);
    close_socket(sockfd);
    return 0;
}