//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with system time
    int year = rand() % 1001 + 1000; // generate a random year between 1000 and 2000

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("You have been transported back in time to the year %d.\n\n", year);

    printf("What would you like to do?\n");
    printf("1. Visit the king\n");
    printf("2. Explore the village\n");
    printf("3. Investigate the castle\n");
    printf("4. Attend a jousting tournament\n");
    printf("5. Return to the present\n");

    int choice;
    scanf("%d", &choice); // get user's choice

    switch(choice)
    {
        case 1:
            printf("\nYou walk up to the castle gates and are admitted into the king's court.\n");
            printf("The king notices you and asks who you are and where you come from.\n");
            printf("What do you say to the king?\n");
            char response[100];
            scanf("%[^\n]", response); // get user's response
            printf("\nThe king is impressed by your response and invites you to a feast in your honor.\n");
            break;
        case 2:
            printf("\nAs you walk around the village, you see a blacksmith hard at work.\n");
            printf("He notices you and invites you into his shop.\n");
            printf("What do you want to do?\n");
            printf("1. Watch the blacksmith work\n");
            printf("2. Buy something from the blacksmith\n");
            int shopChoice;
            scanf("%d", &shopChoice); // get user's choice
            if(shopChoice == 1)
            {
                printf("\nYou watch the blacksmith hammer a red-hot piece of metal into a sword.\n");
            }
            else if(shopChoice == 2)
            {
                printf("\nWhat do you want to buy?\n");
                printf("1. Sword\n");
                printf("2. Shield\n");
                int itemChoice;
                scanf("%d", &itemChoice); // get user's choice
                if(itemChoice == 1)
                {
                    printf("\nThe blacksmith hands you a shiny new sword.\n");
                }
                else if(itemChoice == 2)
                {
                    printf("\nThe blacksmith hands you a sturdy new shield.\n");
                }
            }
            break;
        case 3:
            printf("\nYou sneak into the castle and start exploring.\n");
            printf("As you turn a corner, you run into a guard.\n");
            printf("What do you do?\n");
            printf("1. Fight the guard\n");
            printf("2. Try to bribe the guard\n");
            int guardChoice;
            scanf("%d", &guardChoice); // get user's choice
            if(guardChoice == 1)
            {
                printf("\nYou draw your sword and engage the guard in battle.\n");
                printf("After a fierce fight, you emerge victorious.\n");
            }
            else if(guardChoice == 2)
            {
                printf("\nYou offer the guard some gold to let you go.\n");
                printf("The guard accepts your bribe and lets you continue.\n");
            }
            printf("\nAs you explore further, you find a secret passage leading to the king's treasury.\n");
            printf("Do you want to take some treasure?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int treasureChoice;
            scanf("%d", &treasureChoice); // get user's choice
            if(treasureChoice == 1)
            {
                printf("\nYou take a bag of gold coins and slip back out of the castle unnoticed.\n");
            }
            else if(treasureChoice == 2)
            {
                printf("\nYou decide not to risk it and leave the treasury untouched.\n");
            }
            break;
        case 4:
            printf("\nYou attend a jousting tournament and cheer on your favorite knight.\n");
            printf("After an exciting match, your knight emerges victorious.\n");
            printf("As a reward, the knight invites you to a banquet in his honor.\n");
            break;
        case 5:
            printf("\nYou press the button on your time machine and are transported back to the present.\n");
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }

    return 0;
}