//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "speedtest.server.com"
#define BUFFER_SIZE 1024

int main() {
    int sock, bytes_received;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, elapsed_time;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    // Start timer
    start_time = time(NULL);

    // Receive data from server
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error: Could not receive data from server\n");
        exit(1);
    }

    // Stop timer
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    // Calculate and display internet speed
    double speed = (double)bytes_received / (elapsed_time * 1024);
    printf("Internet speed: %.2lf Mbps\n", speed);

    // Close socket
    close(sock);

    return 0;
}