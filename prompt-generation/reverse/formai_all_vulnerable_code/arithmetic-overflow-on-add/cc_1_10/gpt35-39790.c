//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate the time difference
void calculateTimeDifference(int h1, int m1, int h2, int m2, int *diffH, int *diffM)
{
    int totalMinutes1 = h1 * 60 + m1;
    int totalMinutes2 = h2 * 60 + m2;
    int diffMinutes = totalMinutes2 - totalMinutes1;
    *diffH = diffMinutes / 60;
    *diffM = diffMinutes % 60;
}

int main()
{
    printf("<== Welcome to the Time Travel Simulator ==>\n\n");
    printf("You are about to embark on a journey through time...\n\n");
    printf("Enter the current time in 24-hour format (HH:MM): ");
    
    int currentH, currentM;
    scanf("%d:%d", &currentH, &currentM);
    
    printf("\nEnter the time you wish to travel to (HH:MM): ");
    
    int travelH, travelM;
    scanf("%d:%d", &travelH, &travelM);
    
    printf("\n\nCalculating time difference...\n\n");
    
    int diffH, diffM;
    calculateTimeDifference(currentH, currentM, travelH, travelM, &diffH, &diffM);
    
    printf("The time difference is: %d hour(s) and %d minute(s).\n\n", diffH, diffM);
    printf("You are about to travel %d hour(s) and %d minute(s) ", abs(diffH), abs(diffM));
    
    if (diffH < 0 || (diffH == 0 && diffM < 0))
    {
        printf("to the past!\n\n");
    }
    else if (diffH > 0 || (diffH == 0 && diffM > 0))
    {
        printf("to the future!\n\n");
    }
    else
    {
        printf("in time but in the same place.\n\n");
        printf("Are you sure you want to proceed? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
        {
            printf("\n\nTime travel cancelled.\n\n");
            return 0;
        }
    }
    
    printf("\n\nPreparing time travel...\n\n");
    printf("Charging time flux capacitor...\n");
    printf("Programming time coordinates...\n");
    printf("Engaging temporal displacement drive...\n\n");
    
    // delay to simulate time travel
    int delay = abs(diffH) * 60 + abs(diffM);
    for (int i = 0; i < delay; i++)
    {
        printf("Moving through time...%d / %d\n", i+1, delay);
        if (i % 10 == 0) // random glitch effect
        {
            printf("==> ERROR: Temporal interference detected. ");
            printf("System malfunction in %d seconds...\n", rand()%delay);
        }
        srand(time(NULL) + i); // random seed
        int mysteryNo = rand()%100;
        if (mysteryNo == 42) // random easter egg
        {
            printf("\n\n===> Congratulations! You have unlocked the 42 easter egg! <===\n\n");
            break;
        }
        if (i == delay-1) // final jump
        {
            printf("\n\nTime travel complete!\n\n");
            printf("You have arrived at %02d:%02d.\n\n", travelH, travelM);
        }
    }
    
    return 0;
}