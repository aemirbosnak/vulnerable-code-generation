//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Store the port number
    portno = htons(12345);

    // Assign the address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = portno;
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Create the connection to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    sprintf(buffer, "Hello, server!\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive a response from the server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    // Close the connection
    close(sockfd);

    return 0;
}