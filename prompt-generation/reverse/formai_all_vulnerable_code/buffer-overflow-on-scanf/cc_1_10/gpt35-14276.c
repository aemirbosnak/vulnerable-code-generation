//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>

// function to calculate the total time spent on exercise
int calculateTotalTime(int numExercises, int exerciseTime[]) {
    if (numExercises == 0) {
        return 0;
    }
    else {
        return exerciseTime[numExercises-1] + calculateTotalTime(numExercises-1, exerciseTime);
    }
}

// function to calculate the total calories burned based on the exercise
int calculateCaloriesBurned(int numExercises, int exerciseCalories[], int index) {
    if (index == numExercises) {
        return 0;
    }
    else {
        return exerciseCalories[index] + calculateCaloriesBurned(numExercises, exerciseCalories, index+1);
    }
}

// function to get the max calories burned during an exercise session
int getMaxCaloriesBurned(int numExercises, int exerciseCalories[], int maxCalories, int index) {
    if (index == numExercises) {
        return maxCalories;
    }
    else {
        if (exerciseCalories[index] > maxCalories) {
            maxCalories = exerciseCalories[index];
        }
        return getMaxCaloriesBurned(numExercises, exerciseCalories, maxCalories, index+1);
    }
}

int main() {
    int numExercises;
    printf("How many exercises did you do today? ");
    scanf("%d", &numExercises);

    int exerciseTime[numExercises];
    int exerciseCalories[numExercises];

    // getting the exercise time and calories burned for each exercise
    for (int i = 0; i < numExercises; i++) {
        printf("Enter the time spent on exercise %d (in minutes): ", i+1);
        scanf("%d", &exerciseTime[i]);
        printf("Enter the calories burned during exercise %d: ", i+1);
        scanf("%d", &exerciseCalories[i]);
    }

    int totalTime = calculateTotalTime(numExercises, exerciseTime);
    int totalCalories = calculateCaloriesBurned(numExercises, exerciseCalories, 0);
    int maxCaloriesBurned = getMaxCaloriesBurned(numExercises, exerciseCalories, 0, 0);

    printf("Total time spent on exercise: %d minutes\n", totalTime);
    printf("Total calories burned: %d\n", totalCalories);
    printf("Max calories burned during an exercise session: %d\n", maxCaloriesBurned);

    return 0;
}