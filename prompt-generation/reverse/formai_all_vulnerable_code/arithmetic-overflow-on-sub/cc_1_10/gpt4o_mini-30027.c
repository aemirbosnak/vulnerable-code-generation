//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h>

#define SERVER_IP "1.1.1.1" // Dummy server for testing; use a real server in practice
#define SERVER_PORT 80
#define BUFFER_SIZE 1048576 // 1 MB buffer

void *download_speed_test(void *arg);
void *upload_speed_test(void *arg);

typedef struct {
    double download_speed;
    double upload_speed;
} SpeedResults;

void display_results(SpeedResults results) {
    printf("\n----------- Internet Speed Test Results -----------\n");
    printf("Download Speed: %.2f Mbps\n", results.download_speed);
    printf("Upload Speed: %.2f Mbps\n", results.upload_speed);
    printf("--------------------------------------------------\n");
}

double calculate_speed(size_t bytes, double duration) {
    return (bytes * 8) / (duration * 1024 * 1024); // Convert to Mbps
}

int main() {
    printf("🌐 Welcome to the Exciting Internet Speed Test! 🌐\n");
    printf("🏁 Please wait while we measure your internet speed...\n");

    SpeedResults results;
    pthread_t download_thread, upload_thread;

    if (pthread_create(&download_thread, NULL, download_speed_test, &results) != 0) {
        perror("Failed to create download thread");
        return EXIT_FAILURE;
    }

    if (pthread_create(&upload_thread, NULL, upload_speed_test, &results) != 0) {
        perror("Failed to create upload thread");
        return EXIT_FAILURE;
    }

    pthread_join(download_thread, NULL);
    pthread_join(upload_thread, NULL);

    display_results(results);
    printf("🎉 Speed test completed! Thank you for participating! 🎉\n");

    return 0;
}

void *download_speed_test(void *arg) {
    SpeedResults *results = (SpeedResults *)arg;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int sockfd, bytes_received;
    clock_t start_time, end_time;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        return NULL;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(sockfd);
        return NULL;
    }

    start_time = clock();
    size_t total_bytes = 0;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        total_bytes += bytes_received;
    }

    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    results->download_speed = calculate_speed(total_bytes, elapsed_time);

    close(sockfd);
    return NULL;
}

void *upload_speed_test(void *arg) {
    SpeedResults *results = (SpeedResults *)arg;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int sockfd, bytes_sent;
    clock_t start_time, end_time;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        return NULL;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(sockfd);
        return NULL;
    }

    memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with dummy data
    start_time = clock();
    size_t total_bytes = 0;

    while ((bytes_sent = send(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        total_bytes += bytes_sent;
    }

    end_time = clock();
    elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    results->upload_speed = calculate_speed(total_bytes, elapsed_time);

    close(sockfd);
    return NULL;
}