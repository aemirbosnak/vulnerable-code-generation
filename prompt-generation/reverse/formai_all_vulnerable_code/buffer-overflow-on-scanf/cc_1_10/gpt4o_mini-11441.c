//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 10
#define SERVICE_NAME_LENGTH 20

typedef struct {
    char name[SERVICE_NAME_LENGTH];
    int enabled;
} Service;

Service services[MAX_SERVICES];
int service_count = 0;

// Function to initialize sample services
void init_services() {
    strcpy(services[0].name, "Network");
    services[0].enabled = 1;

    strcpy(services[1].name, "Bluetooth");
    services[1].enabled = 1;

    strcpy(services[2].name, "Socket");
    services[2].enabled = 1;

    strcpy(services[3].name, "Display");
    services[3].enabled = 1;

    strcpy(services[4].name, "Printer");
    services[4].enabled = 0;

    strcpy(services[5].name, "Firewall");
    services[5].enabled = 1;

    service_count = 6; // Initialize count of services
}

// Function to display services
void display_services() {
    printf("Available Services:\n");
    for (int i = 0; i < service_count; i++) {
        printf("[%d] %s - %s\n", i + 1, services[i].name,
               services[i].enabled ? "Enabled" : "Disabled");
    }
}

// Function to toggle service state
void toggle_service(int index) {
    if (index < 0 || index >= service_count) {
        printf("Invalid service index!\n");
        return;
    }
    services[index].enabled = !services[index].enabled;
    printf("Service '%s' is now %s.\n", services[index].name,
           services[index].enabled ? "Enabled" : "Disabled");
}

// Main function
int main() {
    int choice;

    init_services();
    
    while (1) {
        printf("\nBoot Optimizer Menu:\n");
        printf("1. Display Services\n");
        printf("2. Toggle Service\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                display_services();
                break;
            case 2:
                printf("Enter the service index to toggle: ");
                int service_index;
                if (scanf("%d", &service_index) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                toggle_service(service_index - 1); // Adjust for zero-based index
                break;
            case 3:
                printf("Exiting Boot Optimizer...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}