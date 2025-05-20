//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function prototypes
void intro();
void startGame();
void room_1();
void room_2();
void room_3();
void endGame();

int health = 100;
int damage = 10;
int key = 0;

int main()
{
    intro();
    startGame();
    return 0;
}

void intro()
{
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("The room smells musty and there is a faint light coming from the door.\n\n");
}

void startGame()
{
    char choice;
    printf("What would you like to do?\n");
    printf("A. Open the door.\n");
    printf("B. Search the room.\n");
    printf("C. Wait for someone to rescue you.\n");
    scanf(" %c", &choice);

    if (toupper(choice) == 'A')
    {
        room_1();
    }
    else if (toupper(choice) == 'B')
    {
        room_2();
    }
    else if (toupper(choice) == 'C')
    {
        printf("You wait for hours but no one comes to rescue you. You starve to death.\n");
        endGame();
    }
    else
    {
        printf("Invalid choice. Please choose again.\n");
        startGame();
    }
}

void room_1()
{
    printf("You open the door and find yourself in a hallway.\n");
    printf("There are three doors. Which one do you want to go through?\n");
    printf("A. Door 1\n");
    printf("B. Door 2\n");
    printf("C. Door 3\n");
    char choice;
    scanf(" %c", &choice);

    if (toupper(choice) == 'A')
    {
        room_2();
    }
    else if (toupper(choice) == 'B')
    {
        room_3();
    }
    else if (toupper(choice) == 'C')
    {
        printf("You open the door and find a room full of treasures.\n");
        printf("You win the game!\n");
        endGame();
    }
    else
    {
        printf("Invalid choice. Please choose again.\n");
        room_1();
    }
}

void room_2()
{
    printf("You enter a room with a monster in it!\n");
    printf("What do you want to do?\n");
    printf("A. Fight the monster\n");
    printf("B. Run away\n");
    char choice;
    scanf(" %c", &choice);
    if (toupper(choice) == 'A')
    {
        health -= damage;
        printf("You fight the monster and lose %d health.\n", damage);
        if (health <= 0)
        {
            printf("You died.\n");
            endGame();
        }
        else
        {
            printf("You defeated the monster and found a key!\n");
            key = 1;
            room_1();
        }
    }
    else if (toupper(choice) == 'B')
    {
        printf("You run away and go back to the hallway.\n");
        room_1();
    }
    else
    {
        printf("Invalid choice. Please choose again.\n");
        room_2();
    }
}

void room_3()
{
    if (key == 0)
    {
        printf("The door is locked. You need a key.\n");
        room_1();
    }
    else
    {
        printf("You use the key to open the door and find a treasure chest.\n");
        printf("You win the game!\n");
        endGame();
    }
}

void endGame()
{
    printf("Game over.\n");
    exit(0);
}