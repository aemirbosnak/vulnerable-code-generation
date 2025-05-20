//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) == -1) {
        perror("inet_pton failed");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server.\n");

    // Send request to server
    char* request = "GET /index.html HTTP/1.1\r\nHost: localhost\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send failed");
        exit(1);
    }

    printf("Request sent to server.\n");

    // Receive response from server
    int bytes_received;
    if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) == -1) {
        perror("recv failed");
        exit(1);
    }

    buffer[bytes_received] = '\0';
    printf("Response received from server:\n%s", buffer);

    // Close socket
    close(sockfd);
    printf("Socket closed.\n");

    return 0;
}