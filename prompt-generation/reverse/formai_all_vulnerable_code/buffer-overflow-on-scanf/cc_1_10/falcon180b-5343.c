//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of exercises
#define MAX_EXERCISES 100

// Define the structure for an exercise
typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

// Function to add an exercise
void add_exercise(Exercise* exercises, int num_exercises, char* name, int duration, int calories) {
    if (num_exercises >= MAX_EXERCISES) {
        printf("Error: Maximum number of exercises reached.\n");
        return;
    }
    
    strcpy(exercises[num_exercises].name, name);
    exercises[num_exercises].duration = duration;
    exercises[num_exercises].calories = calories;
    
    num_exercises++;
}

// Function to display the list of exercises
void display_exercises(Exercise* exercises, int num_exercises) {
    printf("List of exercises:\n");
    for (int i = 0; i < num_exercises; i++) {
        printf("%s - %d minutes - %d calories\n", exercises[i].name, exercises[i].duration, exercises[i].calories);
    }
}

// Function to calculate the total calories burned during a workout
int calculate_calories(Exercise* exercises, int num_exercises, int workout_duration) {
    int total_calories = 0;
    
    for (int i = 0; i < num_exercises; i++) {
        total_calories += (exercises[i].duration * exercises[i].calories) / 60;
    }
    
    return total_calories * workout_duration;
}

// Function to track a workout
void track_workout(Exercise* exercises, int num_exercises) {
    int workout_duration;
    
    printf("Enter the duration of your workout in minutes: ");
    scanf("%d", &workout_duration);
    
    int total_calories = calculate_calories(exercises, num_exercises, workout_duration);
    
    printf("You burned %d calories during your workout.\n", total_calories);
}

// Main function
int main() {
    Exercise exercises[MAX_EXERCISES];
    int num_exercises = 0;
    
    // Add some exercises
    add_exercise(exercises, num_exercises, "Jogging", 30, 300);
    add_exercise(exercises, num_exercises, "Cycling", 45, 500);
    add_exercise(exercises, num_exercises, "Swimming", 60, 700);
    
    // Display the list of exercises
    display_exercises(exercises, num_exercises);
    
    // Track a workout
    track_workout(exercises, num_exercises);
    
    return 0;
}