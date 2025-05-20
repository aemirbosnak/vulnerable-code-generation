//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories; // in kilocalories
    time_t date; // to store the date of the record
} FitnessRecord;

FitnessRecord records[MAX_RECORDS];
int recordCount = 0;

// Function to add a fitness record
void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Record limit reached. Cannot add more records.\n");
        return;
    }

    FitnessRecord newRecord;
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter steps taken: ");
    scanf("%d", &newRecord.steps);
    printf("Enter distance covered (in km): ");
    scanf("%f", &newRecord.distance);
    printf("Enter calories burned: ");
    scanf("%f", &newRecord.calories);
    newRecord.date = time(NULL); // capture the current date and time

    records[recordCount++] = newRecord;
    printf("Record added successfully!\n");
}

// Function to display fitness records
void displayRecords() {
    if (recordCount == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\n--- Fitness Records ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Record %d:\n", i + 1);
        printf("\tName: %s\n", records[i].name);
        printf("\tSteps: %d\n", records[i].steps);
        printf("\tDistance: %.2f km\n", records[i].distance);
        printf("\tCalories: %.2f kcal\n", records[i].calories);
        printf("\tDate: %s", ctime(&records[i].date));
        printf("-----------------------\n");
    }
}

// Function to calculate average steps
float averageSteps() {
    int totalSteps = 0;
    for (int i = 0; i < recordCount; i++) {
        totalSteps += records[i].steps;
    }
    return (recordCount == 0) ? 0.0 : (float)totalSteps / recordCount;
}

// Function to calculate total distance
float totalDistance() {
    float totalDistance = 0.0;
    for (int i = 0; i < recordCount; i++) {
        totalDistance += records[i].distance;
    }
    return totalDistance;
}

// Function to calculate total calories burned
float totalCalories() {
    float totalCalories = 0.0;
    for (int i = 0; i < recordCount; i++) {
        totalCalories += records[i].calories;
    }
    return totalCalories;
}

// Function to show statistics
void showStatistics() {
    printf("\n--- Statistical Data ---\n");
    printf("Average Steps: %.2f\n", averageSteps());
    printf("Total Distance: %.2f km\n", totalDistance());
    printf("Total Calories Burned: %.2f kcal\n", totalCalories());
}

// Function to display menu and handle user's choice
void menu() {
    int choice;
    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Show Statistics\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                showStatistics();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}