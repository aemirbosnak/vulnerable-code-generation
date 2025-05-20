//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
/* 
   This is a C Fitness Tracker example program which will help you track your daily fitness activities.
   It will ask the user to set his/her daily goal for various activities.
   The user will enter the amount of time he/she spends on various activities.
   The program will calculate total time spent on each activity and compare it with the daily goals set by user.
   The program will then display the progress report for each activity.
*/

#include <stdio.h>
#include <string.h>

// Function to calculate progress percentage
float calculateProgress(float current, float goal)
{
    float progress = (current / goal) * 100;
    return progress;
}

int main()
{
    // Arrays to store activity names and daily goals
    char activities[5][20] = {"Running", "Walking", "Swimming", "Cycling", "Weight Lifting"};
    int goals[5];
    
    // Ask user to set daily goals for each activity
    for (int i = 0; i < 5; i++)
    {
        printf("Enter your daily goal (in minutes) for %s: ", activities[i]);
        scanf("%d", &goals[i]);
    }
    
    // Arrays to store time spent on each activity
    int timespent[5];
    
    // Ask user to input time spent on each activity
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the time spent on %s (in minutes): ", activities[i]);
        scanf("%d", &timespent[i]);
    }
    
    printf("\n************ Progress Report ************\n");
    
    // Display progress report for each activity
    for (int i = 0; i < 5; i++)
    {
        printf("%s: %d minutes out of %d minutes. ", activities[i], timespent[i], goals[i]);
        float progress = calculateProgress(timespent[i], goals[i]);
        printf("Progress: %.2f%%\n", progress);
    }
    
    // Calculate total time spent on all activities
    int total_time = 0;
    for (int i = 0; i < 5; i++)
    {
        total_time += timespent[i];
    }
    
    // Calculate total daily goal
    int total_goal = 0;
    for (int i = 0; i < 5; i++)
    {
        total_goal += goals[i];
    }
    
    // Display overall progress report
    printf("\nOverall Progress: %d minutes out of %d minutes. ", total_time, total_goal);
    float overall_progress = calculateProgress(total_time, total_goal);
    printf("Overall Progress: %.2f%%", overall_progress);
    
    return 0;
}