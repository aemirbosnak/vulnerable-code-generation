//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>

#define SERVER_IP "8.8.8.8" // Google's public DNS
#define PACKET_SIZE 1024
#define NUM_PACKETS 10

void display_welcome_message() {
    printf("🎉 Welcome to the Internet Speed Test Application! 🎉\n");
    printf("Measuring how speedy your connection can be! 🚀\n");
    printf("Please wait while we check your internet speed...\n\n");
}

double calculate_average_time(double times[], int n) {
    double total_time = 0.0;
    for (int i = 0; i < n; i++) {
        total_time += times[i];
    }
    return total_time / n;
}

void run_speed_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[PACKET_SIZE];
    double round_trip_times[NUM_PACKETS];
    struct timespec start, end;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Use standard HTTP port
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    for (int i = 0; i < NUM_PACKETS; i++) {
        // Send a packet
        clock_gettime(CLOCK_MONOTONIC, &start);
        sendto(sockfd, buffer, PACKET_SIZE, 0, (const struct sockaddr*)&server_addr, sizeof(server_addr));

        // Wait for a response
        recvfrom(sockfd, buffer, PACKET_SIZE, 0, NULL, NULL);
        clock_gettime(CLOCK_MONOTONIC, &end);

        // Calculate round trip time
        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        round_trip_times[i] = elapsed_time;

        printf("🏓 Packet %d sent and received in %.6f seconds! 🎊\n", i + 1, elapsed_time);
        usleep(100000); // Sleep for 0.1 second before next packet
    }

    close(sockfd);

    // Calculate average round trip time
    double average_time = calculate_average_time(round_trip_times, NUM_PACKETS);
    
    printf("\n🎉 Speed Test Complete! 🎉\n");
    printf("🚀 Average Round Trip Time: %.6f seconds!\n", average_time);
    printf("✨ Thank you for using the Internet Speed Test Application! ✨\n");
}

int main() {
    display_welcome_message();
    run_speed_test();

    return 0;
}