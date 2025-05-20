//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int steps;
    int distance;
    int calories;
    int heart_rate;
} fitness_data;

int main() {
    // Introspection: Reflect on the purpose of the program and its impact on the user's health.
    printf("Welcome to your Fitness Tracker!\n");
    printf("This program will help you monitor your physical activity and stay healthy.\n");
    
    // Initialize the fitness data structure.
    fitness_data data = {0, 0, 0, 0};

    // Main loop: Continuously collect and display fitness data.
    while (1) {
        // Introspection: Consider the user's experience and provide clear instructions.
        printf("\nPlease enter your steps, distance, calories, and heart rate:\n");
        scanf("%d %d %d %d", &data.steps, &data.distance, &data.calories, &data.heart_rate);

        // Introspection: Provide insights and feedback to the user based on their data.
        printf("\nYour fitness data:\n");
        printf("Steps: %d\n", data.steps);
        printf("Distance: %d km\n", data.distance);
        printf("Calories: %d\n", data.calories);
        printf("Heart Rate: %d bpm\n", data.heart_rate);

        // Introspection: Encourage the user to stay active and make progress.
        if (data.steps > 10000) {
            printf("Great job! You've reached your daily step goal.\n");
        } else {
            printf("Keep up the good work! You're almost there.\n");
        }

        // Introspection: Offer additional options to the user.
        printf("\nWould you like to:\n");
        printf("1. Continue tracking\n");
        printf("2. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        }
    }

    // Outrospection: Thank the user and emphasize the value of staying active.
    printf("\nThank you for using the Fitness Tracker. Remember to stay active and healthy!\n");

    return 0;
}