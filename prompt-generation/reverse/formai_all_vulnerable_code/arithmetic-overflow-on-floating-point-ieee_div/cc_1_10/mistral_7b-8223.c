//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define SERVER_IP "192.168.1.1" // Change this to your server IP address
#define SERVER_PORT 8080 // Change this to your server port number
#define BUFFER_SIZE 1024
#define FILE_SIZE 1048576 // Change this to your desired file size in bytes

int main() {
    int sockfd, new_sockfd, n;
    struct sockaddr_in server, client;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, transfer_time;
    double data_sent, data_received;
    struct timeval tv;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connection error");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&tv, NULL);
    start_time = tv.tv_sec + tv.tv_usec / 1000000.0;

    if (send(sockfd, "GET /test.bin", strlen("GET /test.bin") + 1, 0) < 0) {
        perror("sending data error");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, FILE_SIZE, 0) < 0) {
        perror("receiving data error");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&tv, NULL);
    end_time = tv.tv_sec + tv.tv_usec / 1000000.0;

    transfer_time = end_time - start_time;
    data_sent = strlen("GET /test.bin") + 1;
    data_received = FILE_SIZE;

    printf("Transfer complete! Transfer time: %.2f seconds\n", transfer_time);
    printf("Data sent: %.2f MB\n", data_sent / (1024 * 1024));
    printf("Data received: %.2f MB\n", data_received / (1024 * 1024));
    printf("Average speed: %.2f MB/s\n", (data_received / transfer_time) / (1024 * 1024));

    close(sockfd);
    return 0;
}