//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char buffer[BUFFER_SIZE];
    int port;

    // Check if the user provided a port number
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Get the port number from the user input
    port = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Get the server's address
    host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        printf("Error getting host information: %s\n", strerror(errno));
        exit(1);
    }

    // Fill in the server's address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send a message to the server
    strcpy(buffer, "Hello, World!");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive a message from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Message from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}