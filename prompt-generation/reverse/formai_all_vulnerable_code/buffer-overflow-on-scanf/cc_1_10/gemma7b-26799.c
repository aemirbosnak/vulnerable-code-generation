//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    system("clear");
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    system("clear");
    printf("Welcome, %s! Let's see what you can do:\n", name);

    int choice;
    printf("1. Track your heart rate\n");
    printf("2. Count your steps\n");
    printf("3. Measure your blood pressure\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("clear");
            printf("Okay, %s, I'm going to take your heart rate.\n", name);
            sleep(2);
            printf("Your heart rate is 70 beats per minute.\n");
            break;

        case 2:
            system("clear");
            printf("Alright, %s, let's count your steps.\n", name);
            sleep(2);
            printf("You took 10,000 steps today.\n");
            break;

        case 3:
            system("clear");
            printf("Sure, %s, I'm going to measure your blood pressure.\n", name);
            sleep(2);
            printf("Your blood pressure is 120/80 mmHg.\n");
            break;

        default:
            system("clear");
            printf("Invalid choice, %s. Please try again.\n", name);
            break;
    }

    system("clear");
    printf("Thank you for using the C Fitness Tracker, %s. See you next time!\n", name);

    return 0;
}