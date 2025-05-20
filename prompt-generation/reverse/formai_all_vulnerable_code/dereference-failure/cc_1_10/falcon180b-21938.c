//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define DEFAULT_PORT "80"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA], recv_data[BUFFER_SIZE];
    char hostname[MAX_HOSTNAME];
    int port;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/hostname\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to %s:%d\n", hostname, port);
        close(sockfd);
        return 1;
    }

    printf("Connected to %s:%d\n", hostname, port);

    strcpy(send_data, "GET / HTTP/1.1\r\nHost: ");
    strcat(send_data, hostname);
    strcat(send_data, "\r\nConnection: close\r\n\r\n");

    send(sockfd, send_data, strlen(send_data), 0);

    bzero(recv_data, BUFFER_SIZE);
    n = recv(sockfd, recv_data, BUFFER_SIZE, 0);

    if (n <= 0) {
        printf("Error receiving data\n");
        close(sockfd);
        return 1;
    }

    printf("Received data:\n%s", recv_data);

    close(sockfd);
    return 0;
}