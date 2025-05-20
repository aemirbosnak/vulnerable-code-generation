//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int bytes_received;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    // Send request for QoS information
    if (send(sockfd, "QoS_INFO", strlen("QoS_INFO"), 0) == -1) {
        printf("Error: Failed to send request\n");
        close(sockfd);
        return 1;
    }

    printf("Request sent\n");

    // Receive QoS information
    while ((bytes_received = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received == 0) {
        printf("Connection closed by server\n");
    } else {
        printf("Error: Failed to receive QoS information\n");
    }

    close(sockfd);
    return 0;
}