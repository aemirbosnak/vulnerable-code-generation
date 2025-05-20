//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int age, weight, height, steps, heartRate;

    printf("Welcome to the Baker Street Fitness Tracker!\n");
    printf("Please provide your name: ");
    scanf("%s", name);

    printf("Please provide your age: ");
    scanf("%d", &age);

    printf("Please provide your weight (in kilograms): ");
    scanf("%d", &weight);

    printf("Please provide your height (in centimeters): ");
    scanf("%d", &height);

    steps = stepsTaken(height, weight);
    heartRate = calculateHeartRate(age);

    printf("Well, Mr./Ms. %s, your fitness score is as follows:\n", name);
    printf("Number of steps taken: %d\n", steps);
    printf("Heart rate: %d beats per minute\n", heartRate);

    if (heartRate < 60)
    {
        printf("Your heart rate is considered low. You may need to consult a doctor.\n");
    }
    else if (heartRate >= 60 && heartRate < 70)
    {
        printf("Your heart rate is within the normal range. Keep up the good work!\n");
    }
    else
    {
        printf("Your heart rate is considered high. You should consult a doctor.\n");
    }

    return 0;
}

int stepsTaken(int height, int weight)
{
    return (height * 2) + (weight * 3);
}

int calculateHeartRate(int age)
{
    return 220 - (age * 2);
}