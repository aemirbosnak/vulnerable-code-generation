//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to hold the user's information
struct User {
    char name[50];
    int age;
    float weight;
    int height_feet;
    int height_inches;
    char gender[10];
};

// Create a struct to hold exercise data
struct Exercise {
    char name[50];
    int duration_minutes;
    float calories_burned;
};

int main() {
    // Create a new user and prompt for their information
    struct User user;
    printf("Welcome to Fitness Tracker!\n");
    printf("What is your name? ");
    fgets(user.name, 50, stdin);
    printf("Age: ");
    scanf("%d", &user.age);
    printf("Weight (in pounds): ");
    scanf("%f", &user.weight);
    printf("Height (feet): ");
    scanf("%d", &user.height_feet);
    printf("Height (inches): ");
    scanf("%d", &user.height_inches);
    printf("Gender: ");
    scanf("%s", user.gender);

    // Print the user's information
    printf("\nHello, %s! Here is your information:\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.1f pounds\n", user.weight);
    printf("Height: %d feet %d inches\n", user.height_feet, user.height_inches);
    printf("Gender: %s\n", user.gender);

    // Prompt the user for exercise data
    printf("\nLet's log some exercise!\n");
    struct Exercise exercises[3];
    for (int i = 0; i < 3; i++) {
        printf("\nExercise #%d\n", i+1);
        printf("Name: ");
        scanf("%s", exercises[i].name);
        printf("Duration (in minutes): ");
        scanf("%d", &exercises[i].duration_minutes);
        printf("Calories burned: ");
        scanf("%f", &exercises[i].calories_burned);
    }

    // Print out exercise data
    printf("\nExercise log:\n");
    float total_calories = 0;
    for (int i = 0; i < 3; i++) {
        printf("Exercise #%d: %s\n", i+1, exercises[i].name);
        printf("Duration: %d minutes\n", exercises[i].duration_minutes);
        printf("Calories burned: %.1f\n", exercises[i].calories_burned);
        total_calories += exercises[i].calories_burned;
    }
    printf("\nTotal calories burned: %.1f\n", total_calories);

    return 0;
}