//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>
#include <netdb.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 64
#define TIMEOUT 1

typedef struct {
    char hostname[256];
    char ip_address[INET_ADDRSTRLEN];
    int successful_pings;
    int failed_pings;
    double min_time;
    double max_time;
    double total_time;
} PingResults;

void ping(const char *ip_address, PingResults *results);
void calculate_statistics(PingResults *results);
void print_statistics(const PingResults *results);
double get_time_diff(struct timeval start, struct timeval end);
void dns_lookup(const char *hostname, char *ip_address);

int main(int argc, char *argv[]) {
    PingResults results;
    results.successful_pings = 0;
    results.failed_pings = 0;
    results.min_time = -1;
    results.max_time = 0;
    results.total_time = 0.0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    dns_lookup(argv[1], results.ip_address);
    strcpy(results.hostname, argv[1]);

    printf("Pinging %s [%s]...\n", results.hostname, results.ip_address);

    ping(results.ip_address, &results);
    
    calculate_statistics(&results);
    print_statistics(&results);

    return EXIT_SUCCESS;
}

void dns_lookup(const char *hostname, char *ip_address) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        perror("DNS lookup failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    inet_ntop(res->ai_family, &(ipv4->sin_addr), ip_address, INET_ADDRSTRLEN);
    freeaddrinfo(res);
}

void ping(const char *ip_address, PingResults *results) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    socklen_t len = sizeof(server_addr);
    ssize_t send_result, recv_result;

    for (int i = 0; i < MAX_PINGS; i++) {
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            perror("Socket creation failed");
            return;
        }

        // Configure server address
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(0); // Random port
        inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

        // Prepare data for ping
        snprintf(buffer, sizeof(buffer), "Ping %d", i + 1);

        // Start timer
        gettimeofday(&start, NULL);
        send_result = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, len);
        if (send_result < 0) {
            perror("Send failed");
            close(sockfd);
            results->failed_pings++;
            continue;
        }

        // Wait for response with timeout
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

        // Receive response
        recv_result = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_addr, &len);
        gettimeofday(&end, NULL);
        
        close(sockfd);

        // Calculate time taken
        double elapsed_time = get_time_diff(start, end);

        if (recv_result < 0) {
            perror("Ping request timed out");
            results->failed_pings++;
        } else {
            printf("Reply from %s: time=%.3f ms\n", ip_address, elapsed_time * 1000);
            results->successful_pings++;
            results->total_time += elapsed_time;

            if (results->min_time < 0 || elapsed_time < results->min_time) {
                results->min_time = elapsed_time;
            }
            if (elapsed_time > results->max_time) {
                results->max_time = elapsed_time;
            }
        }
    }
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

void calculate_statistics(PingResults *results) {
    if (results->successful_pings > 0) {
        results->total_time /= results->successful_pings;
    }
}

void print_statistics(const PingResults *results) {
    printf("\n--- %s ping statistics ---\n", results->hostname);
    printf("%d packets transmitted, %d received, %d%% packet loss\n",
            MAX_PINGS, results->successful_pings, 
            (results->failed_pings * 100) / MAX_PINGS);
    if (results->successful_pings > 0) {
        printf("round-trip min/avg/max = %.3f/%.3f/%.3f ms\n",
               results->min_time * 1000, 
               results->total_time * 1000, 
               results->max_time * 1000);
    }
}