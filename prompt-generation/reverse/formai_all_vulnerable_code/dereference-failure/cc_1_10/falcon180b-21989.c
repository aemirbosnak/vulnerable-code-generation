//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 512

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int len;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error_handling("Error opening socket");

    portno = 8080;

    // Prepare the server address structure
    server = gethostbyname("localhost");
    if (server == NULL)
        error_handling("Error: no such host");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("Error connecting");

    // Send data to the server
    send(sockfd, "Hello, World!", strlen("Hello, World! "), 0);

    // Receive data from the server
    len = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (len < 0)
        error_handling("Error receiving");
    else {
        buffer[len] = '\0';
        printf("Received message: %s\n", buffer);
    }

    // Close the socket
    close(sockfd);

    return 0;
}