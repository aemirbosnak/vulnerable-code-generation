//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int seconds);
void printWelcomeScreen();
void gameLoop();

int main()
{
    srand(time(NULL));
    printWelcomeScreen();
    gameLoop();

    return 0;
}

void delay(int seconds)
{
    int milliseconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds)
    {
    }
}

void printWelcomeScreen()
{
    printf("Welcome to the Haunted House Simulator!\n");
    delay(1);
    printf("You have been dared to spend a night in this haunted house...\n");
    delay(2);
    printf("The rules are simple: survive until 6am and you win.\n");
    printf("But be careful, there are all sorts of scary things lurking inside...\n");
    delay(2);
    printf("Press any key to continue.");
    getchar();
}

void gameLoop()
{
    int isPlaying = 1;
    int hour = 7;
    int isGhostVisible = 0;
    int isMonsterVisible = 0;
    int isRatVisible = 0;
    int randomEvent;

    while (isPlaying)
    {
        printf("Hour: %d\n", hour);

        if (hour > 22 && hour < 6)
        {
            isGhostVisible = 1;
        }

        if (hour > 20 && hour < 23)
        {
            isMonsterVisible = 1;
        }

        if (hour > 1 && hour < 4)
        {
            isRatVisible = 1;
        }

        randomEvent = rand() % 10;

        switch (randomEvent)
        {
        case 0:
            printf("You hear a loud creaking noise from upstairs.\n");
            break;
        case 1:
            printf("You see a pair of red eyes staring at you from the darkness.\n");
            break;
        case 2:
            printf("You smell something rotting and disgusting.\n");
            break;
        case 3:
            printf("You hear something scratching at the walls.\n");
            break;
        case 4:
            printf("You feel a cold breeze blowing through the room.\n");
            break;
        case 5:
            if (isGhostVisible)
            {
                printf("You see a ghostly figure appear before you!\n");
            }
            break;
        case 6:
            printf("You hear the sound of a woman weeping in the distance.\n");
            break;
        case 7:
            printf("You stumble and fall as something unseen trips you.\n");
            break;
        case 8:
            if (isMonsterVisible)
            {
                printf("You see a huge monster standing right in front of you!\n");
            }
            break;
        case 9:
            if (isRatVisible)
            {
                printf("You see a bunch of rats scurrying across the floor.\n");
            }
            break;
        }

        if (isGhostVisible || isMonsterVisible || isRatVisible)
        {
            printf("You are attacked and you have lost the game...");
            isPlaying = 0;
            continue;
        }

        if (hour >= 6)
        {
            printf("Congratulations! You have survived until 6am and have won the game!\n");
            isPlaying = 0;
        }

        hour++;
        delay(1);
    }
}