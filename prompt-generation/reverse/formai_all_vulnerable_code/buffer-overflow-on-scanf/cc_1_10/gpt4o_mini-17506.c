//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DAYS 30

typedef struct {
    int steps;
    float calories;
    int workouts;
} FitnessData;

void addRecord(FitnessData *data, int day);
void viewRecord(FitnessData *data, int day);
void viewAverage(FitnessData *data, int numDays);
void resetData(FitnessData *data);

int main() {
    FitnessData fitnessData[MAX_DAYS] = {0};
    int choice, day, numDays;
    
    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add today's workout\n");
        printf("2. View today's record\n");
        printf("3. View average records for a number of days\n");
        printf("4. Reset all data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter day (1-30): ");
                scanf("%d", &day);
                if (day < 1 || day > 30) {
                    printf("Invalid day! Please enter a day between 1 and 30.\n");
                } else {
                    addRecord(fitnessData, day - 1);
                }
                break;
            case 2:
                printf("Enter day (1-30) to view: ");
                scanf("%d", &day);
                if (day < 1 || day > 30) {
                    printf("Invalid day! Please enter a day between 1 and 30.\n");
                } else {
                    viewRecord(fitnessData, day - 1);
                }
                break;
            case 3:
                printf("Enter number of days to view average (1-30): ");
                scanf("%d", &numDays);
                if (numDays < 1 || numDays > 30) {
                    printf("Invalid number of days! Please enter a number between 1 and 30.\n");
                } else {
                    viewAverage(fitnessData, numDays);
                }
                break;
            case 4:
                resetData(fitnessData);
                printf("Data reset successful.\n");
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

void addRecord(FitnessData *data, int day) {
    printf("Enter steps taken: ");
    scanf("%d", &data[day].steps);
    printf("Enter calories burned: ");
    scanf("%f", &data[day].calories);
    printf("Enter number of workouts (1 or 0): ");
    scanf("%d", &data[day].workouts);
    printf("Record added successfully for day %d.\n", day + 1);
}

void viewRecord(FitnessData *data, int day) {
    printf("Record for day %d:\n", day + 1);
    printf("Steps: %d\n", data[day].steps);
    printf("Calories burned: %.2f\n", data[day].calories);
    printf("Workouts completed: %d\n", data[day].workouts);
}

void viewAverage(FitnessData *data, int numDays) {
    int totalSteps = 0;
    float totalCalories = 0.0f;
    int totalWorkouts = 0;

    for (int i = 0; i < numDays; i++) {
        totalSteps += data[i].steps;
        totalCalories += data[i].calories;
        totalWorkouts += data[i].workouts;
    }

    printf("Average records over last %d days:\n", numDays);
    printf("Average Steps: %.2f\n", (float)totalSteps / numDays);
    printf("Average Calories burned: %.2f\n", totalCalories / numDays);
    printf("Average Workouts completed: %.2f\n", (float)totalWorkouts / numDays);
}

void resetData(FitnessData *data) {
    memset(data, 0, sizeof(FitnessData) * MAX_DAYS);
}