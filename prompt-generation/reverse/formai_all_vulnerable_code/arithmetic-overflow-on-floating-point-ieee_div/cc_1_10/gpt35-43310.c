//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness tracker
typedef struct FitnessTracker {
    char name[50];
    int age;
    float height;
    float weight;
    int steps;
    float distance;
} Fitness;

// Function to calculate the distance travelled
float calculate_distance(Fitness f) {
    return 0.7 * f.steps;
}

// Function to calculate Body Mass Index (BMI)
float calculate_bmi(Fitness f) {
    return f.weight / (f.height * f.height);
}

// Function to display user data
void display_user(Fitness f) {
    printf("\nName: %s\nAge: %d\nHeight: %.2f meters\nWeight: %.2f kg\nSteps Taken: %d\nDistance Travelled: %.2f meters\nBMI: %.2f\n", f.name, f.age, f.height, f.weight, f.steps, f.distance, calculate_bmi(f));
}

int main() {
    Fitness f;
    char option[10];
    printf("---- Welcome to the Fitness Tracker Program! ----\n\n");

    // Get user details
    printf("Enter your name: ");
    scanf("%[^\n]%*c", f.name);
    printf("Enter your age: ");
    scanf("%d", &f.age);
    printf("Enter your height (in meters): ");
    scanf("%f", &f.height);
    printf("Enter your weight (in kilograms): ");
    scanf("%f", &f.weight);
    printf("\n");

    display_user(f);

    // Loops through the menu until user enters 'quit'
    while (strcmp(option, "quit") != 0) {
        printf("\n---- Main Menu ----\n");
        printf("1. Record steps taken\n");
        printf("2. Display user data\n");
        printf("3. Quit\n");
        printf("Enter option: ");

        scanf("%[^\n]%*c", option);

        // If user enters option 1
        if (strcmp(option, "1") == 0) {
            int steps;
            printf("Enter the number of steps taken: ");
            scanf("%d", &steps);
            f.steps += steps;
            f.distance = calculate_distance(f);
            display_user(f);
        }
        // If user enters option 2
        else if (strcmp(option, "2") == 0) {
            display_user(f);
        }
        // If user enters an invalid option
        else if (strcmp(option, "3") != 0) {
            printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}