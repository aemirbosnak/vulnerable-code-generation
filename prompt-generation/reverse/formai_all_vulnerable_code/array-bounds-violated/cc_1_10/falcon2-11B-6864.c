//Falcon2-11B DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5001

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Create a host structure and fill in with server IP and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    char message[] = "Hello, server!";
    int message_len = strlen(message);
    send(sockfd, message, message_len, 0);

    // Receive a response from the server
    char response[1024];
    int response_len = recv(sockfd, response, sizeof(response), 0);
    if (response_len < 0) {
        perror("recv");
        return 1;
    }
    response[response_len] = '\0';
    printf("Server response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}