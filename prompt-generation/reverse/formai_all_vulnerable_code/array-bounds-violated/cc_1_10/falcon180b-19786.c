//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server;
    char hostname[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int port;
    int opt = 1;
    int addrlen;
    int ret;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));
    if (ret == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Resolve hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Unknown host: %s\n", hostname);
        exit(1);
    }

    // Fill in server address structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    // Send data
    sprintf(data, "PING %s:%d\r\n", hostname, port);
    send(sockfd, data, strlen(data), 0);

    // Receive data
    addrlen = sizeof(server);
    ret = recv(sockfd, data, MAX_DATA_LEN, 0);
    if (ret == -1) {
        perror("recv");
        exit(1);
    }
    data[ret] = '\0';

    printf("Received: %s", data);

    // Close socket
    close(sockfd);

    return 0;
}