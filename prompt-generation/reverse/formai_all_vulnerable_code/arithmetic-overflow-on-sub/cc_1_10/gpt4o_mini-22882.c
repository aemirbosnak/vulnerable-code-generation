//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 10
#define SERVICE_NAME_LENGTH 50

typedef struct {
    char name[SERVICE_NAME_LENGTH];
    int enabled;
} Service;

Service services[MAX_SERVICES];
int service_count = 0;

void initialize_services() {
    // Initialize some example services
    strcpy(services[0].name, "Network Manager");
    services[0].enabled = 1;
    
    strcpy(services[1].name, "Bluetooth");
    services[1].enabled = 0;
    
    strcpy(services[2].name, "Printing Service");
    services[2].enabled = 1;

    service_count = 3; // We initialized 3 services
}

void display_services() {
    printf("\nCurrent Boot Services:\n");
    for (int i = 0; i < service_count; i++) {
        printf(" [%d] %s - %s\n", i + 1, services[i].name, services[i].enabled ? "Enabled" : "Disabled");
    }
}

void enable_service(int index) {
    if (index >= 0 && index < service_count) {
        services[index].enabled = 1;
        printf("Service '%s' enabled successfully.\n", services[index].name);
    } else {
        printf("Invalid service index!\n");
    }
}

void disable_service(int index) {
    if (index >= 0 && index < service_count) {
        services[index].enabled = 0;
        printf("Service '%s' disabled successfully.\n", services[index].name);
    } else {
        printf("Invalid service index!\n");
    }
}

void save_services_state() {
    FILE *file = fopen("service_state.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving service state.\n");
        return;
    }
    
    for (int i = 0; i < service_count; i++) {
        fprintf(file, "%s %d\n", services[i].name, services[i].enabled);
    }
    
    fclose(file);
    printf("Service states saved successfully to 'service_state.txt'.\n");
}

void load_services_state() {
    FILE *file = fopen("service_state.txt", "r");
    if (file == NULL) {
        printf("No previous service state found. Starting fresh.\n");
        return;
    }
    
    service_count = 0;
    while (fscanf(file, "%s %d", services[service_count].name, &services[service_count].enabled) != EOF) {
        service_count++;
        if (service_count >= MAX_SERVICES) break;
    }

    fclose(file);
    printf("Service states loaded successfully from 'service_state.txt'.\n");
}

int main() {
    load_services_state();
    display_services();
    
    int choice, index;
    
    while (1) {
        printf("\n1. Enable Service\n2. Disable Service\n3. Save Service State\n4. Display Services\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter service index to enable (1-%d): ", service_count);
                scanf("%d", &index);
                enable_service(index - 1);
                break;
            case 2:
                printf("Enter service index to disable (1-%d): ", service_count);
                scanf("%d", &index);
                disable_service(index - 1);
                break;
            case 3:
                save_services_state();
                break;
            case 4:
                display_services();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}