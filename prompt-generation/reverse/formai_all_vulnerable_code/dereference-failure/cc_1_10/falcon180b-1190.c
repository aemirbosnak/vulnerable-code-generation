//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTS 100
#define MAX_DATA 1024

typedef struct {
    char hostname[MAX_HOSTS];
    int port;
    char data[MAX_DATA];
} host_t;

int send_ping(int sockfd, const char* hostname, int port, const char* data)
{
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    send(sockfd, data, strlen(data), 0);

    char buffer[MAX_DATA];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);

    printf("Received response from %s:%d\n%s\n", hostname, port, buffer);

    return bytes_received;
}

int main(int argc, char* argv[])
{
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <data>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);
    char* data = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to host\n");
        return 1;
    }

    send_ping(sockfd, hostname, port, data);

    close(sockfd);

    return 0;
}