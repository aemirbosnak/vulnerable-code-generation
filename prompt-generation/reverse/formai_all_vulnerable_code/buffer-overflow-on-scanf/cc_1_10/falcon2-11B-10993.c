//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

int main() {
    char hostname[1024];
    int sockfd, numBytes, bytesRead, bytesSent, i, j, k;
    struct sockaddr_in serverAddr;
    struct hostent *server;
    struct timeval timeout;
    char buffer[1024];

    printf("Enter the hostname to ping: ");
    scanf("%s", hostname);

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // set timeout
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // get server address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: Hostname not found\n");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(80);
    serverAddr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // send ping request
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    bytesSent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytesSent < 0) {
        perror("Error sending ping request");
        exit(1);
    }

    // receive ping response
    memset(buffer, 0, sizeof(buffer));
    bytesRead = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytesRead < 0) {
        perror("Error receiving ping response");
        exit(1);
    }

    // print ping response
    printf("Ping response:\n");
    printf("%s\n", buffer);

    return 0;
}