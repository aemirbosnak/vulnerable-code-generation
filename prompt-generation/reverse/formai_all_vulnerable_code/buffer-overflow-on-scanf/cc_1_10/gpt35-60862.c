//FormAI DATASET v1.0 Category: System administration ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void displayMenu();
void addService();
void listServices();
void stopService();
int serviceExists(char* name);

typedef struct Service {
    char name[30];
    int isRunning;
} Service;

Service services[10];
int count = 0;

int main() {
    while (1) {
        displayMenu();
    }
    return 0;
}

void displayMenu() {
    printf("\nMenu\n");
    printf("1. Add service\n");
    printf("2. List services\n");
    printf("3. Stop service\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addService();
            break;
        case 2:
            listServices();
            break;
        case 3:
            stopService();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

void addService() {
    if (count >= 10) {
        printf("No more services can be added\n");
        return;
    }
    char name[30];
    printf("Enter name of service: ");
    scanf("%s", &name);
    int exists = serviceExists(name);
    if (exists == -1) {
        Service s;
        strcpy(s.name, name);
        s.isRunning = 1;
        services[count] = s;
        count++;
        printf("Service added successfully\n");
    } else {
        printf("Service already exists\n");
    }
}

void listServices() {
    printf("Services\n");
    printf("-------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t", services[i].name);
        if (services[i].isRunning) {
            printf("Running\n");
        } else {
            printf("Stopped\n");
        }
    }
}

void stopService() {
    char name[30];
    printf("Enter name of service to stop: ");
    scanf("%s", &name);
    int exists = serviceExists(name);
    if (exists != -1) {
        services[exists].isRunning = 0;
        printf("Service stopped successfully\n");
    } else {
        printf("Service doesn't exist\n");
    }
}

int serviceExists(char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(services[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}