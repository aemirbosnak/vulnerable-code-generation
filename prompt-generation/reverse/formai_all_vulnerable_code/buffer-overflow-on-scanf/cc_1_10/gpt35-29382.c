//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* function prototypes */
void intro();
void room_options(int room);
void take_action(int room, int action);
void end_game();

/* global variables */
int health = 100;
bool key = false;
int room = 1;
bool game_over = false;

int main()
{
    intro();
    
    while(!game_over)
    {
        room_options(room);
        int action;
        scanf("%d", &action);
        take_action(room, action);
    }
    
    return 0;
}

/* function to display game introduction */
void intro()
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are trapped in a mysterious castle with no memory of how you got there.\n");
    printf("You must explore each room to find clues and escape. Good luck!\n\n");
}

/* function to display room options */
void room_options(int room)
{
    printf("Room %d\n", room);
    if(room == 1)
    {
        printf("You are in a dark and damp room.\n");
        printf("1. Check for a door\n");
        printf("2. Search for a light source\n");
    }
    else if(room == 2)
    {
        printf("You are in a grand hall with a chandelier.\n");
        printf("1. Search for a key\n");
        printf("2. Check for a window\n");
        printf("3. Go back to previous room\n");
    }
    else if(room == 3)
    {
        printf("You are in a small room with a locked chest.\n");
        printf("1. Use key on chest\n");
        printf("2. Leave room\n");
    }
    else if(room == 4)
    {
        printf("You are in a room with a suspiciously empty bookshelf.\n");
        printf("1. Investigate bookshelf\n");
        printf("2. Leave room\n");
    }
    else if(room == 5)
    {
        printf("You are in a room with a painting on the wall.\n");
        printf("1. Inspect painting\n");
        printf("2. Leave room\n");
    }
    else if(room == 6)
    {
        printf("You are in a room with a window overlooking a garden.\n");
        printf("1. Jump out of window\n");
        printf("2. Leave room\n");
    }
    else if(room == 7)
    {
        printf("Congratulations! You have found the exit.\n");
        printf("1. End game\n");
    }
}

/* function to take action based on room and user input */
void take_action(int room, int action)
{
    if(room == 1)
    {
        if(action == 1)
        {
            printf("You feel a door, but it won't budge.\n");
        }
        else if(action == 2)
        {
            printf("You find a candle and light it.\n");
        }
        else
        {
            printf("Invalid action.\n");
        }
    }
    else if(room == 2)
    {
        if(action == 1)
        {
            if(key == false)
            {
                printf("You found a key!\n");
                key = true;
            }
            else
            {
                printf("You already have the key.\n");
            }
        }
        else if(action == 2)
        {
            printf("The window is too high to reach.\n");
        }
        else if(action == 3)
        {
            room = 1;
        }
        else
        {
            printf("Invalid action.\n");
        }
    }
    else if(room == 3)
    {
        if(action == 1)
        {
            if(key == true)
            {
                printf("You find a note that reads:\n");
                printf("'Congratulations on finding the key. The exit is in Room 7.'\n");
            }
            else
            {
                printf("The chest is locked.\n");
            }
        }
        else if(action == 2)
        {
            room = 2;
        }
        else
        {
            printf("Invalid action.\n");
        }
    }
    else if(room == 4)
    {
        if(action == 1)
        {
            printf("You pull on a book and a secret door opens!\n");
            room = 5;
        }
        else if(action == 2)
        {
            room = 2;
        }
        else
        {
            printf("Invalid action.\n");
        }
    }
    else if(room == 5)
    {
        if(action == 1)
        {
            printf("You find another note that reads:\n");
            printf("'You're almost there. Stay vigilant.'\n");
        }
        else if(action == 2)
        {
            room = 4;
        }
        else
        {
            printf("Invalid action.\n");
        }
    }
    else if(room == 6)
    {
        if(action == 1)
        {
            printf("You jump and land safely in the garden. Congratulations, you've escaped!\n");
            game_over = true;
        }
        else if(action == 2)
        {
            room = 2;
        }
        else
        {
            printf("Invalid action.\n");
        }
    }
    else if(room == 7)
    {
        if(action == 1)
        {
            end_game();
        }
        else
        {
            printf("Invalid action.\n");
        }
    }
    else
    {
        printf("Invalid room.\n");
    }
}

/* function to end the game */
void end_game()
{
    printf("Thank you for playing the Text-Based Adventure Game!\n");
    printf("Your final health was %d.\n", health);
    exit(0);
}