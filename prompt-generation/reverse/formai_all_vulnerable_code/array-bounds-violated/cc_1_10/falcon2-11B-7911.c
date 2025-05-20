//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080

int main() {
    int sockfd, n;
    struct sockaddr_in server;
    char send_buffer[1024] = "GET / HTTP/1.1\r\nHost: ";
    char recv_buffer[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        return 1;
    }

    // Set up the address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect failed");
        return 1;
    }

    // Send the ping request
    sprintf(send_buffer + strlen(send_buffer), "%s\r\n", SERVER_IP);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Receive the response
    if ((n = recv(sockfd, recv_buffer, 1024, 0)) == -1) {
        perror("recv failed");
        return 1;
    }
    recv_buffer[n] = '\0';

    // Print the response
    printf("%s", recv_buffer);

    // Close the socket
    close(sockfd);

    return 0;
}