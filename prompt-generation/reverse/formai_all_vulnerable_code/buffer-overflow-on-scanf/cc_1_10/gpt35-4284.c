//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Exercise {
    char type[20];
    int duration; //in minutes
    float caloriesBurned;
};

struct FitnessTracker {
    char name[50];
    int age;
    float height; //in meters
    float weight; //in kilograms
    int numExercises; //number of exercises added to tracker
    struct Exercise exercises[10]; //maximum of 10 exercises per tracker
};

void addExercise(struct FitnessTracker *tracker) { //function to add exercise to tracker
    if (tracker->numExercises == 10) { //if tracker already has 10 exercises added
        printf("Maximum exercises reached.\n");
        return;
    }
    struct Exercise exercise;
    printf("Type of exercise: ");
    scanf("%s", exercise.type);
    printf("Duration (in minutes): ");
    scanf("%d", &exercise.duration);
    printf("Calories burned: ");
    scanf("%f", &exercise.caloriesBurned);
    tracker->exercises[tracker->numExercises] = exercise; //add exercise to tracker
    tracker->numExercises++;
    printf("Exercise added successfully!\n");
}

void displayTracker(struct FitnessTracker tracker) { //function to display tracker information
    printf("Name: %s\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Height: %.2fm\n", tracker.height);
    printf("Weight: %.2fkg\n", tracker.weight);
    printf("Number of exercises: %d\n", tracker.numExercises);
    if (tracker.numExercises > 0) { //if tracker has exercises added
        printf("Exercises:\n");
        for (int i = 0; i < tracker.numExercises; i++) {
            printf("- %s for %d minutes, burned %.2f calories\n", tracker.exercises[i].type, tracker.exercises[i].duration, tracker.exercises[i].caloriesBurned);
        }
    }
}

int main() {
    struct FitnessTracker tracker;
    printf("Enter your name: ");
    scanf("%s", tracker.name);
    printf("Enter your age: ");
    scanf("%d", &tracker.age);
    printf("Enter your height (in meters): ");
    scanf("%f", &tracker.height);
    printf("Enter your weight (in kilograms): ");
    scanf("%f", &tracker.weight);
    tracker.numExercises = 0; //initialize numExercises to 0
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add exercise\n");
        printf("2. View tracker\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                displayTracker(tracker);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}