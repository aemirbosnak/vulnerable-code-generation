//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void trackWorkout(int*, int*, int*, int*, int*);

int main() {
    int caloriesBurned = 0;
    int stepsTaken = 0;
    int pushupsDone = 0;
    int squatsDone = 0;
    int situpsDone = 0;

    printf("Welcome to your C Fitness Tracker!\n");
    printf("Please enter the following information:\n");
    printf("Number of calories burned during your workout: ");
    scanf("%d", &caloriesBurned);
    printf("Number of steps taken during your workout: ");
    scanf("%d", &stepsTaken);
    printf("Number of pushups done during your workout: ");
    scanf("%d", &pushupsDone);
    printf("Number of squats done during your workout: ");
    scanf("%d", &squatsDone);
    printf("Number of situps done during your workout: ");
    scanf("%d", &situpsDone);

    //passing the user input to the trackWorkout function
    trackWorkout(&caloriesBurned, &stepsTaken, &pushupsDone, &squatsDone, &situpsDone);

    printf("Thank you for using the C Fitness Tracker!\n");

    return 0;
}

void trackWorkout(int* caloriesBurned, int* stepsTaken, int* pushupsDone, int* squatsDone, int* situpsDone) {
    //Calculating the average of all the exercises
    float averageExercise = (*pushupsDone + *squatsDone + *situpsDone) / 3.0;

    printf("\nYour workout summary is as follows:\n");
    printf("Calories Burned: %d\n", *caloriesBurned);
    printf("Steps Taken: %d\n", *stepsTaken);
    printf("Pushups Done: %d\n", *pushupsDone);
    printf("Squats Done: %d\n", *squatsDone);
    printf("Situps Done: %d\n", *situpsDone);
    printf("Your average number of exercise reps: %.2f\n", averageExercise);
    
    //If the user is below the average number of exercise reps, they need to improve
    if(averageExercise < 20) {
        printf("You need to improve your exercise performance!\n");
    }
    else {
        printf("Great job on your workout! Keep up the good work!\n");
    }
}