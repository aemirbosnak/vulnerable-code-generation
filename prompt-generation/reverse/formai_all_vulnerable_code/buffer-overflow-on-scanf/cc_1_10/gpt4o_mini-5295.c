//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 100
#define SERVICE_NAME_LENGTH 256

typedef struct {
    char name[SERVICE_NAME_LENGTH];
    int enabled; // 1 for enabled, 0 for disabled
} Service;

Service services[MAX_SERVICES];
int service_count = 0;

void load_services() {
    // Simulated loading of services
    strcpy(services[0].name, "network.service");
    services[0].enabled = 1;
    strcpy(services[1].name, "bluetooth.service");
    services[1].enabled = 1;
    strcpy(services[2].name, "cron.service");
    services[2].enabled = 1;
    strcpy(services[3].name, "ssh.service");
    services[3].enabled = 1;
    service_count = 4;
}

void display_services() {
    printf("\n=== Available Services ===\n");
    for (int i = 0; i < service_count; i++) {
        printf("%d. %s [%s]\n", i + 1, services[i].name, services[i].enabled ? "Enabled" : "Disabled");
    }
}

void toggle_service(int index) {
    services[index].enabled = !services[index].enabled;
    printf("Service '%s' has been %s.\n", services[index].name, services[index].enabled ? "enabled" : "disabled");
}

void optimize_boot() {
    printf("\n=== Boot Optimization Report ===\n");
    for (int i = 0; i < service_count; i++) {
        if (!services[i].enabled) {
            printf("Disabling service: %s\n", services[i].name);
            char command[SERVICE_NAME_LENGTH + 30];
            snprintf(command, sizeof(command), "systemctl disable %s", services[i].name);
            system(command);
        }
    }
    printf("Boot optimization completed!\n");
}

void start_optimizer() {
    int choice;

    load_services();

    while (1) {
        display_services();
        printf("\nOptions:\n1. Toggle Service\n2. Optimize Boot\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int service_number;
                printf("Enter service number to toggle: ");
                scanf("%d", &service_number);
                if (service_number > 0 && service_number <= service_count) {
                    toggle_service(service_number - 1);
                } else {
                    printf("Invalid service number!\n");
                }
                break;
            }
            case 2:
                optimize_boot();
                break;
            case 3:
                printf("Exiting the Boot Optimizer. Goodbye!\n");
                return;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    printf("=== System Boot Optimizer ===\n");
    start_optimizer();
    return 0;
}