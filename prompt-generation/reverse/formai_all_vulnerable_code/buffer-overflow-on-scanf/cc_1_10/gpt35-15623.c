//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Hello, %s!\n", name);

    // Initializing the random number generator
    srand(time(NULL));

    // Generating a random number
    int fortune_number = rand() % 5;
    printf("\n");

    // Checking the fortune number and displaying the fortune
    switch(fortune_number)
    {
        case 0:
            printf("Oh dear! I'm shocked to see that your fortune is really bad.\n");
            printf("You are going to face a lot of problems in the coming days.\n");
            printf("But don't worry, things will eventually get better...\n");
            break;
        case 1:
            printf("Wow! This is shocking! Your fortune is off the charts!\n");
            printf("You are going to achieve incredible success in everything you do!\n");
            printf("Remember to stay humble and give back to those in need.\n");
            break;
        case 2:
            printf("Oh my god! Your fortune is really confusing...\n");
            printf("It's telling me that you will face both good and bad experiences in your life.\n");
            printf("But it's up to you to make the most of what you have and come out on top!\n");
            break;
        case 3:
            printf("This is surprising... Your fortune reveals that you will travel to faraway lands.\n");
            printf("Perhaps this is the perfect time for a vacation? Keep your passport ready!\n");
            break;
        case 4:
            printf("What?! This is unbelievable! Your fortune is telling me that you have a secret admirer!\n");
            printf("Who could it possibly be? Keep your eyes peeled for signs of affection...\n");
            break;
        default:
            printf("Oops! Something went wrong and I couldn't read your fortune...\n");
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");
    return 0;
}