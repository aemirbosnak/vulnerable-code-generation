//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define INTERVAL 1 // seconds
#define MAX_TRACES 5

typedef struct {
    struct sockaddr_in addr;
    int latency;
    int packet_loss;
} QoSResult;

void *ping_host(void *arg);
void calculate_qos(QoSResult *results, int count);
int ping(const char *host);

int main() {
    pthread_t threads[MAX_TRACES];
    QoSResult results[MAX_TRACES];
    char buffer[BUFFER_SIZE];
    int i;

    const char *hosts[MAX_TRACES] = {
        "8.8.8.8",  // Google DNS
        "1.1.1.1",  // Cloudflare DNS
        "192.30.253.113", // GitHub
        "104.244.42.1", // Twitter
        "151.101.1.69"  // Fastly CDN
    };

    while (1) {
        for (i = 0; i < MAX_TRACES; i++) {
            results[i].addr.sin_family = AF_INET;
            inet_pton(AF_INET, hosts[i], &results[i].addr.sin_addr);
            pthread_create(&threads[i], NULL, ping_host, (void *)&results[i]);
        }

        for (i = 0; i < MAX_TRACES; i++) {
            pthread_join(threads[i], NULL);
        }

        calculate_qos(results, MAX_TRACES);

        printf("Metrics calculated. Waiting for next sampling...\n");
        sleep(INTERVAL);
    }

    return 0;
}

void *ping_host(void *arg) {
    QoSResult *result = (QoSResult *)arg;
    result->latency = ping(inet_ntoa(result->addr.sin_addr));
    result->packet_loss = rand() % 10; // Simulated Packet Loss between 0-9%
    return NULL;
}

int ping(const char *host) {
    struct timespec start, end;
    int status;

    clock_gettime(CLOCK_MONOTONIC, &start);
    // Simulating ping return; In a real scenario, a ping command would be executed here
    usleep((rand() % 100) * 1000 + 100000);  // Simulating random latency between 100ms-200ms
    clock_gettime(CLOCK_MONOTONIC, &end);

    long latency = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("Ping to %s: %ld ms\n", host, latency);
    return (int)latency;
}

void calculate_qos(QoSResult *results, int count) {
    int total_latency = 0;
    int total_packet_loss = 0;

    for (int i = 0; i < count; i++) {
        total_latency += results[i].latency;
        total_packet_loss += results[i].packet_loss;
    }

    double avg_latency = total_latency / (double)count;
    double avg_packet_loss = total_packet_loss / (double)count;

    printf("Average Latency: %.2f ms\n", avg_latency);
    printf("Average Packet Loss: %.2f%%\n", avg_packet_loss);
}