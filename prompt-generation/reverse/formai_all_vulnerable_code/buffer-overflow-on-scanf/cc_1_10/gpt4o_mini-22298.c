//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SERVICES 100
#define SERVICE_NAME_LEN 50

typedef struct {
    char name[SERVICE_NAME_LEN];
    int boot_time; // Boot time in milliseconds
    int enabled; // 1 if enabled, 0 if disabled
} Service;

Service services[MAX_SERVICES];
int service_count = 0;

void load_services() {
    // Simulated loading of services (in real life, this would be more complex)
    strcpy(services[0].name, "networking");
    services[0].boot_time = 200;
    services[0].enabled = 1;

    strcpy(services[1].name, "ssh");
    services[1].boot_time = 100;
    services[1].enabled = 1;

    strcpy(services[2].name, "cron");
    services[2].boot_time = 50;
    services[2].enabled = 1;

    strcpy(services[3].name, "cups");
    services[3].boot_time = 150;
    services[3].enabled = 1;

    service_count = 4;
}

void display_services() {
    printf("\nCurrent Services:\n");
    printf("%-20s %-10s %-10s\n", "Service Name", "Boot Time", "Enabled");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < service_count; i++) {
        printf("%-20s %-10d %-10s\n", services[i].name, services[i].boot_time, services[i].enabled ? "Yes" : "No");
    }
}

void optimize_boot() {
    int total_time = 0;
    printf("\nOptimizing Services...\n");
    
    for (int i = 0; i < service_count; i++) {
        if (services[i].enabled) {
            total_time += services[i].boot_time;
        }
    }

    printf("Current Total Boot Time: %d ms\n", total_time);
    
    for (int i = 0; i < service_count; i++) {
        if (services[i].boot_time > 100 && services[i].enabled) {
            printf("Disabling %s to optimize boot time...\n", services[i].name);
            services[i].enabled = 0; // Disable service
        }
    }

    total_time = 0; // Resetting total time after optimizations
    for (int i = 0; i < service_count; i++) {
        if (services[i].enabled) {
            total_time += services[i].boot_time;
        }
    }

    printf("New Total Boot Time: %d ms\n", total_time);
    printf("Boot optimization complete!\n");
}

void save_optimization() {
    FILE *file = fopen("boot_optimization_report.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "Boot Optimization Report\n");
    fprintf(file, "========================\n");
    for (int i = 0; i < service_count; i++) {
        fprintf(file, "Service: %s, Boot Time: %d ms, Enabled: %s\n",
                services[i].name, services[i].boot_time, services[i].enabled ? "Yes" : "No");
    }

    fclose(file);
    printf("\nOptimization report saved to boot_optimization_report.txt\n");
}

int main() {
    load_services();
    int choice;

    while (1) {
        printf("\nWelcome to Boot Optimizer!\n");
        display_services();
        printf("\nOptions:\n");
        printf("1. Optimize Boot\n");
        printf("2. Save Optimization Report\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                optimize_boot();
                break;
            case 2:
                save_optimization();
                break;
            case 3:
                printf("Exiting Boot Optimizer. Have a good day!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}