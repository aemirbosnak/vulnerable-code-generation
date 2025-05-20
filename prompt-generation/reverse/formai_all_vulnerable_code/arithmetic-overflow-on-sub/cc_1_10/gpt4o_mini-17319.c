//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "8.8.8.8"  // Google's public DNS server for pinging
#define BUFFER_SIZE 1024
#define TIMEOUT 5
#define NUM_TESTS 5

void print_instructions() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This program will measure your internet speed by calculating the latency and the download speed.\n");
    printf("Press Ctrl + C to exit.\n");
}

double get_ping_time(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;
    struct timeval start, end;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Common HTTP port
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    gettimeofday(&start, NULL);
    sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
    gettimeofday(&end, NULL);

    close(sock);
    double ping_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    
    return ping_time;
}

double download_test(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer;
    long total_bytes = 0;
    struct timeval start, end;
    double duration = 0.0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Common HTTP port
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -1;
    }

    buffer = (char *)malloc(BUFFER_SIZE);
    gettimeofday(&start, NULL);
    
    while (1) {
        ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) break;
        total_bytes += bytes_received;
    }

    gettimeofday(&end, NULL);
    close(sock);
    free(buffer);

    duration = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
    double download_speed = (total_bytes * 8) / (duration / 1000.0) / (1024 * 1024); // Mbps

    return download_speed;
}

int main() {
    print_instructions();
    double total_ping_time = 0.0;
    double total_download_speed = 0.0;

    for (int i = 0; i < NUM_TESTS; i++) {
        double ping_time = get_ping_time(SERVER_IP);
        if (ping_time < 0) {
            printf("Ping test failed.\n");
            continue;
        }
        printf("Ping Test %d: %0.2f ms\n", i + 1, ping_time);
        total_ping_time += ping_time;

        double download_speed = download_test(SERVER_IP);
        if (download_speed < 0) {
            printf("Download test failed.\n");
            continue;
        }
        printf("Download Speed Test %d: %0.2f Mbps\n", i + 1, download_speed);
        total_download_speed += download_speed;

        sleep(1); // Pause before next test
    }

    printf("\n--- Summary ---\n");
    printf("Average Ping: %0.2f ms\n", total_ping_time / NUM_TESTS);
    printf("Average Download Speed: %0.2f Mbps\n", total_download_speed / NUM_TESTS);
    
    return 0;
}