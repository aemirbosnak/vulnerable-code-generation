//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define NUM_PINGS 5
#define PING_INTERVAL 1 // in seconds
#define HOST "8.8.8.8" // Google's DNS for testing
#define BANDWIDTH_INTERVAL 5 // in seconds

volatile int pingResponsesReceived = 0;
pthread_mutex_t lock;

void *ping(void *arg) {
    char command[100];
    struct timeval start, end;
    double totalTime;

    while (1) {
        gettimeofday(&start, NULL);
        snprintf(command, sizeof(command), "ping -c 1 -W 1 %s > /dev/null 2>&1", HOST);
        int result = system(command);
        gettimeofday(&end, NULL);

        if (result == 0) {
            pthread_mutex_lock(&lock);
            pingResponsesReceived++;
            pthread_mutex_unlock(&lock);
            totalTime = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
            printf("Ping successful! Time: %.2f ms\n", totalTime);
        } else {
            printf("Ping failed to %s!\n", HOST);
        }

        sleep(PING_INTERVAL);
    }

    return NULL;
}

void *check_bandwidth(void *arg) {
    char command[100];

    while (1) {
        int bandwidthResult = system("speedtest-cli --simple > /tmp/bandwidth.txt 2>/dev/null");
        if (bandwidthResult == 0) {
            FILE *file = fopen("/tmp/bandwidth.txt", "r");
            if (file) {
                char line[256];
                printf("\n--- Bandwidth Test Results ---\n");
                while (fgets(line, sizeof(line), file)) {
                    printf("%s", line);
                }
                fclose(file);
            }
        } else {
            printf("Failed to retrieve bandwidth info!\n");
        }

        sleep(BANDWIDTH_INTERVAL);
    }

    return NULL;
}

int main() {
    pthread_t pingThread, bandwidthThread;
    pthread_mutex_init(&lock, NULL);

    // Create ping and bandwidth threads
    pthread_create(&pingThread, NULL, ping, NULL);
    pthread_create(&bandwidthThread, NULL, check_bandwidth, NULL);

    // Join threads (this will keep the main thread active)
    pthread_join(pingThread, NULL);
    pthread_join(bandwidthThread, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}