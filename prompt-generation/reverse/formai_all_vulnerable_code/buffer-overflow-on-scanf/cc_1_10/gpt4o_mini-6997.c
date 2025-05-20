//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int load_time; // in milliseconds
} Service;

void input_services(Service services[], int *n) {
    printf("Enter the number of services (max %d): ", MAX_SERVICES);
    scanf("%d", n);
    
    for (int i = 0; i < *n; i++) {
        printf("Enter name of service %d: ", i + 1);
        scanf("%s", services[i].name);
        printf("Enter load time for %s (in ms): ", services[i].name);
        scanf("%d", &services[i].load_time);
    }
}

int compare_services(const void *a, const void *b) {
    return ((Service *)a)->load_time - ((Service *)b)->load_time;
}

void optimize_boot_sequence(Service services[], int n) {
    qsort(services, n, sizeof(Service), compare_services);
}

void simulate_boot_sequence(Service services[], int n) {
    printf("\nStarting optimized boot sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("Loading service: %s (Load Time: %d ms)\n", services[i].name, services[i].load_time);
        // Simulate loading time
        usleep(services[i].load_time * 1000); // Convert ms to microseconds
    }
    printf("Boot sequence completed successfully!\n");
}

void display_services(Service services[], int n) {
    printf("\nCurrent services and their load times:\n");
    for (int i = 0; i < n; i++) {
        printf("Service: %s, Load Time: %d ms\n", services[i].name, services[i].load_time);
    }
}

int main() {
    Service services[MAX_SERVICES];
    int n = 0;

    input_services(services, &n);
    display_services(services, n);
    
    optimize_boot_sequence(services, n);
    
    simulate_boot_sequence(services, n);

    return 0;
}