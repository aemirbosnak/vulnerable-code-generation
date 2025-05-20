//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define SERVER_PORT 5000
#define BUFFER_SIZE 1024
#define TEST_DURATION 5 // seconds
#define NUM_THREADS 4

typedef struct {
    const char *server_ip;
    double *result_speed;
} SpeedTestArgs;

void *test_speed(void *args) {
    SpeedTestArgs *test_args = (SpeedTestArgs *)args;
    const char *server_ip = test_args->server_ip;
    double *speed_result = test_args->result_speed;

    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    size_t bytes_sent, bytes_received;

    // Create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Start speed test
    time_t start_time = time(NULL);
    time_t end_time;

    size_t total_bytes = 0;

    while (1) {
        bytes_sent = sendto(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (bytes_sent < 0) {
            perror("Send failed");
            close(sock);
            pthread_exit(NULL);
        }

        bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (bytes_received < 0) {
            perror("Receive failed");
            close(sock);
            pthread_exit(NULL);
        }

        total_bytes += bytes_sent;  // Assuming echo server sends back the same size

        end_time = time(NULL);
        if (difftime(end_time, start_time) >= TEST_DURATION) {
            break;
        }
    }

    close(sock);
    *speed_result = (total_bytes * 8.0) / (TEST_DURATION * 1e6); // Mbps
    pthread_exit(NULL);
}

int main() {
    const char *server_ip = "127.0.0.1"; // Echo server address (must be running)
    double speeds[NUM_THREADS];
    pthread_t threads[NUM_THREADS];
    SpeedTestArgs args[NUM_THREADS];

    printf(">>> Welcome to the Mind-Bending Internet Speed Test! <<<\n\n");
    printf("Testing speed to %s using %d threads...\n\n", server_ip, NUM_THREADS);

    // Create threads to test internet speed
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].server_ip = server_ip;
        args[i].result_speed = &speeds[i];
        pthread_create(&threads[i], NULL, test_speed, (void *)&args[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate and display average speed
    double total_speed = 0.0;
    for (int i = 0; i < NUM_THREADS; i++) {
        total_speed += speeds[i];
    }
    double average_speed = total_speed / NUM_THREADS;

    printf("\n>>> Test Complete! <<<\n");
    printf("Total Average Speed: %.2f Mbps\n", average_speed);
    
    // Simple feedback based on speed
    if (average_speed < 1.0) {
        printf("Oh dear! Your internet speed is below 1 Mbps. You might consider speaking to your ISP!\n");
    } else if (average_speed < 5.0) {
        printf("Your speed is decent, but there's room for improvement. Try upgrading your plan!\n");
    } else {
        printf("Fantastic! You're surfing at an excellent speed of %.2f Mbps!\n", average_speed);
    }

    printf("\n>>> Thank you for using the Mind-Bending Internet Speed Test! <<<\n");
    return 0;
}