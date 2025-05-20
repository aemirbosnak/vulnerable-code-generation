//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void roomOne();
void roomTwo();
void roomThree();
void endGame();

int main()
{
    printf("Welcome to Adventure Game!\n");
    roomOne();
    return 0;
}

void roomOne()
{
    char input[20];
    printf("\nYou are in room 1. There is a door in front of you.\n");
    printf("What do you do? (type 'open door' or 'look around')\n");
    scanf("%s", input);

    if (strcmp(input, "open") == 0)
    {
        printf("The door is locked. You need to find the key.\n");
        roomOne();
    }
    else if (strcmp(input, "look") == 0)
    {
        printf("You find a key hidden under a rock.\n");
        roomTwo();
    }
    else
    {
        printf("I don't understand.\n");
        roomOne();
    }
}

void roomTwo()
{
    char input[20];
    printf("\nYou are in room 2. There are two doors: one red, one blue.\n");
    printf("Which do you choose? (type 'red door' or 'blue door')\n");
    scanf("%s", input);

    if (strcmp(input, "red") == 0)
    {
        printf("You find a treasure chest full of gold. Congratulations, you win!\n");
        endGame();
    }
    else if (strcmp(input, "blue") == 0)
    {
        printf("You fall into a pit of spiders and die.\n");
        endGame();
    }
    else
    {
        printf("I don't understand.\n");
        roomTwo();
    }
}

void endGame()
{
    printf("\nGame Over.\n");
    printf("Thank you for playing Adventure Game!\n");
}