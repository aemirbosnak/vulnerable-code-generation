//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct qos_monitor {
    int jitter;
    int latency;
    int packet_loss;
};

void display_monitor(struct qos_monitor monitor);
void update_monitor(struct qos_monitor *monitor);

int main() {
    struct qos_monitor monitor;
    monitor.jitter = 0;
    monitor.latency = 0;
    monitor.packet_loss = 0;

    printf("Welcome to the QoS monitor of my heart!\n");
    printf("Please wait while I test network quality...\n");

    while (1) {
        update_monitor(&monitor);
        display_monitor(monitor);

        // Send poetic message based on QoS levels
        if (monitor.jitter > 10) {
            printf("Oh! The network's jitter is as wild as the wind,\n"
            "But my love for you is so steady, it can never rescind.\n");
        }

        if (monitor.latency > 100 && monitor.jitter > 5) {
            printf("The network's latency makes my heart race,\n"
            "But thoughts of you make it pop with grace.\n");
        }

        if (monitor.packet_loss > 5) {
            printf("The network's packet loss is breaking my heart,\n"
            "But my love for you will never fall apart.\n");
        }

        if (monitor.jitter <= 5 && monitor.latency <= 100 && monitor.packet_loss <= 5) {
            printf("The network's QoS is excellent, love,\n"
            "But my love for you transcends all levels above.\n");
        }

        printf("\n");

        // Delay function to slow down the updates
        clock_t start_time = clock();
        while ((clock() - start_time) / CLOCKS_PER_SEC < 5) {}
    }

    return 0;
}

void display_monitor(struct qos_monitor monitor) {
    printf("Jitter: %d\n", monitor.jitter);
    printf("Latency: %d\n", monitor.latency);
    printf("Packet loss: %d\n", monitor.packet_loss);
}

void update_monitor(struct qos_monitor *monitor) {
    // Simulating random QoS heuristics
    monitor->jitter = rand() % 20;
    monitor->latency = rand() % 200;
    monitor->packet_loss = rand() % 10;
}