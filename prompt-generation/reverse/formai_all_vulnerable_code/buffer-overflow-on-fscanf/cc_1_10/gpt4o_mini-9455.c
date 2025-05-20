//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SERVICES 50
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int priority;
} Service;

Service services[MAX_SERVICES];
int serviceCount = 0;

void addService(const char *name, int priority) {
    if (serviceCount < MAX_SERVICES) {
        strncpy(services[serviceCount].name, name, MAX_NAME_LEN - 1);
        services[serviceCount].name[MAX_NAME_LEN - 1] = '\0';
        services[serviceCount].priority = priority;
        serviceCount++;
    } else {
        printf("Cannot add more services. Maximum limit reached.\n");
    }
}

void displayServices() {
    printf("Configured Services:\n");
    for (int i = 0; i < serviceCount; i++) {
        printf("Service: %s, Priority: %d\n", services[i].name, services[i].priority);
    }
}

void swapServices(int index1, int index2) {
    Service temp = services[index1];
    services[index1] = services[index2];
    services[index2] = temp;
}

void optimizeBootOrder() {
    printf("Optimizing boot order...\n");
    for (int i = 0; i < serviceCount - 1; i++) {
        for (int j = i + 1; j < serviceCount; j++) {
            if (services[i].priority > services[j].priority) {
                swapServices(i, j);
            }
        }
    }
    printf("Boot order optimized!\n");
}

void saveBootConfig(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < serviceCount; i++) {
        fprintf(file, "%s %d\n", services[i].name, services[i].priority);
    }

    fclose(file);
    printf("Boot configuration saved to %s\n", filename);
}

void loadBootConfig(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }

    serviceCount = 0;
    while (fscanf(file, "%s %d", services[serviceCount].name, &services[serviceCount].priority) != EOF) {
        serviceCount++;
        if (serviceCount >= MAX_SERVICES) {
            break;
        }
    }

    fclose(file);
    printf("Boot configuration loaded from %s\n", filename);
}

int main() {
    int choice;
    char serviceName[MAX_NAME_LEN];
    int priority;
    const char *configFile = "boot_config.txt";

    while (1) {
        printf("\nDecentralized Boot Optimizer\n");
        printf("1. Add Service\n");
        printf("2. Display Services\n");
        printf("3. Optimize Boot Order\n");
        printf("4. Save Boot Configuration\n");
        printf("5. Load Boot Configuration\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter service name: ");
                scanf("%s", serviceName);
                printf("Enter service priority (lower is higher priority): ");
                scanf("%d", &priority);
                addService(serviceName, priority);
                break;
            case 2:
                displayServices();
                break;
            case 3:
                optimizeBootOrder();
                break;
            case 4:
                saveBootConfig(configFile);
                break;
            case 5:
                loadBootConfig(configFile);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}