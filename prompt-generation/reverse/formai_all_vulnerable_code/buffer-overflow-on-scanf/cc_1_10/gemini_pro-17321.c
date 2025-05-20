//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Define the user's fitness data
typedef struct {
    char name[20];
    int age;
    float weight;
    float height;
    int steps;
    int calories;
} fitness_data;

// Define the fitness tracker's main menu
enum menu_option {
    MENU_OPTION_TRACK_STEPS = 1,
    MENU_OPTION_TRACK_CALORIES,
    MENU_OPTION_VIEW_DATA,
    MENU_OPTION_QUIT
};

// Define the fitness tracker's functions
void track_steps(fitness_data *data);
void track_calories(fitness_data *data);
void view_data(fitness_data *data);
void quit(fitness_data *data);

// Define the main function
int main() {
    // Create a new fitness tracker
    fitness_data data;

    // Get the user's name
    printf("What is your name? ");
    scanf("%s", data.name);

    // Get the user's age
    printf("What is your age? ");
    scanf("%d", &data.age);

    // Get the user's weight
    printf("What is your weight (in pounds)? ");
    scanf("%f", &data.weight);

    // Get the user's height
    printf("What is your height (in inches)? ");
    scanf("%f", &data.height);

    // Set the user's steps to 0
    data.steps = 0;

    // Set the user's calories to 0
    data.calories = 0;

    // Display the main menu
    int choice;
    do {
        printf("\nFitness Tracker Main Menu\n");
        printf("1. Track Steps\n");
        printf("2. Track Calories\n");
        printf("3. View Data\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case MENU_OPTION_TRACK_STEPS:
                track_steps(&data);
                break;
            case MENU_OPTION_TRACK_CALORIES:
                track_calories(&data);
                break;
            case MENU_OPTION_VIEW_DATA:
                view_data(&data);
                break;
            case MENU_OPTION_QUIT:
                quit(&data);
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != MENU_OPTION_QUIT);

    return 0;
}

// Define the track_steps function
void track_steps(fitness_data *data) {
    // Get the number of steps the user has taken
    int steps;
    printf("How many steps have you taken? ");
    scanf("%d", &steps);

    // Add the number of steps to the user's total steps
    data->steps += steps;

    // Display the number of steps the user has taken
    printf("You have taken %d steps today.\n", data->steps);
}

// Define the track_calories function
void track_calories(fitness_data *data) {
    // Get the number of calories the user has consumed
    int calories;
    printf("How many calories have you consumed today? ");
    scanf("%d", &calories);

    // Add the number of calories to the user's total calories
    data->calories += calories;

    // Display the number of calories the user has consumed
    printf("You have consumed %d calories today.\n", data->calories);
}

// Define the view_data function
void view_data(fitness_data *data) {
    // Display the user's fitness data
    printf("\nFitness Data\n");
    printf("Name: %s\n", data->name);
    printf("Age: %d\n", data->age);
    printf("Weight: %.2f pounds\n", data->weight);
    printf("Height: %.2f inches\n", data->height);
    printf("Steps: %d\n", data->steps);
    printf("Calories: %d\n", data->calories);
}

// Define the quit function
void quit(fitness_data *data) {
    // Thank the user for using the fitness tracker
    printf("Thank you for using the Fitness Tracker. Goodbye!\n");
}