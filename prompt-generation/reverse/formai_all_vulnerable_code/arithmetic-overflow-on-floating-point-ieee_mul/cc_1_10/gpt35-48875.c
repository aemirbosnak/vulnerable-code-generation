//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the user structure
struct User {
    char name[50];
    int age;
    float weight;
    float height;
    float bodyMassIndex;
};

// Define the exercise structure
struct Exercise {
    char name[50];
    int duration;
    float caloriesBurned;
};

// Define the fitness tracker structure
struct FitnessTracker {
    struct User user;
    struct Exercise exercises[5];
    int numExercises;
};

void newUser(struct User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    
    printf("Enter your age: ");
    scanf("%d", &user->age);
    
    printf("Enter your weight (in kgs): ");
    scanf("%f", &user->weight);
    
    printf("Enter your height (in meters): ");
    scanf("%f", &user->height);
}

void displayUser(struct User *user) {
    printf("\n\nUser Details:\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %.2f kgs\n", user->weight);
    printf("Height: %.2f meters\n", user->height);
}

void addExercise(struct FitnessTracker *tracker) {
    if (tracker->numExercises >= 5) {
        printf("You have reached the maximum number of exercises.\n");
        return;
    }
    
    struct Exercise exercise;
    
    printf("Enter exercise name: ");
    scanf("%s", exercise.name);
    
    printf("Enter exercise duration (in minutes): ");
    scanf("%d", &exercise.duration);
    
    exercise.caloriesBurned = (exercise.duration / 30.0) * 250.0;
    
    tracker->exercises[tracker->numExercises++] = exercise;
    
    printf("Exercise has been added to your tracker.\n");
}

void displayExercises(struct FitnessTracker *tracker) {
    printf("\n\nExercises:\n");
    
    for (int i = 0; i < tracker->numExercises; i++) {
        struct Exercise *exercise = &tracker->exercises[i];
        printf("Name: %s\n", exercise->name);
        printf("Duration: %d minutes\n", exercise->duration);
        printf("Calories Burned: %.2f\n", exercise->caloriesBurned);
    }
}

void calculateBMI(struct FitnessTracker *tracker) {
    float heightSquared = tracker->user.height * tracker->user.height;
    tracker->user.bodyMassIndex = tracker->user.weight / heightSquared;
    
    printf("\n\nBMI Calculation:\n");
    printf("Your BMI is %.2f\n", tracker->user.bodyMassIndex);
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to Fitness Tracker!\n");
    
    struct FitnessTracker *tracker_a, *tracker_b;
    tracker_a = (struct FitnessTracker*) malloc(sizeof(struct FitnessTracker));
    tracker_b = (struct FitnessTracker*) malloc(sizeof(struct FitnessTracker));
    
    printf("\n\nPLAYER A\n\n");
    newUser(&tracker_a->user);
    displayUser(&tracker_a->user);
    addExercise(tracker_a);
    addExercise(tracker_a);
    calculateBMI(tracker_a);
    
    printf("\n\nPLAYER B\n\n");
    newUser(&tracker_b->user);
    displayUser(&tracker_b->user);
    addExercise(tracker_b);
    addExercise(tracker_b);
    calculateBMI(tracker_b);
    
    displayExercises(tracker_a);
    displayExercises(tracker_b);
    
    free(tracker_a);
    free(tracker_b);
    
    return 0;
}