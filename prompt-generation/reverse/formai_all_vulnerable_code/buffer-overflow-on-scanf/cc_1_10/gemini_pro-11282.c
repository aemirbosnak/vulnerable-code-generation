//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[32];
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    int distance;
    time_t timestamp;
} fitness_data_t;

int main() {
    fitness_data_t data;

    // Get user input
    printf("Enter your name: ");
    scanf("%s", data.name);

    printf("Enter your age: ");
    scanf("%d", &data.age);

    printf("Enter your weight (in pounds): ");
    scanf("%d", &data.weight);

    printf("Enter your height (in inches): ");
    scanf("%d", &data.height);

    // Initialize fitness data
    data.steps = 0;
    data.calories = 0;
    data.distance = 0;
    data.timestamp = time(NULL);

    // Start fitness tracking loop
    while (1) {
        // Get user input
        printf("\nWhat would you like to do?\n");
        printf("1. Start walking\n");
        printf("2. Stop walking\n");
        printf("3. View fitness data\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                printf("How many steps did you take? ");
                scanf("%d", &data.steps);

                printf("How many calories did you burn? ");
                scanf("%d", &data.calories);

                printf("How far did you walk (in miles)? ");
                scanf("%d", &data.distance);

                data.timestamp = time(NULL);
                break;

            case 2:
                // Stop walking
                break;

            case 3:
                // View fitness data
                printf("\nFitness Data\n");
                printf("Name: %s\n", data.name);
                printf("Age: %d\n", data.age);
                printf("Weight: %d pounds\n", data.weight);
                printf("Height: %d inches\n", data.height);
                printf("Steps: %d\n", data.steps);
                printf("Calories: %d\n", data.calories);
                printf("Distance: %d miles\n", data.distance);
                printf("Timestamp: %s\n", ctime(&data.timestamp));
                break;

            case 4:
                // Quit
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}