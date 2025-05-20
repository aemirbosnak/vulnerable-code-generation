//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent* server;
    char buffer[BUFFER_SIZE];

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert the IP address from string to binary format
    struct in_addr in;
    if (inet_pton(AF_INET, argv[1], &in) <= 0) {
        fprintf(stderr, "Invalid IP Address\n");
        exit(EXIT_FAILURE);
    }

    // Convert the port number from string to integer
    portno = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    // Set up the server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = in.s_addr;
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect failed");
    }

    // Send a message to the server
    send(sockfd, "Hello, World!", strlen("Hello, World!"), 0);

    // Receive a message from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        error_handling("recv failed");
    }
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}