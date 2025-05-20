//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int i;

    if (argc!= 2) {
        printf("Usage:./program <IP address>\n");
        exit(1);
    }

    // Convert IP address string to binary format
    struct in_addr in_addr;
    if (inet_pton(AF_INET, argv[1], &in_addr)!= 1) {
        printf("Invalid IP address.\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(22);
    server_addr.sin_addr.s_addr = in_addr.s_addr;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // Send SSH banner
    if (send(sockfd, "SSH-2.0-OpenSSH_8.2\r\n", 28, 0) == -1) {
        printf("Error sending SSH banner.\n");
        exit(1);
    }

    // Receive server response
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving server response.\n");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("Server response: %s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}