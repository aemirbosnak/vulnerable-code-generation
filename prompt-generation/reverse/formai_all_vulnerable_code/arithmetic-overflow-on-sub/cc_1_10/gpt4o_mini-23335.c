//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>

#define PING_COUNT 4
#define PING_INTERVAL 1 // seconds

volatile sig_atomic_t stop;

void handle_sigint(int sig) {
    stop = 1;
}

void print_statistics(int sent, int received, double total_time) {
    printf("\n--- Network Quality of Service Monitor ---\n");
    printf("Packets: Sent = %d, Received = %d, Lost = %d (%.1f%% loss)\n", 
           sent, received, sent - received, 
           (sent - received) / (double)sent * 100);
    printf("Round trip time (RTT): Total = %.2f seconds\n", total_time);
}

void ping(const char *ip_address) {
    struct timeval start, end;
    int sent = 0, received = 0;

    printf("Pinging %s...\n", ip_address);
    while (!stop && sent < PING_COUNT) {
        gettimeofday(&start, NULL);
        char command[100];
        snprintf(command, sizeof(command), "ping -c 1 -W 1 %s > /dev/null", ip_address);
        
        // Execute the ping command
        int result = system(command);
        gettimeofday(&end, NULL);

        sent++;
        if (result == 0) {
            received++;
            double time_taken = (end.tv_sec - start.tv_sec) + 
                                (end.tv_usec - start.tv_usec) / 1000000.0;
            printf("Reply from %s: time=%.2f ms\n", ip_address, time_taken * 1000);
        } else {
            printf("Request timed out for %s\n", ip_address);
        }
        
        // Sleep for the interval
        sleep(PING_INTERVAL);
    }

    // Printing the statistics
    print_statistics(sent, received, 0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];

    // Set up signal handling for graceful exit
    signal(SIGINT, handle_sigint);

    // Start monitoring the QoS
    ping(ip_address);

    return 0;
}