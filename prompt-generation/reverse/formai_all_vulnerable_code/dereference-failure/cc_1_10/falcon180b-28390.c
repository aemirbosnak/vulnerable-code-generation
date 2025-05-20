//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

#define MAX_HOST_LEN 256
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char host[MAX_HOST_LEN];
    strcpy(host, argv[1]);
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char send_buffer[BUFFER_SIZE];
    strcpy(send_buffer, "PING");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    char recv_buffer[BUFFER_SIZE];
    memset(recv_buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        close(sockfd);
        return 1;
    }

    recv_buffer[bytes_received] = '\0';
    printf("Response: %s\n", recv_buffer);

    close(sockfd);
    return 0;
}