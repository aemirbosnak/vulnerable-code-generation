//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char *host_name;

    if (argc < 3) {
        printf("Usage: %s <hostname/IP> <port number>\n", argv[0]);
        exit(1);
    }

    host_name = argv[1];
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    printf("Socket created\n");

    // Connect to remote server
    server = gethostbyname(host_name);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connected to remote host\n");

    // Send data to remote server
    bzero(buffer, BUFFER_SIZE);
    strcpy(buffer, "PING");
    n = strlen(buffer);

    if (send(sockfd, buffer, n, 0) < 0) {
        printf("Error: send failed\n");
        exit(1);
    }

    printf("Ping sent\n");

    // Receive response from remote server
    bzero(buffer, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        printf("Error: recv failed\n");
        exit(1);
    }

    printf("Response received: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}