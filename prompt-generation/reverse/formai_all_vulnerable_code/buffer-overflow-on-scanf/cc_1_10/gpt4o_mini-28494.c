//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>

void addExercise(int *caloriesBurned, int *exerciseCount);
int calculateTotalCalories(int *caloriesBurned, int exerciseCount);
void displayExercises(int *caloriesBurned, int exerciseCount, int index);

int main() {
    int caloriesBurned[100];
    int exerciseCount = 0;

    printf("Welcome to the Fitness Tracker!\n");
    
    addExercise(caloriesBurned, &exerciseCount);

    printf("\nYou entered %d exercises.\n", exerciseCount);
    displayExercises(caloriesBurned, exerciseCount, 0);
    
    int totalCalories = calculateTotalCalories(caloriesBurned, exerciseCount);
    printf("Total Calories Burned: %d\n", totalCalories);
    
    return 0;
}

void addExercise(int *caloriesBurned, int *exerciseCount) {
    int calories;

    printf("Enter calories burned for exercise (or -1 to finish): ");
    scanf("%d", &calories);

    if (calories == -1) {
        return;
    }

    caloriesBurned[*exerciseCount] = calories;
    (*exerciseCount)++;
    
    // Recursive call to add another exercise
    addExercise(caloriesBurned, exerciseCount);
}

int calculateTotalCalories(int *caloriesBurned, int exerciseCount) {
    if (exerciseCount == 0) {
        return 0;
    }
    
    return caloriesBurned[exerciseCount - 1] + calculateTotalCalories(caloriesBurned, exerciseCount - 1);
}

void displayExercises(int *caloriesBurned, int exerciseCount, int index) {
    if (index >= exerciseCount) {
        return;
    }
    
    printf("Exercise %d: %d calories burned\n", index + 1, caloriesBurned[index]);
    
    // Recursive call for the next exercise
    displayExercises(caloriesBurned, exerciseCount, index + 1);
}