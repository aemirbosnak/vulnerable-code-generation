//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void printWelcomeMessage();
void playGame();

int main()
{
    printWelcomeMessage();
    playGame();
    return 0;
}

void printWelcomeMessage()
{
    printf("Welcome to the Cryptic Game!\n");
    printf("You find yourself in a dark and mysterious room.\n");
    printf("There is only one exit, but the door is locked.\n");
    printf("To open the door, you must find the key.\n");
    printf("You have 60 seconds to find the key and escape.\n");
    printf("Good luck!\n");
}

void playGame()
{
    int timeRemaining = 60;

    while (timeRemaining > 0)
    {
        printf("You hear a mysterious voice say: 'The key is hidden somewhere in this room.'\n");
        printf("Do you want to search the room? (y/n): ");
        char input;
        scanf(" %c", &input);

        if (input == 'y')
        {
            printf("You begin searching the room...\n");
            printf("You find a key under a rug!\n");
            printf("You have %d seconds left to escape.\n", timeRemaining);
        }
        else
        {
            printf("You decide to give up and wait for help.\n");
            printf("The room starts shaking and the walls start closing in.\n");
            printf("You have %d seconds left to escape.\n", timeRemaining);
        }

        timeRemaining--;
    }

    if (timeRemaining <= 0)
    {
        printf("Time's up! You failed to escape.\n");
    }
    else
    {
        printf("Congratulations! You escaped in the nick of time!\n");
    }
}