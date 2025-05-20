//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TEMP_HISTORY 100

typedef struct {
    char name[20];
    int temperature;
    time_t timestamp;
} TempData;

void addTempData(TempData* tempData, int temperature, char* name) {
    strncpy(tempData->name, name, 20);
    tempData->temperature = temperature;
    tempData->timestamp = time(NULL);
}

void printTempData(TempData* tempData) {
    printf("Name: %s\n", tempData->name);
    printf("Temperature: %d\n", tempData->temperature);
    printf("Timestamp: %s\n", ctime(&tempData->timestamp));
}

void displayTempHistory(TempData tempData[], int size) {
    if (size == 0) {
        printf("No temperature data available.\n");
        return;
    }

    printf("Temperature history:\n");
    for (int i = 0; i < size; i++) {
        printTempData(&tempData[i]);
    }
}

int main() {
    TempData tempData[MAX_TEMP_HISTORY];
    int size = 0;

    while (true) {
        int choice;
        printf("\n");
        printf("1. Add new temperature data\n");
        printf("2. Display temperature history\n");
        printf("3. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size >= MAX_TEMP_HISTORY) {
                printf("Temperature history is full. Please delete some entries first.\n");
                break;
            }

            char name[20];
            printf("Enter the name of the temperature sensor: ");
            scanf("%s", name);

            int temperature;
            printf("Enter the current temperature: ");
            scanf("%d", &temperature);

            addTempData(&tempData[size], temperature, name);
            size++;
            break;

        case 2:
            displayTempHistory(tempData, size);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}