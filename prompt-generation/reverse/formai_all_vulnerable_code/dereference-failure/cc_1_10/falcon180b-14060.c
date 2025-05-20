//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, retval, bytes_sent, bytes_received;
    struct hostent *hostinfo;
    struct sockaddr_in serveraddr;
    char *server_ip;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./ping <server_ip> <port>\n");
        exit(1);
    }

    server_ip = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set up server address structure
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &serveraddr.sin_addr);

    // Connect to server
    retval = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (retval == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send data
    strcpy(buffer, "PING");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent == -1) {
        printf("Error sending data: %s\n", strerror(errno));
        exit(1);
    }

    // Receive data
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving data: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received response: %s\n", buffer);

    close(sockfd);
    return 0;
}