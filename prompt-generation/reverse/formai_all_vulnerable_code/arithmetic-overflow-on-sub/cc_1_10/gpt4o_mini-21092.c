//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PACKET_SIZE 64
#define TIMEOUT 1        // 1 second timeout
#define PING_COUNT 5     // Number of pings
#define MAX_BUFFER 1024

typedef struct {
    char ip_address[INET6_ADDRSTRLEN];
    int received_response;
    double round_trip_time;
} PingResult;

void log_results(PingResult results[], int count) {
    FILE *log_file = fopen("ping_results.log", "a");
    if (!log_file) {
        perror("Could not open log file");
        return;
    }

    fprintf(log_file, "Ping Results:\n");
    for (int i = 0; i < count; i++) {
        fprintf(log_file, "IP: %s | Response: %s | RTT: %.2f ms\n",
            results[i].ip_address,
            results[i].received_response ? "Yes" : "No",
            results[i].round_trip_time);
    }
    fclose(log_file);
    printf("Ping results logged successfully.\n");
}

double calculate_rtt(struct timespec start, struct timespec end) {
    return ((end.tv_sec - start.tv_sec) * 1000) +
           ((end.tv_nsec - start.tv_nsec) / 1000000.0);
}

int ping(const char *ip_address, PingResult *result) {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[PACKET_SIZE];
    struct timespec start, end;
    int bytes_sent;
    
    // Create a raw socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0; // Any port
    inet_pton(AF_INET, ip_address, &addr.sin_addr);
    
    // Prepare the packet
    memset(buffer, 0, sizeof(buffer));
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    // Send the packet
    bytes_sent = sendto(sockfd, buffer, sizeof(buffer), 0, 
                        (struct sockaddr*)&addr, sizeof(addr));
    
    if (bytes_sent < 0) {
        perror("Send failed");
        close(sockfd);
        return -1;
    }
    
    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    socklen_t addrlen = sizeof(addr);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addrlen) < 0) {
        result->received_response = 0; // No response
        clock_gettime(CLOCK_MONOTONIC, &end);
        result->round_trip_time = 0;
    } else {
        result->received_response = 1; // Response received
        clock_gettime(CLOCK_MONOTONIC, &end);
        result->round_trip_time = calculate_rtt(start, end);
    }

    inet_ntop(AF_INET, &addr.sin_addr, result->ip_address, sizeof(result->ip_address));
    close(sockfd);
    return 0;
}

void monitor_qos(const char *target_ip) {
    PingResult results[PING_COUNT];
    int success_count = 0;
    
    for (int i = 0; i < PING_COUNT; i++) {
        printf("Pinging %s...\n", target_ip);
        if (ping(target_ip, &results[i]) == 0) {
            if (results[i].received_response) {
                success_count++;
            }
            printf("Reply from %s: RTT = %.2f ms\n", results[i].ip_address, results[i].round_trip_time);
        } else {
            printf("Ping to %s failed.\n", target_ip);
        }
        sleep(1); // Sleep before the next ping
    }

    // Log the results
    log_results(results, PING_COUNT);
    
    // Summary
    printf("Ping Summary: %d out of %d packets received.\n", success_count, PING_COUNT);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *target_ip = argv[1];
    monitor_qos(target_ip);

    return EXIT_SUCCESS;
}