//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTAINERS 100

typedef struct {
    int id;
    char containerType[20];
    bool isArrived;
    int location;
} Container;

Container warehouse[MAX_CONTAINERS];
int containerCount = 0;

void printMenu() {
    printf("\n--- CargoMaster Menu ---\n");
    printf("1. Arrive Container\n");
    printf("2. Depart Container\n");
    printf("3. List Containers\n");
    printf("4. Quit\n");
}

int getFreeLocation() {
    for (int i = 0; i < MAX_CONTAINERS; i++) {
        if (warehouse[i].location == -1) {
            return i;
        }
    }
    return -1;
}

void arriveContainer(Container newContainer) {
    int freeLocation = getFreeLocation();
    if (freeLocation != -1) {
        warehouse[freeLocation] = newContainer;
        containerCount++;
        printf("Container arrived with ID: %d and type: %s. Location assigned: %d.\n", newContainer.id, newContainer.containerType, freeLocation);
    } else {
        printf("No free location available. Container cannot be stored.\n");
    }
}

void departContainer(int containerId) {
    for (int i = 0; i < containerCount; i++) {
        if (warehouse[i].id == containerId) {
            warehouse[i].isArrived = false;
            warehouse[i].location = -1;
            containerCount--;
            printf("Container with ID: %d has been departed.\n", containerId);
            return;
        }
    }
    printf("Container with ID: %d not found.\n", containerId);
}

void listContainers() {
    if (containerCount == 0) {
        printf("No containers in the warehouse.\n");
        return;
    }
    printf("Containers in the warehouse:\n");
    for (int i = 0; i < containerCount; i++) {
        printf("ID: %d, Type: %s, Status: %s, Location: %d\n", warehouse[i].id, warehouse[i].containerType, (warehouse[i].isArrived ? "Arrived" : "Departed"), warehouse[i].location);
    }
}

int main() {
    int choice;
    Container newContainer;

    while (true) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter container ID: ");
                scanf("%d", &newContainer.id);
                printf("Enter container type: ");
                scanf("%s", newContainer.containerType);
                arriveContainer(newContainer);
                break;
            case 2:
                printf("Enter container ID: ");
                scanf("%d", &newContainer.id);
                departContainer(newContainer.id);
                break;
            case 3:
                listContainers();
                break;
            case 4:
                printf("Quitting CargoMaster...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}