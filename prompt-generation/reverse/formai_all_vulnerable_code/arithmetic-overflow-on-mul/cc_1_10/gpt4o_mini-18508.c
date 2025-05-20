//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_COUNT 4
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define PAYLOAD_SIZE 64

typedef struct {
    struct timeval sendTime;
    struct timeval recvTime;
    int replyStatus;
} PingResult;

void printPingStatistics(PingResult results[], int count) {
    long totalTime = 0;
    int sent = 0, received = 0;

    printf("\n--- Network Quality of Service Monitor ---\n");
    printf("Packets: Sent = %d, Received = %d\n", count, received);
    
    for (int i = 0; i < count; i++) {
        if (results[i].replyStatus == ICMP_ECHO_REPLY) {
            received++;
            long duration = (results[i].recvTime.tv_sec - results[i].sendTime.tv_sec) * 1000 +
                            (results[i].recvTime.tv_usec - results[i].sendTime.tv_usec) / 1000;
            totalTime += duration;
            printf("Reply from %s: time=%ld ms\n", "localhost", duration);
        } else {
            printf("Request timed out.\n");
        }
        sent++;
    }
 
    printf("\n--- Summary ---\n");
    printf("Min/Max/Average = [min] ms / [max] ms / %ld ms\n",
           (received > 0) ? totalTime / received : 0);
    printf("Packet Loss: %.2f%%\n", ((float)(sent - received) / sent) * 100);
}

int ping(char *hostname) {
    PingResult results[PACKET_COUNT];
    char command[128];
    sprintf(command, "ping -c %d %s", PACKET_COUNT, hostname);
    
    for (int i = 0; i < PACKET_COUNT; i++) {
        gettimeofday(&results[i].sendTime, NULL);
        int response = system(command);  // Execute ping command in system shell
        gettimeofday(&results[i].recvTime, NULL);
        
        results[i].replyStatus = (response == 0) ? ICMP_ECHO_REPLY : -1;  // Check if successful
        usleep(100000);  // Sleep for a short duration to avoid flooding the network
    }
    
    printPingStatistics(results, PACKET_COUNT);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    printf("Starting the QoS monitor for %s...\n", argv[1]);
    ping(argv[1]);

    printf("QoS monitoring completed!\n");
    return 0;
}