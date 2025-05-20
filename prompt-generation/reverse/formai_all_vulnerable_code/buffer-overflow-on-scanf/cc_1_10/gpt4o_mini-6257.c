//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define MAX_ACTIVITY_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float weight; // in kilograms
    int steps;
    float caloriesBurned;
    time_t startTime;
    time_t endTime;
} FitnessTracker;

FitnessTracker users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", users[userCount].name);
    printf("Enter age: ");
    scanf("%d", &users[userCount].age);
    printf("Enter weight (kg): ");
    scanf("%f", &users[userCount].weight);
    users[userCount].steps = 0;
    users[userCount].caloriesBurned = 0.0;
    users[userCount].startTime = time(NULL);
    users[userCount].endTime = 0;

    printf("User %s added successfully.\n", users[userCount].name);
    userCount++;
}

void recordActivity(int userIndex) {
    if (userIndex < 0 || userIndex >= userCount) {
        printf("Invalid user index.\n");
        return;
    }
    
    int steps;
    printf("Enter number of steps: ");
    scanf("%d", &steps);

    users[userIndex].steps += steps;
    users[userIndex].caloriesBurned += steps * 0.05; // approx. 0.05 calories per step

    printf("Activity recorded for %s: %d steps, %.2f calories burned.\n", 
            users[userIndex].name, users[userIndex].steps, users[userIndex].caloriesBurned);
}

void displayUserInfo(int userIndex) {
    if (userIndex < 0 || userIndex >= userCount) {
        printf("Invalid user index.\n");
        return;
    }

    FitnessTracker user = users[userIndex];
    printf("\nUser Information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Steps taken: %d\n", user.steps);
    printf("Calories burned: %.2f\n", user.caloriesBurned);
    printf("Start Time: %s", ctime(&user.startTime));
    if (user.endTime != 0) {
        printf("End Time: %s", ctime(&user.endTime));
    } else {
        printf("End Time: Activity still ongoing.\n");
    }
}

void endActivity(int userIndex) {
    if (userIndex < 0 || userIndex >= userCount) {
        printf("Invalid user index.\n");
        return;
    }

    users[userIndex].endTime = time(NULL);
    printf("Activity ended for %s.\n", users[userIndex].name);
}

void menu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add User\n");
    printf("2. Record Activity\n");
    printf("3. Display User Info\n");
    printf("4. End Activity\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    int userIndex;

    while (1) {
        menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                printf("Select user index (0 to %d): ", userCount - 1);
                scanf("%d", &userIndex);
                recordActivity(userIndex);
                break;
            case 3:
                printf("Select user index (0 to %d): ", userCount - 1);
                scanf("%d", &userIndex);
                displayUserInfo(userIndex);
                break;
            case 4:
                printf("Select user index (0 to %d): ", userCount - 1);
                scanf("%d", &userIndex);
                endActivity(userIndex);
                break;
            case 5:
                printf("Exiting Fitness Tracker. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}