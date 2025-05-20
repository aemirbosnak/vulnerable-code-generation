//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of exercises and repetitions
#define MAX_EXERCISES 10
#define MAX_REPETITIONS 100

// Define the structure for an exercise
typedef struct {
    char name[50]; // Name of the exercise
    int repetitions; // Number of repetitions
} Exercise;

// Function to print the current date and time
void print_date_and_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("Current date and time: %s", asctime(t));
}

// Function to get user input for an exercise name
void get_exercise_name(Exercise *exercise) {
    printf("Enter the name of the exercise: ");
    scanf("%s", exercise->name);
}

// Function to get user input for the number of repetitions
void get_repetitions(Exercise *exercise) {
    int repetitions;
    do {
        printf("Enter the number of repetitions (1-100): ");
        scanf("%d", &repetitions);
    } while (repetitions < 1 || repetitions > MAX_REPETITIONS);
    exercise->repetitions = repetitions;
}

// Function to calculate the total number of repetitions for all exercises
int calculate_total_repetitions(Exercise exercises[], int num_exercises) {
    int total_repetitions = 0;
    for (int i = 0; i < num_exercises; i++) {
        total_repetitions += exercises[i].repetitions;
    }
    return total_repetitions;
}

// Function to print the total number of repetitions for all exercises
void print_total_repetitions(int total_repetitions) {
    printf("Total number of repetitions: %d\n", total_repetitions);
}

int main() {
    Exercise exercises[MAX_EXERCISES]; // Array to store exercises
    int num_exercises = 0; // Number of exercises entered by the user

    // Get the current date and time
    print_date_and_time();

    // Get the number of exercises from the user
    printf("Enter the number of exercises (1-10): ");
    scanf("%d", &num_exercises);

    // Get user input for each exercise
    for (int i = 0; i < num_exercises; i++) {
        get_exercise_name(&exercises[i]);
        get_repetitions(&exercises[i]);
    }

    // Calculate the total number of repetitions for all exercises
    int total_repetitions = calculate_total_repetitions(exercises, num_exercises);

    // Print the total number of repetitions for all exercises
    print_total_repetitions(total_repetitions);

    return 0;
}