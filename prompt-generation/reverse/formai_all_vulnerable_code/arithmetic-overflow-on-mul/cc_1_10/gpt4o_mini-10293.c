//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1048576 // 1MB
#define SERVER_IP "127.0.0.1"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
}

void measure_download_speed() {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer;
    struct timeval start, end;

    buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        error("Failed to allocate memory for buffer");
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        free(buffer);
        error("Error creating socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        free(buffer);
        close(sock);
        error("Invalid server IP");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        free(buffer);
        close(sock);
        error("Connection to server failed");
    }

    // Starting download speed test
    gettimeofday(&start, NULL);
    ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    gettimeofday(&end, NULL);
    
    if (bytes_received < 0) {
        free(buffer);
        close(sock);
        error("Failed to receive data");
    }

    double time_taken = get_time_diff(start, end);
    double speed = (bytes_received * 8) / (time_taken * 1000000); // speed in Mbps
    
    printf("Downloaded %zd bytes in %.2f seconds.\n", bytes_received, time_taken);
    printf("Download speed: %.2f Mbps\n", speed);

    free(buffer);
    close(sock);
}

int main() {
    printf("Welcome to the C Internet Speed Test Application!\n");
    printf("Testing download speed...\n\n");
    
    measure_download_speed();
    
    return 0;
}