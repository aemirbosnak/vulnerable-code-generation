//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numDays;
    float weight;
    int totalWorkouts = 0;
    float totalCaloriesBurned = 0.0f;
    float totalMilesRan = 0.0f;
    float avgCaloriesBurnedPerWorkout = 0.0f;
    float avgMilesRanPerWorkout = 0.0f;
    int i;

    printf("Enter the number of days you worked out this week: ");
    scanf("%d", &numDays);

    // Loop through each day and get workout data
    for (i = 1; i <= numDays; i++)
    {
        printf("\nDAY %d\n", i);

        // Get weight input
        printf("Enter your weight: ");
        scanf("%f", &weight);

        // Get workout input
        int numWorkouts;
        printf("How many workouts did you do today? ");
        scanf("%d", &numWorkouts);

        // Loop through each workout and get data
        int j;
        for (j = 1; j <= numWorkouts; j++)
        {
            printf("WORKOUT %d\n", j);

            // Get calories burned input
            float caloriesBurned;
            printf("How many calories did you burn during this workout? ");
            scanf("%f", &caloriesBurned);

            // Get miles ran input
            float milesRan;
            printf("How many miles did you run during this workout? ");
            scanf("%f", &milesRan);

            // Update totals
            totalCaloriesBurned += caloriesBurned;
            totalMilesRan += milesRan;
            totalWorkouts++;

            // Calculate averages
            avgCaloriesBurnedPerWorkout = totalCaloriesBurned / totalWorkouts;
            avgMilesRanPerWorkout = totalMilesRan / totalWorkouts;
        }
    }

    printf("\nSUMMARY\n");
    printf("Total Workouts: %d\n", totalWorkouts);
    printf("Total Calories Burned: %.2f\n", totalCaloriesBurned);
    printf("Total Miles Ran: %.2f\n", totalMilesRan);
    printf("Average Calories Burned per Workout: %.2f\n", avgCaloriesBurnedPerWorkout);
    printf("Average Miles Ran per Workout: %.2f\n", avgMilesRanPerWorkout);

    return 0;
}