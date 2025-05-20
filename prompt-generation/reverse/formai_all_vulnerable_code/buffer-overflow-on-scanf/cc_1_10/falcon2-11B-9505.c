//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

int main(int argc, char **argv)
{
    // Initialize variables
    int calories = 0;
    double total_time = 0.0;
    double step_count = 0;

    // Get user input for activity type
    printf("Welcome to the Fitness Tracker!\n");
    printf("What activity did you do? (running, walking, cycling, etc.): ");
    char activity[50];
    scanf("%s", activity);

    // Get user input for duration and steps
    printf("How long did you %s for? (in minutes): ", activity);
    scanf("%d", &total_time);
    printf("How many steps did you take? ");
    scanf("%d", &step_count);

    // Calculate calories burned based on activity type and duration
    switch (strlen(activity))
    {
        case 1:
            calories = (total_time * 10) * (int) (step_count * 0.1);
            break;
        case 2:
            calories = (total_time * 10) * (int) (step_count * 0.2);
            break;
        case 3:
            calories = (total_time * 10) * (int) (step_count * 0.3);
            break;
        case 4:
            calories = (total_time * 10) * (int) (step_count * 0.4);
            break;
        case 5:
            calories = (total_time * 10) * (int) (step_count * 0.5);
            break;
        case 6:
            calories = (total_time * 10) * (int) (step_count * 0.6);
            break;
        case 7:
            calories = (total_time * 10) * (int) (step_count * 0.7);
            break;
        case 8:
            calories = (total_time * 10) * (int) (step_count * 0.8);
            break;
        case 9:
            calories = (total_time * 10) * (int) (step_count * 0.9);
            break;
        default:
            calories = 0;
            break;
    }

    // Calculate time spent on activity
    double time_spent = total_time / 60.0;

    // Print results
    printf("You burned %d calories in %d minutes!\n", calories, total_time);
    printf("That's equivalent to %d minutes of running!\n", time_spent);
    printf("You took %d steps, which is equivalent to %d miles!\n", step_count, (double) step_count / 2000.0);

    return 0;
}