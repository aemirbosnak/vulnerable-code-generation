//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intro();
int room1();
int room2();
int room3();

int main()
{
    intro();
    int room = 1;

    while(room != 4)
    {
        switch(room) {
            case 1:
                room = room1();
                break;
            case 2:
                room = room2();
                break;
            case 3:
                room = room3();
                break;
        }
    }

    printf("\nYou have completed the adventure game!\n");
    printf("Thanks for playing!\n");

    return 0;
}

void intro()
{
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("----------------------------------------\n");
    printf("You find yourself in a dark room. You have no idea how you got here.\n");
    printf("There is a door in front of you and it's locked.\n");
    printf("Your goal is to find a way to escape.\n\n");

    printf("Commands:\n");
    printf("look - look around the room\n");
    printf("open - try to open the door\n");
    printf("help - display the available commands\n");
}

int room1()
{
    printf("\nYou are in room 1.\n");
    printf("There is a table and a chair in the room.\n");
    printf("The door is still locked.\n\n");

    char command[10];
    printf("> ");
    scanf("%s", command);

    if(strcmp(command, "look") == 0)
    {
        printf("\nYou see a key on the table.\n");
        return 1;
    }
    else if(strcmp(command, "open") == 0)
    {
        printf("\nThe door is locked.\n");
        return 1;
    }
    else if(strcmp(command, "help") == 0)
    {
        printf("\nCommands:\n");
        printf("look - look around the room\n");
        printf("open - try to open the door\n");
        printf("help - display the available commands\n");
        return 1;
    }
    else
    {
        printf("\nInvalid command!\n");
        return 1;
    }
}

int room2()
{
    printf("\nYou are in room 2.\n");
    printf("The room is empty except for a painting on the wall.\n");
    printf("The door is still locked.\n\n");

    char command[10];
    printf("> ");
    scanf("%s", command);

    if(strcmp(command, "look") == 0)
    {
        printf("\nThe painting has a keyhole behind it.\n");
        return 2;
    }
    else if(strcmp(command, "open") == 0)
    {
        printf("\nThe door is locked.\n");
        return 2;
    }
    else if(strcmp(command, "help") == 0)
    {
        printf("\nCommands:\n");
        printf("look - look around the room\n");
        printf("open - try to open the door\n");
        printf("help - display the available commands\n");
        return 2;
    }
    else
    {
        printf("\nInvalid command!\n");
        return 2;
    }
}

int room3()
{
    printf("\nYou are in room 3.\n");
    printf("There is a chest in the center of the room.\n");
    printf("The door is still locked.\n\n");

    char command[10];
    printf("> ");
    scanf("%s", command);

    if(strcmp(command, "look") == 0)
    {
        printf("\nThe chest is locked.\n");
        return 3;
    }
    else if(strcmp(command, "open") == 0)
    {
        printf("\nYou open the chest and find a key inside!\n");
        return 4;
    }
    else if(strcmp(command, "help") == 0)
    {
        printf("\nCommands:\n");
        printf("look - look around the room\n");
        printf("open - try to open the chest or door\n");
        printf("help - display the available commands\n");
        return 3;
    }
    else
    {
        printf("\nInvalid command!\n");
        return 3;
    }
}