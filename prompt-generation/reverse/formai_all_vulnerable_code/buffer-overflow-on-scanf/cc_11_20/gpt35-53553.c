//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Initialization of variables
    int present_year, target_year, i, j, travel_year, presents_count, target_count;
    char name[50], gender[10], present[100], target[100];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    present_year = tm.tm_year + 1900;

    // Introduction and input section
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("What is your name?\n");
    fgets(name, 50, stdin);
    printf("\nHello, %s! What is your gender? (male/female)\n", name);
    fgets(gender, 10, stdin);
    printf("\nAlright %s, so where are you right now?\n", name);
    fgets(present, 100, stdin);
    printf("\nInteresting! And where do you want to go?\n");
    fgets(target, 100, stdin);
    printf("\nGreat! Now, in what year do you want to travel to?\n");
    scanf("%d", &travel_year);

    // Output section
    printf("\nLet's see... %s wants to travel from %s to %s in the year %d...\n\n", name, present, target, travel_year);
    printf("Initializing Time Travel...\n");
    printf("3... 2... 1... BZZZZT!!!\n\n");

    // Time travel simulation
    for (i = present_year; i <= travel_year; i++)
    {
        printf("Traveling through time... Currently in the year %d!\n", i);
    }

    printf("\nArrived at destination! You are now in the year %d in %s!\n\n", travel_year, target);

    // Random gift generator
    printf("To celebrate your journey, we have prepared a special gift for you!\n");
    printf("How many gifts would you like to receive? (maximum of 10)\n");
    scanf("%d", &presents_count);

    if (presents_count > 10)
    {
        presents_count = 10;
        printf("\nSorry, the maximum number of gifts is 10. You will receive 10 gifts!\n\n");
    }

    printf("\nCongratulations! You have received the following gifts:\n");

    for (j = 0; j < presents_count; j++)
    {
        int gift = rand() % 5;

        switch (gift)
        {
        case 0:
            printf("- A vintage camera\n");
            break;
        case 1:
            printf("- A rare book\n");
            break;
        case 2:
            printf("- A mysterious key\n");
            break;
        case 3:
            printf("- A notebook filled with coded messages\n");
            break;
        case 4:
            printf("- A map to a treasure\n");
            break;
        }

        target_count = presents_count - j - 1;

        if (target_count == 1)
        {
            printf("\nYou have %d more gift waiting for you!\n", target_count);
        }
        else if (target_count > 1)
        {
            printf("\nYou have %d more gifts waiting for you!\n", target_count);
        }
    }

    printf("\nThank you for using the Time Travel Simulator! We hope you have enjoyed your journey!\n");

    return 0;
}