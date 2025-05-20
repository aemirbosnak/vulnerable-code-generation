//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of exercises
#define NUM_EXERCISES 5

// Define the maximum number of sets and reps
#define MAX_SETS 5
#define MAX_REPS 50

// Define the structure for an exercise
typedef struct {
    char name[50];
    int sets;
    int reps;
} Exercise;

// Function to print the current date and time
void print_date_and_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("Current date and time: %s", asctime(t));
}

// Function to get user input for an integer
int get_integer_input(char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

// Function to get user input for a string
void get_string_input(char *prompt, char *input) {
    printf("%s", prompt);
    scanf("%s", input);
}

// Function to display the list of exercises
void display_exercises(Exercise exercises[]) {
    printf("\nList of Exercises:\n");
    for (int i = 0; i < NUM_EXERCISES; i++) {
        printf("%d. %s\n", i + 1, exercises[i].name);
    }
}

// Function to get user input for an exercise
void get_exercise_input(Exercise *exercise) {
    get_string_input("Enter the name of the exercise: ", exercise->name);
    exercise->sets = get_integer_input("Enter the number of sets: ");
    exercise->reps = get_integer_input("Enter the number of reps: ");
}

// Function to calculate the total number of reps for an exercise
int calculate_total_reps(Exercise exercise) {
    return exercise.sets * exercise.reps;
}

// Function to calculate the total number of reps for all exercises
int calculate_total_reps_all(Exercise exercises[]) {
    int total_reps = 0;
    for (int i = 0; i < NUM_EXERCISES; i++) {
        total_reps += calculate_total_reps(exercises[i]);
    }
    return total_reps;
}

int main() {
    Exercise exercises[NUM_EXERCISES];

    // Get user input for each exercise
    for (int i = 0; i < NUM_EXERCISES; i++) {
        get_exercise_input(&exercises[i]);
    }

    // Display the list of exercises
    display_exercises(exercises);

    // Calculate the total number of reps for all exercises
    int total_reps = calculate_total_reps_all(exercises);

    // Print the total number of reps
    printf("\nTotal number of reps: %d\n", total_reps);

    return 0;
}