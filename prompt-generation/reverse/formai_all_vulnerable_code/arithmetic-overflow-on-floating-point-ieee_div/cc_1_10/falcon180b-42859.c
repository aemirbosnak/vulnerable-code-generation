//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define DATA_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char data[DATA_SIZE];
    int bytes_sent, bytes_recv;
    double start_time, end_time;
    double total_time;
    double bandwidth;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "www.google.com", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    start_time = time(NULL);

    bytes_sent = send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"), 0);

    if (bytes_sent == -1) {
        printf("Error: Send failed\n");
        exit(1);
    }

    bytes_recv = recv(sockfd, data, DATA_SIZE, 0);

    if (bytes_recv == -1) {
        printf("Error: Receive failed\n");
        exit(1);
    }

    end_time = time(NULL);

    total_time = end_time - start_time;

    bandwidth = (double)bytes_recv / total_time;

    printf("Bandwidth: %.2f bytes/sec\n", bandwidth);

    close(sockfd);

    return 0;
}