//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *host;
    int port;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int sockfd;

    // Check if the correct number of arguments have been provided
    if (argc!= 3) {
        printf("Usage:./ping_test <host> <port>\n");
        return 1;
    }

    // Assign the host and port values
    host = argv[1];
    port = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    // Set up the host address structure
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Failed to resolve host: %s\n", host);
        close(sockfd);
        return 1;
    }

    // Assign the IP address to the host variable
    host = inet_ntoa(*(struct in_addr *)server->h_addr);

    // Set up the server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    // Send a message to the server
    printf("Sending message to server...\n");
    if (send(sockfd, "PING", strlen("PING"), 0) < 0) {
        printf("Failed to send message: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    // Receive a message from the server
    printf("Waiting for response from server...\n");
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Failed to receive message: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    } else if (bytes_received == 0) {
        printf("Server did not respond.\n");
        close(sockfd);
        return 1;
    }

    // Print the response from the server
    printf("Response from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}