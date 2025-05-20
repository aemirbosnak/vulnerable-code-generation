//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

struct QoS_DATA {
    int priority;
    double bandwidth;
    double delay;
    double jitter;
};

struct QoS_DATA get_qos_data() {
    struct QoS_DATA data;

    printf("Enter QoS data:");
    scanf("%d %lf %lf %lf", &data.priority, &data.bandwidth, &data.delay, &data.jitter);

    return data;
}

void monitor_qos(struct QoS_DATA data) {
    int status = 0;

    // Check if the QoS data is valid
    if (data.priority < 0 || data.priority > 9) {
        status = 1;
    }
    if (data.bandwidth < 0 || data.bandwidth > 100) {
        status = 1;
    }
    if (data.delay < 0 || data.delay > 100) {
        status = 1;
    }
    if (data.jitter < 0 || data.jitter > 100) {
        status = 1;
    }

    // If the QoS data is invalid, display an error message
    if (status) {
        printf("Error: Invalid QoS data.\n");
    } else {
        // Display the QoS data
        printf("QoS data:**\n");
        printf("Priority: %d\n", data.priority);
        printf("Bandwidth: %.2lf MB/s\n", data.bandwidth);
        printf("Delay: %.2lf ms\n", data.delay);
        printf("Jitter: %.2lf%\n", data.jitter);
    }
}

int main() {
    struct QoS_DATA data = get_qos_data();
    monitor_qos(data);

    return 0;
}