//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SERVICES 10
#define SERVICE_NAME_LEN 30

typedef struct {
    char name[SERVICE_NAME_LEN];
    int bootTime; // Time taken to boot this service
    int runtime;  // How often the service is frequently used
    int importance; // Importance level from 1 (low) to 5 (high)
} Service;

void inputServices(Service services[], int *service_count) {
    printf("Enter the number of services (max %d): ", MAX_SERVICES);
    scanf("%d", service_count);
    if (*service_count > MAX_SERVICES) *service_count = MAX_SERVICES;

    for (int i = 0; i < *service_count; i++) {
        printf("Enter service name: ");
        scanf("%s", services[i].name);
        printf("Enter boot time (ms): ");
        scanf("%d", &services[i].bootTime);
        printf("Enter runtime frequency (1-10): ");
        scanf("%d", &services[i].runtime);
        printf("Enter importance (1-5): ");
        scanf("%d", &services[i].importance);
    }
}

void optimizeBootOrder(Service services[], int service_count) {
    // Sort services based on custom metric (importance * runtime / bootTime)
    for (int i = 0; i < service_count - 1; i++) {
        for (int j = 0; j < service_count - i - 1; j++) {
            float metric1 = (services[j].importance * services[j].runtime) / (float)services[j].bootTime;
            float metric2 = (services[j + 1].importance * services[j + 1].runtime) / (float)services[j + 1].bootTime;
            if (metric1 < metric2) {
                Service tmp = services[j];
                services[j] = services[j + 1];
                services[j + 1] = tmp;
            }
        }
    }
}

void displayOptimizedOrder(Service services[], int service_count) {
    printf("\nOptimized Boot Order:\n");
    for (int i = 0; i < service_count; i++) {
        printf("Service: %-20s | Boot Time: %3d ms | Runtime: %d | Importance: %d\n",
                services[i].name, services[i].bootTime, services[i].runtime, services[i].importance);
    }
}

int main() {
    Service services[MAX_SERVICES];
    int service_count;

    // Input Services
    inputServices(services, &service_count);

    // Optimize Boot Order
    optimizeBootOrder(services, service_count);

    // Display Optimized Order
    displayOptimizedOrder(services, service_count);

    return 0;
}