//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for the fitness tracker
struct FitnessTracker {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int numSteps;
};

// Function to calculate BMI
float getBMI(float weight, float height) {
    float bmi = weight / (height * height);
    return bmi;
}

int main() {
    // Initialize fitness tracker struct
    struct FitnessTracker user;

    // Get user's name
    printf("What is your name? ");
    fgets(user.name, 50, stdin);
    user.name[strcspn(user.name, "\n")] = '\0';

    // Get user's age
    printf("What is your age? ");
    scanf("%d", &user.age);

    // Get user's weight
    printf("What is your weight in kilograms? ");
    scanf("%f", &user.weight);

    // Get user's height
    printf("What is your height in meters? ");
    scanf("%f", &user.height);

    // Calculate BMI
    user.bmi = getBMI(user.weight, user.height);
    printf("Your BMI is %.2f\n", user.bmi);

    // Get number of steps taken today
    printf("How many steps have you taken today? ");
    scanf("%d", &user.numSteps);

    // Print out summary of user's information
    printf("\n%s's Fitness Tracker Summary\n", user.name);
    printf("Age: %d years\n", user.age);
    printf("Weight: %.2f kilograms\n", user.weight);
    printf("Height: %.2f meters\n", user.height);
    printf("BMI: %.2f\n", user.bmi);
    printf("Number of steps taken today: %d\n", user.numSteps);

    // Save user's information to file
    FILE *fp = fopen("user_info.txt", "w");
    if(fp == NULL) {
        printf("Error opening file for writing.\n");
        return -1;
    }
    fprintf(fp, "Name: %s\n", user.name);
    fprintf(fp, "Age: %d years\n", user.age);
    fprintf(fp, "Weight: %.2f kilograms\n", user.weight);
    fprintf(fp, "Height: %.2f meters\n", user.height);
    fprintf(fp, "BMI: %.2f\n", user.bmi);
    fprintf(fp, "Number of steps taken today: %d\n", user.numSteps);
    fclose(fp);

    printf("\nUser information saved to file user_info.txt.\n");

    return 0;
}