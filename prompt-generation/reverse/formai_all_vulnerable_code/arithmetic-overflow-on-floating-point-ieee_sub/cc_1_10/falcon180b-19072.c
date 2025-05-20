//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_ADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time, elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    start_time = difftime(time(NULL), 0);
    send(sockfd, "GET /speedtest.txt HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n", strlen("GET /speedtest.txt HTTP/1.1\r\nHost: 127.0.0.1\r\n\r\n"), 0);

    bytes_received = 0;
    while ((bytes_received < BUFFER_SIZE) && (bytes_received >= 0)) {
        bytes_received += recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }

    close(sockfd);

    end_time = difftime(time(NULL), 0);
    elapsed_time = end_time - start_time;

    printf("Elapsed time: %.2lf seconds\n", elapsed_time);
    printf("Bytes received: %d\n", bytes_received);

    return 0;
}