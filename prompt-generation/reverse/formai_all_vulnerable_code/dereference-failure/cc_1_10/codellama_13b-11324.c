//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: active
/*
 * C Port Scanner Example Program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PORT_MIN 1024
#define PORT_MAX 65535
#define IP_ADDR "192.168.1.1"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Fill in the server address structure
    server = gethostbyname(IP_ADDR);
    if (server == NULL) {
        perror("Error getting hostname");
        exit(1);
    }
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_MIN);
    memcpy((char *) &server_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message to the server
    n = write(sockfd, "Hello, server!\n", strlen("Hello, server!\n"));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Read the response from the server
    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}