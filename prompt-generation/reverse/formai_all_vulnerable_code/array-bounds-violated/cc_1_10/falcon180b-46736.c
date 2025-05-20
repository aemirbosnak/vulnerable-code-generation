//Falcon-180B DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char buffer[BUF_SIZE];
    while (1) {
        // Receive data from server
        int bytes_received = recv(sockfd, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data from server\n");
            exit(1);
        }

        // Print received data
        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        // Send data to server
        printf("Enter data to send: ");
        fgets(buffer, BUF_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}