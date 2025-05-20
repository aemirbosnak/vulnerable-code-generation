//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

struct device {
    char name[20];
    int priority;
    int bandwidth;
};

int main() {
    int num_devices = 0;
    struct device devices[MAX_DEVICES];

    printf("In the post-apocalyptic world, network resources are scarce.\n");
    printf("As a network administrator, you must prioritize devices based on\n");
    printf("their importance and allocate bandwidth accordingly.\n\n");

    // Add devices
    while (num_devices < MAX_DEVICES) {
        printf("Enter device name (or 'done' to finish): ");
        scanf("%s", devices[num_devices].name);

        if (strcmp(devices[num_devices].name, "done") == 0) break;

        printf("Enter device priority (1-10): ");
        scanf("%d", &devices[num_devices].priority);

        printf("Enter device bandwidth requirement (in kbps): ");
        scanf("%d", &devices[num_devices].bandwidth);

        num_devices++;
    }

    // Print device list
    printf("\nDevice List:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s - Priority: %d - Bandwidth: %d kbps\n",
               devices[i].name, devices[i].priority, devices[i].bandwidth);
    }

    // Calculate total bandwidth
    int total_bandwidth = 0;
    for (int i = 0; i < num_devices; i++) {
        total_bandwidth += devices[i].bandwidth;
    }

    // Allocate bandwidth
    int allocated_bandwidth = 0;
    for (int i = 0; i < num_devices; i++) {
        int device_bandwidth = (devices[i].bandwidth * devices[i].priority) / 10;
        if (allocated_bandwidth + device_bandwidth <= total_bandwidth) {
            allocated_bandwidth += device_bandwidth;
        } else {
            printf("\nNot enough bandwidth for device '%s'!\n", devices[i].name);
        }
    }

    // Print allocation results
    printf("\nBandwidth Allocation:\n");
    for (int i = 0; i < num_devices; i++) {
        int device_bandwidth = (devices[i].bandwidth * devices[i].priority) / 10;
        if (allocated_bandwidth >= device_bandwidth) {
            printf("%s - Allocated: %d kbps\n", devices[i].name, device_bandwidth);
        } else {
            printf("%s - Not Allocated\n", devices[i].name);
        }
    }

    return 0;
}