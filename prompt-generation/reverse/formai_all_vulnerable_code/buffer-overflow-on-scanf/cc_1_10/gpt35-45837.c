//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function prototypes
void intro();
void prompt();
void first_room();
void second_room();
void third_room();
void fourth_room();
void fifth_room();
void sixth_room();
void seventh_room();
void eighth_room();
void ninth_room();
void secret_room();

// global variables
int choice, flag = 0;

int main()
{
    intro();
    prompt();
    return 0;
}

// function definitions
void intro()
{
    printf("\nWelcome to the Text-Based Adventure Game!\n");
    printf("You are an adventurer on a quest to find the legendary treasure of the lost city.\n");
    printf("You will encounter dangerous traps and puzzles along the way.\n");
    printf("Good luck!\n\n");
}

void prompt()
{
    printf("\nYou are in a dark room.\n");
    printf("What would you like to do?\n\n");
    printf("1. Look around\n");
    printf("2. Search for a way out\n");
    printf("3. Quit game\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            first_room();
            break;

        case 2:
            if(flag == 0)
            {
                printf("\nYou cannot leave until you find the treasure!\n");
                prompt();
            }
            else
            {
                printf("\nYou have found the treasure! Congratulations!\n");
                secret_room();
            }
            break;

        case 3:
            printf("\nThank you for playing!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            prompt();
    }
}

void first_room()
{
    printf("\nYou look around the room.\n");
    printf("You see a torch and a door.\n");
    printf("What would you like to do?\n\n");
    printf("1. Take the torch\n");
    printf("2. Open the door\n");
    printf("3. Go back\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nYou take the torch.\n");
            prompt();
            break;

        case 2:
            second_room();
            break;

        case 3:
            prompt();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            first_room();
    }
}

void second_room()
{
    printf("\nYou open the door.\n");
    printf("You see a long hallway.\n");
    printf("What would you like to do?\n\n");
    printf("1. Walk down the hallway\n");
    printf("2. Go back\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            third_room();
            break;

        case 2:
            first_room();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            second_room();
    }
}

void third_room()
{
    printf("\nYou walk down the hallway.\n");
    printf("You see a fork in the path.\n");
    printf("What would you like to do?\n\n");
    printf("1. Take the left path\n");
    printf("2. Take the right path\n");
    printf("3. Go back\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            fourth_room();
            break;

        case 2:
            fifth_room();
            break;

        case 3:
            second_room();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            third_room();
    }
}

void fourth_room()
{
    printf("\nYou take the left path.\n");
    printf("You see a chest in the middle of the room.\n");
    printf("What would you like to do?\n\n");
    printf("1. Open the chest\n");
    printf("2. Go back\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nYou open the chest.\n");
            printf("A poisonous gas fills the room.\n");
            printf("You die.\n");
            exit(0);
            break;

        case 2:
            third_room();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            fourth_room();
    }
}

void fifth_room()
{
    printf("\nYou take the right path.\n");
    printf("You see a riddle on the wall.\n");
    printf("What has a heart that doesn't beat?\n");
    printf("What would you like to do?\n\n");
    printf("1. Answer the riddle\n");
    printf("2. Go back\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nYou answer 'artichoke'.\n");
            printf("The door unlocks.\n");
            sixth_room();
            break;

        case 2:
            third_room();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            fifth_room();
    }
}

void sixth_room()
{
    printf("\nYou enter the room.\n");
    printf("You see a lever and a door.\n");
    printf("What would you like to do?\n\n");
    printf("1. Pull the lever\n");
    printf("2. Open the door\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            seventh_room();
            break;

        case 2:
            printf("\nThe door is locked.\n");
            sixth_room();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            sixth_room();
    }
}

void seventh_room()
{
    printf("\nYou pull the lever.\n");
    printf("The door to the next room opens.\n");
    eighth_room();
}

void eighth_room()
{
    printf("\nYou enter the room.\n");
    printf("You see a chest and a door.\n");
    printf("What would you like to do?\n\n");
    printf("1. Open the chest\n");
    printf("2. Open the door\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nYou open the chest.\n");
            printf("A boulder falls from the ceiling.\n");
            printf("You die.\n");
            exit(0);
            break;

        case 2:
            ninth_room();
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            eighth_room();
    }
}

void ninth_room()
{
    printf("\nYou open the door.\n");
    printf("You see a room filled with treasure!\n");
    printf("Congratulations, you have found it!\n");
    flag = 1;
    prompt();
}

void secret_room()
{
    printf("\nYou have found the secret room!\n");
    printf("What would you like to do?\n\n");
    printf("1. Play again\n");
    printf("2. Quit game\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            flag = 0;
            prompt();
            break;

        case 2:
            printf("\nThank you for playing!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice! Try again.\n");
            secret_room();
    }
}