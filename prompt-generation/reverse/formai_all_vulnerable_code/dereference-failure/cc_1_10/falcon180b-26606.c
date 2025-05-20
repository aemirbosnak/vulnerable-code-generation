//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int port;
    int opt = 1;
    int timeout = 5;
    struct timeval tv;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send data
    strcpy(data, "PING");
    ret = send(sockfd, data, strlen(data), 0);
    if (ret == -1) {
        printf("Error sending data\n");
        return 1;
    }

    // Set timeout
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(struct timeval));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(struct timeval));

    // Receive data
    memset(data, 0, MAX_DATA);
    ret = recv(sockfd, data, MAX_DATA, 0);
    if (ret == -1) {
        printf("Error receiving data\n");
        return 1;
    } else if (ret == 0) {
        printf("Server did not respond\n");
        return 1;
    }

    printf("Data received: %s\n", data);

    close(sockfd);
    return 0;
}