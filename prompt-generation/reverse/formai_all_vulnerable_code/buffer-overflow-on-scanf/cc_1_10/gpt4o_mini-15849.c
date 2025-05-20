//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned; // per minute
} Exercise;

typedef struct {
    int steps;
    int caloriesIntake;
    Exercise exercises[MAX_EXERCISES];
    int exerciseCount;
} UserFitnessData;

void displayMenu();
void addExercise(UserFitnessData* data);
void logSteps(UserFitnessData* data);
void logCalories(UserFitnessData* data);
void displayData(const UserFitnessData* data);
void resetData(UserFitnessData* data);

int main() {
    UserFitnessData userData = {0};
    userData.exerciseCount = 0;

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExercise(&userData);
                break;
            case 2:
                logSteps(&userData);
                break;
            case 3:
                logCalories(&userData);
                break;
            case 4:
                displayData(&userData);
                break;
            case 5:
                resetData(&userData);
                break;
            case 0:
                printf("Exiting program. Stay fit!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Exercise\n");
    printf("2. Log Steps\n");
    printf("3. Log Calories Intake\n");
    printf("4. Display Data\n");
    printf("5. Reset Data\n");
    printf("0. Exit\n");
}

void addExercise(UserFitnessData* data) {
    if (data->exerciseCount >= MAX_EXERCISES) {
        printf("You can't add more exercises!\n");
        return;
    }

    Exercise newExercise;

    printf("Enter the name of the exercise: ");
    scanf("%s", newExercise.name);
    printf("Enter the duration in minutes: ");
    scanf("%d", &newExercise.duration);
    printf("Enter calories burned per minute: ");
    scanf("%d", &newExercise.caloriesBurned);

    data->exercises[data->exerciseCount] = newExercise;
    data->exerciseCount++;
    printf("Exercise added successfully!\n");
}

void logSteps(UserFitnessData* data) {
    int steps;

    printf("Enter the number of steps: ");
    scanf("%d", &steps);
    data->steps += steps;
    printf("Logged %d steps. Total steps: %d\n", steps, data->steps);
}

void logCalories(UserFitnessData* data) {
    int calories;

    printf("Enter the calories consumed: ");
    scanf("%d", &calories);
    data->caloriesIntake += calories;
    printf("Logged %d calories. Total calories intake: %d\n", calories, data->caloriesIntake);
}

void displayData(const UserFitnessData* data) {
    printf("\n--- User Fitness Data ---\n");
    printf("Total Steps: %d\n", data->steps);
    printf("Total Calories Intake: %d\n", data->caloriesIntake);
    printf("Exercises Log:\n");

    for (int i = 0; i < data->exerciseCount; i++) {
        printf("%s - Duration: %d minutes, Calories Burned per minute: %d\n",
               data->exercises[i].name,
               data->exercises[i].duration,
               data->exercises[i].caloriesBurned);
    }

    if (data->exerciseCount == 0) {
        printf("No exercises logged yet.\n");
    }
}

void resetData(UserFitnessData* data) {
    memset(data, 0, sizeof(UserFitnessData));
    printf("Data has been reset!\n");
}