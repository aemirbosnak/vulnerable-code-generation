//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1024

int main()
{
    char str[MAX_CHAR];
    int i = 0, num_steps = 0, total_calories = 0, step_count = 0;
    char activity_type[MAX_CHAR];

    printf("Welcome to the Baker Street Fitness Tracker!\n");

    // Gather user input
    printf("Please describe your activity: ");
    scanf("%s", str);

    // Analyze the activity type
    if (strstr(str, "walking") != NULL)
    {
        strcpy(activity_type, "Walking");
        num_steps = 10000;
        total_calories = 600;
    }
    else if (strstr(str, "running") != NULL)
    {
        strcpy(activity_type, "Running");
        num_steps = 12000;
        total_calories = 800;
    }
    else if (strstr(str, "cycling") != NULL)
    {
        strcpy(activity_type, "Cycling");
        num_steps = 8000;
        total_calories = 500;
    }
    else
    {
        printf("Invalid activity type.\n");
        return 1;
    }

    // Calculate step count and total calories
    step_count = num_steps * 2;
    total_calories = total_calories * step_count;

    // Print results
    printf("Your activity type is: %s\n", activity_type);
    printf("Number of steps taken: %d\n", num_steps);
    printf("Total calories burned: %d\n", total_calories);

    return 0;
}