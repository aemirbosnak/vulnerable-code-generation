//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to store fitness data
typedef struct {
    int steps;
    float distance;
    float calories;
} FitnessData;

// Struct to store user info
typedef struct {
    char name[50];
    int age;
    char gender;
    float weight;
    float height;
    FitnessData data;
} User;

// Function to update fitness data
void updateFitnessData(User* user, int steps) {
    // Calculate distance (assuming an average stride length of 0.8 meters)
    float distance = steps * 0.8;

    // Calculate calories burnt (assuming an average calorie burn of 0.05 calories per step)
    float calories = steps * 0.05;

    // Update user's fitness data
    user->data.steps += steps;
    user->data.distance += distance;
    user->data.calories += calories;
}

int main() {
    // Create a new user
    User user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &user.gender);
    printf("Enter your weight (in kilograms): ");
    scanf("%f", &user.weight);
    printf("Enter your height (in meters): ");
    scanf("%f", &user.height);

    // Initialize fitness data
    user.data.steps = 0;
    user.data.distance = 0;
    user.data.calories = 0;

    // Loop to track fitness data
    char choice[10];
    while (1) {
        printf("\n--- Fitness Tracker ---\n");
        printf("1. Record steps\n");
        printf("2. View fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            int steps;
            printf("Enter number of steps: ");
            scanf("%d", &steps);
            updateFitnessData(&user, steps);
            printf("Fitness data updated!\n");
        } else if (strcmp(choice, "2") == 0) {
            printf("\n--- Fitness Data ---\n");
            printf("Name: %s\n", user.name);
            printf("Age: %d\n", user.age);
            printf("Gender: %c\n", user.gender);
            printf("Weight: %.2f kg\n", user.weight);
            printf("Height: %.2f m\n", user.height);
            printf("Steps: %d\n", user.data.steps);
            printf("Distance: %.2f m\n", user.data.distance);
            printf("Calories: %.2f cal\n", user.data.calories);
        } else if (strcmp(choice, "3") == 0) {
            printf("Exiting Fitness Tracker...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}