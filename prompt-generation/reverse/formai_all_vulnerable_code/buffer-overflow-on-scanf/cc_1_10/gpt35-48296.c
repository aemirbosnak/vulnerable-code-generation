//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FitnessTracker {
    char name[50]; // name of exercise
    int caloriesBurned; // calories burned during exercise
    int minutes; // duration of exercise in minutes
};

int main() {
    int numExercises;
    struct FitnessTracker *exercises; // pointer to array of exercises
    
    printf("How many exercises did you do today?\n");
    scanf("%d", &numExercises);
    
    exercises = (struct FitnessTracker*) malloc(numExercises * sizeof(struct FitnessTracker)); // allocate memory
    
    for(int i = 0; i < numExercises; i++) {
        printf("Enter the name of exercise %d: ", i+1);
        scanf("%s", exercises[i].name);
        printf("Enter calories burned during exercise %d: ", i+1);
        scanf("%d", &exercises[i].caloriesBurned);
        printf("Enter duration of exercise %d in minutes: ", i+1);
        scanf("%d", &exercises[i].minutes);
    }
    
    // print out summary of exercises
    printf("\n\nExercise Summary\n");
    printf("=============================\n");
    printf("Exercise\tCalories Burned\tTime (min)\n");
    printf("=============================\n");
    for(int i = 0; i < numExercises; i++) {
        printf("%s\t%d\t\t%d\n", exercises[i].name, exercises[i].caloriesBurned, exercises[i].minutes);
    }
    
    // calculate total calories burned
    int totalCalories = 0;
    for(int i = 0; i < numExercises; i++) {
        totalCalories += exercises[i].caloriesBurned;
    }
    
    // calculate total time
    int totalTime = 0;
    for(int i = 0; i < numExercises; i++) {
        totalTime += exercises[i].minutes;
    }
    
    // print out totals
    printf("\n\nTotal Calories Burned: %d\n", totalCalories);
    printf("Total Time: %d minutes\n", totalTime);
    
    free(exercises); // free memory
    
    return 0;
}