//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ITEMS 4
#define MAX_LEN 20

void initializeGame(char* playerName);
void displayOpeningScreen();
int getMenuChoice();
void displayRoomChoices();
int getChoice();
void roomOne(char* playerName, int* itemsFound);
void roomTwo(char* playerName, int* itemsFound);
void roomThree(char* playerName, int* itemsFound);
void roomFour(char* playerName, int* itemsFound);
void gameOver(char* playerName, int* itemsFound);

int main()
{
    char playerName[MAX_LEN];
    int itemsFound[ITEMS] = {0};

    displayOpeningScreen();
    printf("\nEnter your name: ");
    fgets(playerName, MAX_LEN, stdin);
    strtok(playerName, "\n");

    initializeGame(playerName);
    roomOne(playerName, itemsFound);

    return 0;
}

void initializeGame(char* playerName)
{
    printf("\nWelcome %s! This is a text-based adventure game.\n", playerName);
    printf("You will need to navigate through different rooms to find the hidden treasure.\n");
    printf("Good luck!\n");
}

void displayOpeningScreen()
{
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
    printf("**                                                                            **\n");
    printf("**                         The Adventure Game                                **\n");
    printf("**                                                                            **\n");
    printf("********************************************************************************\n");
    printf("********************************************************************************\n");
}

int getMenuChoice()
{
    int choice;
    printf("\nWhat would you like to do?\n");
    printf("1. Move to another room\n");
    printf("2. Check your inventory\n");
    printf("3. Quit game\n");
    scanf("%d", &choice);
    return choice;
}

void displayRoomChoices()
{
    printf("\nWhich room would you like to move to?\n");
    printf("1. Room One\n");
    printf("2. Room Two\n");
    printf("3. Room Three\n");
    printf("4. Room Four\n");
}

int getChoice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

void roomOne(char* playerName, int* itemsFound)
{
    printf("\nYou have entered Room One.\n");
    printf("You see a table with a key on it.\n");

    int choice = 0;
    while (choice != 2 && choice != 3)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Take the key\n");
        printf("2. Move to another room\n");
        printf("3. Quit game\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            itemsFound[0] = 1;
            printf("\nYou have taken the key.\n");
        }
        else if (choice == 2)
        {
            displayRoomChoices();
            int roomChoice = getChoice();

            if (roomChoice == 1)
            {
                printf("\nYou are already in Room One.\n");
            }
            else if (roomChoice == 2)
            {
                roomTwo(playerName, itemsFound);
            }
            else if (roomChoice == 3)
            {
                roomThree(playerName, itemsFound);
            }
            else if (roomChoice == 4)
            {
                roomFour(playerName, itemsFound);
            }
        }
        else if (choice == 3)
        {
            gameOver(playerName, itemsFound);
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    if (choice == 3)
    {
        gameOver(playerName, itemsFound);
    }
}

void roomTwo(char* playerName, int* itemsFound)
{
    printf("\nYou have entered Room Two.\n");
    printf("You see a chest in the middle of the room.\n");

    int choice = 0;
    while (choice != 2 && choice != 3)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Try to open the chest\n");
        printf("2. Move to another room\n");
        printf("3. Quit game\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (itemsFound[0] == 1)
            {
                itemsFound[1] = 1;
                printf("\nYou have found a second key in the chest.\n");
            }
            else
            {
                printf("\nThe chest is locked. You need a key to open it.\n");
            }
        }
        else if (choice == 2)
        {
            displayRoomChoices();
            int roomChoice = getChoice();

            if (roomChoice == 1)
            {
                roomOne(playerName, itemsFound);
            }
            else if (roomChoice == 2)
            {
                printf("\nYou are already in Room Two.\n");
            }
            else if (roomChoice == 3)
            {
                roomThree(playerName, itemsFound);
            }
            else if (roomChoice == 4)
            {
                roomFour(playerName, itemsFound);
            }
        }
        else if (choice == 3)
        {
            gameOver(playerName, itemsFound);
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    if (choice == 3)
    {
        gameOver(playerName, itemsFound);
    }
}

void roomThree(char* playerName, int* itemsFound)
{
    printf("\nYou have entered Room Three.\n");
    printf("You see a ladder leading to the attic.\n");

    int choice = 0;
    while (choice != 2 && choice != 3)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Climb up the ladder\n");
        printf("2. Move to another room\n");
        printf("3. Quit game\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (itemsFound[1] == 1)
            {
                itemsFound[2] = 1;
                printf("\nYou have found a treasure map in the attic.\n");
            }
            else
            {
                printf("\nYou need a key to climb up the ladder.\n");
            }
        }
        else if (choice == 2)
        {
            displayRoomChoices();
            int roomChoice = getChoice();

            if (roomChoice == 1)
            {
                roomOne(playerName, itemsFound);
            }
            else if (roomChoice == 2)
            {
                roomTwo(playerName, itemsFound);
            }
            else if (roomChoice == 3)
            {
                printf("\nYou are already in Room Three.\n");
            }
            else if (roomChoice == 4)
            {
                roomFour(playerName, itemsFound);
            }
        }
        else if (choice == 3)
        {
            gameOver(playerName, itemsFound);
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    if (choice == 3)
    {
        gameOver(playerName, itemsFound);
    }
}

void roomFour(char* playerName, int* itemsFound)
{
    printf("\nYou have entered Room Four.\n");
    printf("You see a chest in the corner of the room.\n");

    int choice = 0;
    while (choice != 2 && choice != 3)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Try to open the chest\n");
        printf("2. Move to another room\n");
        printf("3. Quit game\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (itemsFound[2] == 1)
            {
                itemsFound[3] = 1;
                printf("\nYou have found the hidden treasure!\n");
            }
            else
            {
                printf("\nThe chest is locked. You need a treasure map to open it.\n");
            }
        }
        else if (choice == 2)
        {
            displayRoomChoices();
            int roomChoice = getChoice();

            if (roomChoice == 1)
            {
                roomOne(playerName, itemsFound);
            }
            else if (roomChoice == 2)
            {
                roomTwo(playerName, itemsFound);
            }
            else if (roomChoice == 3)
            {
                roomThree(playerName, itemsFound);
            }
            else if (roomChoice == 4)
            {
                printf("\nYou are already in Room Four.\n");
            }
        }
        else if (choice == 3)
        {
            gameOver(playerName, itemsFound);
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    if (choice == 3)
    {
        gameOver(playerName, itemsFound);
    }
}

void gameOver(char* playerName, int* itemsFound)
{
    printf("\nGame Over!\n");
    printf("Congratulations %s! You found %d out of %d items.\n", playerName, 
           itemsFound[0] + itemsFound[1] + itemsFound[2] + itemsFound[3], ITEMS);
}