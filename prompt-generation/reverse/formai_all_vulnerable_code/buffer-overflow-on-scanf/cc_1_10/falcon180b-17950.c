//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    float temperature;
    char unit[10];
    time_t timestamp;
} Reading;

Reading readings[100];
int numReadings = 0;

void addReading() {
    if (numReadings == 100) {
        printf("Error: Maximum number of readings reached.\n");
        return;
    }

    printf("Enter the name of the sensor: ");
    scanf("%s", readings[numReadings].name);

    printf("Enter the temperature: ");
    scanf("%f", &readings[numReadings].temperature);

    printf("Enter the unit of measurement (C/F): ");
    scanf("%s", readings[numReadings].unit);

    readings[numReadings].timestamp = time(NULL);
    numReadings++;
}

void displayReadings() {
    printf("Name         | Temperature | Unit | Timestamp\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < numReadings; i++) {
        printf("%-20s | %-10.2f | %-6s | %s\n", readings[i].name, readings[i].temperature, readings[i].unit, ctime(&readings[i].timestamp));
    }
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("Welcome to the Temperature Monitor\n");
        printf("1. Add a new reading\n");
        printf("2. Display all readings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addReading();
            break;
        case 2:
            displayReadings();
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (true);

    return 0;
}