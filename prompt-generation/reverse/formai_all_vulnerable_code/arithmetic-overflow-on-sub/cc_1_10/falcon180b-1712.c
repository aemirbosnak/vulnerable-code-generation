//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.example.com"
#define TIMEOUT 10

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int total_bytes_sent = 0;
    int total_bytes_received = 0;
    double start_time, end_time;
    double elapsed_time;
    int bytes_per_second;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    start_time = time(NULL);

    while (total_bytes_sent < BUFFER_SIZE) {
        int bytes_sent = send(sockfd, send_buffer, BUFFER_SIZE - total_bytes_sent, 0);
        if (bytes_sent == -1) {
            printf("Error sending data\n");
            close(sockfd);
            return 1;
        }
        total_bytes_sent += bytes_sent;
    }

    while (total_bytes_received < BUFFER_SIZE) {
        int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE - total_bytes_received, 0);
        if (bytes_received == -1) {
            printf("Error receiving data\n");
            close(sockfd);
            return 1;
        }
        total_bytes_received += bytes_received;
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    bytes_per_second = (double)total_bytes_sent / elapsed_time;

    printf("Internet speed: %.2f bytes/second\n", bytes_per_second);

    close(sockfd);
    return 0;
}