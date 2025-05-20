//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
void startGame();
void investigateRoom();
void investigateClues();
void interrogateSuspect();
void accuseSuspect();

int main()
{
    printf("Welcome to Sherlock Holmes' Adventure Game!\n\n");
    startGame();
    return 0;
}

void startGame()
{
    char playerName[50];
    printf("What is your name?\n");
    scanf("%s", playerName);
    printf("\nWelcome %s! \n"
           "You are now a detective. Your mission is to find the killer of Mr. Charles Baskerville. \n", playerName);
    printMenu();
}

void printMenu()
{
    printf("\nWhat would you like to do?\n");
    printf("1. Investigate the room\n");
    printf("2. Investigate the clues\n");
    printf("3. Interrogate the suspect\n");
    printf("4. Accuse the suspect\n");
    printf("5. Quit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            investigateRoom();
            break;
        case 2:
            investigateClues();
            break;
        case 3:
            interrogateSuspect();
            break;
        case 4:
            accuseSuspect();
            break;
        case 5:
            printf("\nThank you for playing, detective!\n");
            exit(0);
        default:
            printf("\nInvalid Choice. Please Choose Again.\n");
            printMenu();
    }
}

void investigateRoom(){
    printf("\nYou are now in Mr. Charles Baskerville's bedroom. It is a dark and gloomy night.\n"
           "You start searching for clues but find nothing. Suddenly, you hear a loud noise coming from the window.\n"
           "You run towards the window and see a man running away from the house.\n"
           "You must now follow him. Press any key to continue.\n");
    getchar();
    printf("\nYou run after the man but lose him in the woods. You start looking for clues in the woods. After a few minutes,\n"
           "you find a notebook lying on the ground. It belongs to the man who was running away from the house. You start reading it.\n"
           "It says that he was hired by someone to kill Mr. Charles Baskerville. You must now find the identity of the killer.\n");
    printMenu();
}

void investigateClues(){
    printf("\nYou go back to the bedroom to check if you have missed anything.\n"
           "You notice that the window is open. You also find a letter lying on the writing table. \n"
           "It has a logo of a hotel in London. You must now go to London to gather more information.\n");
    printMenu();
}

void interrogateSuspect(){
    printf("\nYou reach the hotel and interrogate the staff. One of the staff members reveals that he saw a man named John Watson\n"
           "booking a room in the hotel the same day Mr. Charles Baskerville was killed. You must now find John Watson.\n");
    printMenu();
}

void accuseSuspect(){
    printf("\nYou find John Watson and interrogate him. He confesses that he was hired by Mr. Stapleton to kill Mr. Charles Baskerville. \n"
           "You arrest Mr. Stapleton and justice is served. \n\n"
           "Congratulations, detective! You have solved the case.\n");
    exit(0);
}