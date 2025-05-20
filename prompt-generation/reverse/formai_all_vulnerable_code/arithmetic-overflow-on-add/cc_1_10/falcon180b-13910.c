//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int bytes_received;
    time_t start_time, end_time;
    double total_time;
    double speed;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
    }

    // Start timer
    start_time = time(NULL);

    // Send data
    strcpy(send_buffer, "GET /speedtest.php HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    // Receive data
    bytes_received = 0;
    while ((bytes_received < BUFFER_SIZE) && (bytes_received >= 0)) {
        bytes_received += recv(sockfd, recv_buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
    }
    recv_buffer[bytes_received] = '\0';

    // Stop timer
    end_time = time(NULL);
    total_time = difftime(end_time, start_time);

    // Calculate speed
    speed = (double)bytes_received / total_time;
    printf("Internet speed: %.2f bytes/second\n", speed);

    // Close socket
    close(sockfd);

    return 0;
}