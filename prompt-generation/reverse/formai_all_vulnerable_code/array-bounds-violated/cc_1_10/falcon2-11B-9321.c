//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        return 1;
    }

    // Send a request to the server
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending request");
        return 1;
    }

    // Receive the server response
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error receiving response");
        return 1;
    }
    buffer[n] = '\0';

    // Print the server response
    printf("Server response:\n%s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}