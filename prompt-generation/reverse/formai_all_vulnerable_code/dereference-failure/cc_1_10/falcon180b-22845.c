//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send message to server
    strcpy(buffer, "Hello, server!");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        printf("Error sending message\n");
        exit(1);
    }

    // Receive message from server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error receiving message\n");
        exit(1);
    }
    printf("Message from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}