//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TEST_DURATION 5

void print_speed(float speed) {
    if (speed < 1024) {
        printf("Download Speed: %.2f Bytes/sec\n", speed);
    } else if (speed < 1048576) {
        printf("Download Speed: %.2f KB/sec\n", speed / 1024);
    } else {
        printf("Download Speed: %.2f MB/sec\n", speed / 1048576);
    }
}

void connect_to_server(const char* server_ip) {
    int sock;
    struct sockaddr_in server_addr;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server at %s\n", server_ip);
    char buffer[BUFFER_SIZE];
    int total_bytes = 0;
    struct timeval start, end;

    // Start the speed test
    gettimeofday(&start, NULL);
    for (int i = 0; i < TEST_DURATION; ++i) {
        ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            total_bytes += bytes_received;
        } else {
            break; // Connection closed by server
        }
    }
    gettimeofday(&end, NULL);

    // Calculate duration in seconds
    float duration_in_sec = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calculate speed in bytes/sec
    float speed = total_bytes / duration_in_sec;
    print_speed(speed);

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    connect_to_server(server_ip);

    return 0;
}