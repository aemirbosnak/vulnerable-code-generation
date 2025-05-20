//GEMINI-pro DATASET v1.0 Category: Networking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to send data to the server
int send_data(int sockfd, char *data, int len) {
    int sent = 0;
    while (sent < len) {
        int ret = send(sockfd, data + sent, len - sent, 0);
        if (ret < 0) {
            return -1;
        }
        sent += ret;
    }
    return 0;
}

// Function to receive data from the server
int receive_data(int sockfd, char *data, int len) {
    int received = 0;
    while (received < len) {
        int ret = recv(sockfd, data + received, len - received, 0);
        if (ret < 0) {
            return -1;
        } else if (ret == 0) {
            return 0;
        }
        received += ret;
    }
    return received;
}

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return -1;
    }
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send data to the server
    char *data = "Hello from the client";
    int len = strlen(data);
    if (send_data(sockfd, data, len) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive data from the server
    char buf[1024];
    int recv_len = receive_data(sockfd, buf, sizeof(buf));
    if (recv_len < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    } else if (recv_len == 0) {
        printf("Server closed the connection\n");
        close(sockfd);
        return 0;
    }

    // Print the data received from the server
    printf("Received from the server: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}