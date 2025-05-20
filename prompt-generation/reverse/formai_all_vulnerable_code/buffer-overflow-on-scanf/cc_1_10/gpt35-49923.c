//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int score = 0;
int room = 1;

void initializeGame();
void playGame();
void roomOne();
void roomTwo();
void roomThree();

int main()
{
    initializeGame();
    playGame();
    return 0;
}

void initializeGame()
{
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark room, with no memory of how you got there.\n");
    printf("Your objective is to escape the room and find your way back to safety.\n\n");
    printf("Instructions:\n");
    printf("Enter 'north' to move north, 'south' to move south, 'east' to move east, 'west' to move west.\n");
    printf("Enter 'take *item name*' to pick up the specified item.\n");
    printf("Enter 'use *item name*' to use the specified item.\n");
    printf("Enter 'help' to display these instructions again.\n");
}

void playGame()
{
    while(room != 0)
    {
        switch(room)
        {
            case 1:
                roomOne();
                break;
            case 2:
                roomTwo();
                break;
            case 3:
                roomThree();
                break;
            default:
                printf("Invalid room. The game will now exit.\n");
                room = 0;
                break;
        }
    }
}

void roomOne()
{
    char input[50];
    printf("You are in a small room. There is a door to the north. \n");
    printf("What would you like to do?\n");
    scanf("%s", &input);
    
    if(strcmp(input, "north") == 0)
    {
        printf("You open the door and enter the next room.\n");
        room = 2;
    }
    else if(strcmp(input, "help") == 0)
    {
        initializeGame();
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}

void roomTwo()
{
    char input[50];
    printf("You are in a large hallway. There are doors to the north, east, and west. \n");
    printf("What would you like to do?\n");
    scanf("%s", &input);
    
    if(strcmp(input, "north") == 0)
    {
        printf("Sorry, that door is locked. You need a key to enter.\n");
    }
    else if(strcmp(input, "east") == 0)
    {
        printf("You enter a small room. There is a key on the table. \n");
        printf("What would you like to do?\n");
        scanf("%s", &input);
        if(strcmp(input, "take key") == 0)
        {
            printf("You take the key.\n");
            score += 50;
            printf("Your current score is %d.\n", score);
        }
    }
    else if(strcmp(input, "west") == 0)
    {
        printf("You enter a large room. There is a chest in the corner. \n");
        printf("What would you like to do?\n");
        scanf("%s", &input);
        if(strcmp(input, "open chest") == 0)
        {
            printf("You find a map inside the chest.\n");
            score += 100;
            printf("Your current score is %d.\n", score);
        }
    }
    else if(strcmp(input, "help") == 0)
    {
        initializeGame();
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}

void roomThree()
{
    char input[50];
    printf("You are in a dimly lit room. In the center of the room is a pedestal with a button. \n");
    printf("What would you like to do?\n");
    scanf("%s", &input);
    
    if(strcmp(input, "use key") == 0)
    {
        printf("You use the key to unlock the door to the north.\n");
        room = 0;
    }
    else if(strcmp(input, "use map") == 0)
    {
        printf("You use the map to figure out how to escape the room.\n");
        score += 200;
        printf("Your current score is %d.\n", score);
    }
    else if(strcmp(input, "press button") == 0)
    {
        printf("You press the button and hear a loud noise. \n");
        printf("What would you like to do?\n");
        scanf("%s", &input);

        if(strcmp(input, "help") == 0)
        {
            initializeGame();
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }
    else if(strcmp(input, "help") == 0)
    {
        initializeGame();
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }
}