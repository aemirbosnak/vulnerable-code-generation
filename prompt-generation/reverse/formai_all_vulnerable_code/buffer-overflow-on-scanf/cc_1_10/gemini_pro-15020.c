//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define BUFF_SIZE 1024
#define NUM_THREADS 4

// Thread function to measure download speed
void* download_speed(void *arg) {
    int sockfd = *(int *)arg;
    char buff[BUFF_SIZE];
    int bytes_received = 0;

    // Start timer
    clock_t start = clock();
    while (bytes_received < 10 * 1024 * 1024) {
        int bytes_read = recv(sockfd, buff, BUFF_SIZE, 0);
        if (bytes_read == -1) {
            perror("recv");
            pthread_exit(NULL);
        }
        bytes_received += bytes_read;
    }
    // Stop timer
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate download speed
    double download_speed_mbps = (bytes_received * 8) / (1024 * 1024 * elapsed_time);

    // Print result
    printf("Download speed: %.2f Mbps\n", download_speed_mbps);

    pthread_exit(NULL);
}

// Thread function to measure upload speed
void* upload_speed(void *arg) {
    int sockfd = *(int *)arg;
    char buff[BUFF_SIZE];
    int bytes_sent = 0;

    // Generate random data to send
    memset(buff, 'a', BUFF_SIZE);

    // Start timer
    clock_t start = clock();
    while (bytes_sent < 10 * 1024 * 1024) {
        int bytes_written = send(sockfd, buff, BUFF_SIZE, 0);
        if (bytes_written == -1) {
            perror("send");
            pthread_exit(NULL);
        }
        bytes_sent += bytes_written;
    }
    // Stop timer
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate upload speed
    double upload_speed_mbps = (bytes_sent * 8) / (1024 * 1024 * elapsed_time);

    // Print result
    printf("Upload speed: %.2f Mbps\n", upload_speed_mbps);

    pthread_exit(NULL);
}

int main() {
    // Get server address
    char server_addr[100];
    printf("Enter server address: ");
    scanf("%s", server_addr);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    if (inet_pton(AF_INET, server_addr, &server_address.sin_addr) == -1) {
        perror("inet_pton");
        close(sockfd);
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Create threads to measure download and upload speeds
    pthread_t download_thread, upload_thread;
    if (pthread_create(&download_thread, NULL, download_speed, &sockfd) != 0) {
        perror("pthread_create download_thread");
        close(sockfd);
        return EXIT_FAILURE;
    }
    if (pthread_create(&upload_thread, NULL, upload_speed, &sockfd) != 0) {
        perror("pthread_create upload_thread");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Wait for threads to finish
    if (pthread_join(download_thread, NULL) != 0) {
        perror("pthread_join download_thread");
        close(sockfd);
        return EXIT_FAILURE;
    }
    if (pthread_join(upload_thread, NULL) != 0) {
        perror("pthread_join upload_thread");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}