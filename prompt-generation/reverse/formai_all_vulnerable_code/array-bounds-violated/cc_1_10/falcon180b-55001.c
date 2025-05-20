//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.net"
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Start timer
    start_time = time(0);

    // Receive data from server
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Stop timer
    end_time = time(0);

    // Calculate elapsed time
    elapsed_time = difftime(end_time, start_time);

    // Calculate speed
    speed = (double)bytes_received / elapsed_time;

    // Print speed
    printf("\nSpeed: %.2lf bps\n", speed);

    // Close socket
    close(sockfd);

    return 0;
}