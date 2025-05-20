//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int enabled; // 1 for enabled, 0 for disabled
} Service;

void printServices(Service services[], int count) {
    printf("\nAvailable Services:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s [%s]\n", 
            i + 1, 
            services[i].name, 
            services[i].enabled ? "Enabled" : "Disabled");
    }
}

void toggleService(Service *service) {
    service->enabled = !service->enabled;
}

void optimizeBoot(Service services[], int count) {
    printf("\nOptimizing boot services...\n");

    for (int i = 0; i < count; i++) {
        if (services[i].enabled) {
            printf("Starting %s...\n", services[i].name);
        } else {
            printf("Skipping %s...\n", services[i].name);
        }
    }
    printf("\nBoot optimization complete! Let’s go!\n");
}

int main() {
    Service services[MAX_SERVICES] = {
        {"Network Service", 1},
        {"Logging Service", 0},
        {"Database Service", 1},
        {"Web Server", 0},
        {"Background Sync", 1},
        {"Firewall", 0},
        {"Update Checker", 0},
        {"Print Spooler", 1},
        {"Virtual Machine", 0},
        {"File Sync", 0}
    };

    int serviceCount = 10;
    int choice;

    printf("Welcome to the Boot Optimizer!\n");
    printf("This program will help you optimize the services that run at boot time!\n");

    do {
        printServices(services, serviceCount);
        printf("\nEnter the number of the service to toggle (or 0 to optimize boot): ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= serviceCount) {
            toggleService(&services[choice - 1]);
            printf("Toggled %s to %s.\n", 
                services[choice - 1].name, 
                services[choice - 1].enabled ? "Enabled" : "Disabled");
        } else if (choice == 0) {
            optimizeBoot(services, serviceCount);
            break; // Exit the loop after optimization
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    printf("Thank you for using the Boot Optimizer! Fast booting ahead!\n");
    return 0;
}