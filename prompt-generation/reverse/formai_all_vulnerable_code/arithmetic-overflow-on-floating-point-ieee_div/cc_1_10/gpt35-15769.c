//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
// Romeo and Juliet Fitness Tracker
// by Chatbot

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Structure to hold user data
typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
    int steps;
} User;

// Function to calculate BMI
float calcBMI(float height, float weight) {
    return weight / ((height / 100) * (height / 100));
}

int main() {
    // Welcome message
    printf("Welcome to Romeo and Juliet Fitness Tracker!\n");

    // Create a new user
    User romeo;
    strcpy(romeo.name, "Romeo");
    romeo.age = 18;
    romeo.height = 180;
    romeo.weight = 70;
    romeo.steps = 0;

    // Create a new user
    User juliet;
    strcpy(juliet.name, "Juliet");
    juliet.age = 16;
    juliet.height = 165;
    juliet.weight = 50;
    juliet.steps = 0;

    // Show user information
    printf("\n%s's information:\n", romeo.name);
    printf("Age: %d\n", romeo.age);
    printf("Height: %.2fcm\n", romeo.height);
    printf("Weight: %.2fkg\n", romeo.weight);
    printf("BMI: %.2f\n", calcBMI(romeo.height, romeo.weight));

    // Show user information
    printf("\n%s's information:\n", juliet.name);
    printf("Age: %d\n", juliet.age);
    printf("Height: %.2fcm\n", juliet.height);
    printf("Weight: %.2fkg\n", juliet.weight);
    printf("BMI: %.2f\n", calcBMI(juliet.height, juliet.weight));

    // Prompt user to enter steps taken
    printf("\n%s, please enter the number of steps taken today: ", romeo.name);
    scanf("%d", &romeo.steps);
    printf("%s, you have taken %d steps today.\n", romeo.name, romeo.steps);

    // Prompt user to enter steps taken
    printf("\n%s, please enter the number of steps taken today: ", juliet.name);
    scanf("%d", &juliet.steps);
    printf("%s, you have taken %d steps today.\n", juliet.name, juliet.steps);

    // Calculate total steps taken
    int totalSteps = romeo.steps + juliet.steps;
    printf("\nTotal number of steps taken today: %d\n", totalSteps);

    // Determine who took more steps
    bool romeoMoreSteps = romeo.steps > juliet.steps;
    bool julietMoreSteps = juliet.steps > romeo.steps;

    if (romeoMoreSteps) {
        printf("%s took more steps than %s today.\n", romeo.name, juliet.name);
    } else if (julietMoreSteps) {
        printf("%s took more steps than %s today.\n", juliet.name, romeo.name);
    } else {
        printf("%s and %s took the same number of steps today.\n", romeo.name, juliet.name);
    }

    // Calculate BMI again
    printf("\n%s's updated information:\n", romeo.name);
    printf("BMI: %.2f\n", calcBMI(romeo.height, romeo.weight));

    // Calculate BMI again
    printf("\n%s's updated information:\n", juliet.name);
    printf("BMI: %.2f\n", calcBMI(juliet.height, juliet.weight));

    printf("\nThank you for using Romeo and Juliet Fitness Tracker!\n");

    return 0;
}