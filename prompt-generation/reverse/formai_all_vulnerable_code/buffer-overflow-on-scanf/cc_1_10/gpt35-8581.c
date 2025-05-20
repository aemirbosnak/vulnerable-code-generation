//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void intro();
void roomOne();
void roomTwo();
void roomThree();
void gameOver();
void youWin();

// Recursive function for game flow
void play()
{
    int choice;

    printf("\nWhat do you want to do? (Enter 1, 2, or 3)\n");
    printf("1. Go to Room 1\n");
    printf("2. Go to Room 2\n");
    printf("3. Go to Room 3\n");
    scanf("%d", &choice);

    switch(choice)
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
            printf("Invalid choice. Try again.\n");
            play();
    }
}

// Function for Room 1
void roomOne()
{
    printf("\nYou are in Room 1. You see a key on the table.\n");
    printf("What do you want to do? (Enter 1 or 2)\n");
    printf("1. Take the key\n");
    printf("2. Leave the key\n");
    int choice;
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nYou take the key. You can now open the door to Room 2.\n");
        play(); // Back to main game flow
    }
    else if(choice == 2)
    {
        printf("\nYou leave the key. You cannot get into Room 2.\n");
        play(); // Back to main game flow
    }
    else
    {
        printf("Invalid choice. Try again.\n");
        roomOne(); // Recursive call to Room 1
    }
}

// Function for Room 2
void roomTwo()
{
    printf("\nYou are in Room 2. You see a door with a lock.\n");
    printf("What do you want to do? (Enter 1 or 2)\n");
    printf("1. Try to open the door with the key\n");
    printf("2. Leave the room\n");
    int choice;
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nYou use the key to open the door. You can now enter Room 3.\n");
        play(); // Back to main game flow
    }
    else if(choice == 2)
    {
        printf("\nYou leave the room and go back to the main hallway.\n");
        play(); // Back to main game flow
    }
    else
    {
        printf("\nInvalid choice. Try again.\n");
        roomTwo(); // Recursive call to Room 2
    }
}

// Function for Room 3
void roomThree()
{
    printf("\nYou are in Room 3. You see a treasure chest.\n");
    printf("What do you want to do? (Enter 1 or 2)\n");
    printf("1. Open the treasure chest\n");
    printf("2. Leave the room\n");
    int choice;
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nYou open the treasure chest and find a pile of gold. You win!\n");
        youWin(); // End of the game
    }
    else if(choice == 2)
    {
        printf("\nYou leave the room and go back to the main hallway.\n");
        play(); // Back to main game flow
    }
    else
    {
        printf("\nInvalid choice. Try again.\n");
        roomThree(); // Recursive call to Room 3
    }
}

// Function for game intro
void intro()
{
    printf("\nWelcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark hallway with three doors.\n");
    printf("Your goal is to enter Room 3 and open the treasure chest.\n");
    printf("Good luck!\n\n");
}

// Function for game over
void gameOver()
{
    printf("\nGame over. Try again!\n");
    exit(0);
}

// Function for winning the game
void youWin()
{
    char name[20];

    printf("\nCongratulations! You won the game!\n");
    printf("Enter your name to be added to the leaderboard: ");
    scanf("%s", name);

    printf("\n%s, you have been added to the leaderboard!\n", name);
    printf("Thanks for playing!\n");
    exit(0);
}

// Main function
int main()
{
    intro();
    play();

    return 0;
}