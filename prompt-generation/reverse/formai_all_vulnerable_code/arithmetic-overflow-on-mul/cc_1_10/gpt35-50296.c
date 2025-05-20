//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>

// Function to calculate calories burned based on activity and duration
int calculateCalories(char activity, int duration) {
    int calories = 0;
    switch(activity) {
        case 'C':
            calories = duration * 10;
            break;
        case 'J':
            calories = duration * 8;
            break;
        case 'W':
            calories = duration * 6;
            break;
        default:
            printf("Invalid activity!");
    }
    return calories;
}

int main() {
    char activity;
    int duration;
    int totalCalories = 0;
    int maxDuration = 0;
    char maxActivity;

    // Loop to keep track of multiple activities
    while(1) {
        printf("Enter activity (C for cycling, J for jogging, W for walking): ");
        scanf(" %c", &activity);
        if(activity == 'q' || activity == 'Q') {
            break;
        }
        printf("Enter duration (in minutes): ");
        scanf("%d", &duration);

        // Calculate and display calories burned for each activity
        printf("You burned %d calories.\n", calculateCalories(activity, duration));
        totalCalories += calculateCalories(activity, duration);

        // Keep track of activity with highest duration
        if(duration > maxDuration) {
            maxDuration = duration;
            maxActivity = activity;
        }
    }

    // Display total calories burned and activity with highest duration
    printf("You burned a total of %d calories.\n", totalCalories);
    printf("%c had the highest duration of %d minutes.\n", maxActivity, maxDuration);

    return 0;
}