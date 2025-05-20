//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *request = "GET / HTTP/1.0\r\n\r\n";
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;
    double total_time;
    double speed;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket failed");

    // Connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error_handling("connect failed");

    // Send request
    send(sock, request, strlen(request), 0);

    // Receive response
    bytes_received = 0;
    start_time = clock();
    while (bytes_received < BUFFER_SIZE) {
        int result = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (result <= 0) {
            error_handling("recv failed");
        }
        bytes_received += result;
    }
    end_time = clock();

    // Calculate speed
    total_time = (end_time - start_time) / (double)CLOCKS_PER_SEC;
    speed = bytes_received / total_time;

    // Print speed
    printf("Speed: %.2lf KB/s\n", speed);

    // Close socket
    close(sock);

    return 0;
}