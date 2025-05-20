//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    // initialize variables
    int totalWorkouts = 0;  // total number of workouts completed
    int totalExercises = 0;  // total number of exercises completed
    int totalReps = 0;  // total number of repetitions completed
    int totalWeight = 0;  // total weight lifted
    int maxWeight = 0;  // maximum weight lifted in a single exercise
    int minWeight = 100;  // minimum weight lifted in a single exercise, initialized to 100 as a placeholder
    
    char answer;  // holds user input for whether to continue tracking workouts
    
    // initialize random seed
    srand(time(NULL));
    
    // loop until user chooses to stop tracking workouts
    while (true) {
        // prompt user for today's workout information
        int exercises = rand() % 6 + 1;  // random number of exercises completed between 1 and 6
        int reps = rand() % 10 + 1;  // random number of repetitions completed between 1 and 10
        int weight = rand() % 100 + 1;  // random weight lifted between 1 and 100
        
        // calculate workout information
        totalExercises += exercises;
        totalReps += reps * exercises;
        totalWeight += weight * reps * exercises;
        if (weight > maxWeight) {
            maxWeight = weight;
        }
        if (weight < minWeight) {
            minWeight = weight;
        }
        
        // increment total workouts
        totalWorkouts++;
        
        // ask user if they want to continue tracking workouts
        printf("Do you want to continue tracking workouts? (y/n) ");
        scanf(" %c", &answer);
        
        if (answer != 'y') {
            // print workout statistics
            printf("Total Workouts: %d\n", totalWorkouts);
            printf("Total Exercises: %d\n", totalExercises);
            printf("Total Reps: %d\n", totalReps);
            printf("Total Weight Lifted: %d\n", totalWeight);
            printf("Max Weight Lifted: %d\n", maxWeight);
            printf("Min Weight Lifted: %d\n", minWeight);
            
            return 0;
        }
    }
}