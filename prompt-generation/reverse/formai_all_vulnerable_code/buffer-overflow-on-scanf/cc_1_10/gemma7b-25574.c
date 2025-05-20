//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beep(int duration)
{
    for (int i = 0; i < duration; i++)
    {
        printf("\a");
    }
}

int main()
{
    int heartRate = 0;
    int stepsTaken = 0;
    char mood = 'A';

    printf("Welcome to the C Fitness Tracker!\n");

    // Get the user's heart rate.
    printf("Please enter your current heart rate: ");
    scanf("%d", &heartRate);

    // Get the user's number of steps taken.
    printf("Please enter the number of steps you have taken: ");
    scanf("%d", &stepsTaken);

    // Calculate the user's mood.
    if (heartRate > 120)
    {
        mood = 'H';
    }
    else if (heartRate > 80)
    {
        mood = 'M';
    }
    else if (heartRate > 60)
    {
        mood = 'A';
    }
    else
    {
        mood = 'G';
    }

    // Print the user's mood.
    printf("Your mood is: %c\n", mood);

    // Beep for 2 seconds.
    beep(2);

    // End of program.
    return 0;
}