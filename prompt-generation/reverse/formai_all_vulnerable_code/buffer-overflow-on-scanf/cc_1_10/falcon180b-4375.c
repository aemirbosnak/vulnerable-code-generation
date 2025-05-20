//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    int height;
    int weight;
    int steps;
    int caloriesBurned;
    int heartRate;
} User;

void createUser(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your height (in cm): ");
    scanf("%d", &user->height);

    printf("Enter your weight (in kg): ");
    scanf("%d", &user->weight);
}

void updateSteps(User* user) {
    printf("Enter your steps: ");
    scanf("%d", &user->steps);

    int caloriesBurned = user->weight * user->steps / 100;
    user->caloriesBurned += caloriesBurned;
}

void updateHeartRate(User* user) {
    printf("Enter your heart rate: ");
    scanf("%d", &user->heartRate);
}

void displayUserInfo(User* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %d cm\n", user->height);
    printf("Weight: %d kg\n", user->weight);
    printf("Steps: %d\n", user->steps);
    printf("Calories burned: %d\n", user->caloriesBurned);
    printf("Heart rate: %d\n", user->heartRate);
}

int main() {
    User user;
    createUser(&user);

    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Update steps\n");
        printf("2. Update heart rate\n");
        printf("3. Display user info\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            updateSteps(&user);
            break;
        case 2:
            updateHeartRate(&user);
            break;
        case 3:
            displayUserInfo(&user);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}