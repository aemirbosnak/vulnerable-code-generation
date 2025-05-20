//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SERVICES 10
#define SERVICE_NAME_LENGTH 50

typedef struct {
    char name[SERVICE_NAME_LENGTH];
    int isRunning;
} Service;

Service services[MAX_SERVICES];
int serviceCount = 0;

void initializeServices() {
    strcpy(services[0].name, "Water Purification");
    services[0].isRunning = 0;

    strcpy(services[1].name, "Food Distribution");
    services[1].isRunning = 0;

    strcpy(services[2].name, "Waste Disposal");
    services[2].isRunning = 0;

    strcpy(services[3].name, "Energy Generation");
    services[3].isRunning = 0;

    serviceCount = 4;
}

void startService(int index) {
    if (index >= 0 && index < serviceCount) {
        if (services[index].isRunning) {
            printf("%s is already running.\n", services[index].name);
        } else {
            printf("Starting %s...\n", services[index].name);
            services[index].isRunning = 1;
            printf("%s is now running.\n", services[index].name);
        }
    } else {
        printf("Service index out of range.\n");
    }
}

void stopService(int index) {
    if (index >= 0 && index < serviceCount) {
        if (!services[index].isRunning) {
            printf("%s is not running.\n", services[index].name);
        } else {
            printf("Stopping %s...\n", services[index].name);
            services[index].isRunning = 0;
            printf("%s has been stopped.\n", services[index].name);
        }
    } else {
        printf("Service index out of range.\n");
    }
}

void displayServices() {
    printf("\nAvailable Services:\n");
    for (int i = 0; i < serviceCount; i++) {
        printf("[%d] %s - %s\n", i, services[i].name, services[i].isRunning ? "Running" : "Stopped");
    }
}

void displayMenu() {
    printf("\n--- Post-Apocalyptic Service Management ---\n");
    printf("[1] Start Service\n");
    printf("[2] Stop Service\n");
    printf("[3] Display Services\n");
    printf("[4] Exit\n");
}

int main() {
    int choice, serviceIndex;

    initializeServices();

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayServices();
                printf("Enter service index to start: ");
                scanf("%d", &serviceIndex);
                startService(serviceIndex);
                break;
            case 2:
                displayServices();
                printf("Enter service index to stop: ");
                scanf("%d", &serviceIndex);
                stopService(serviceIndex);
                break;
            case 3:
                displayServices();
                break;
            case 4:
                printf("Exiting the service management system. Stay safe out there!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Simulate the harsh environment with a delay
        sleep(1);
    }

    return 0;
}