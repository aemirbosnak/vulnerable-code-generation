//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMainMenu();
void startGame();
void gameWon();
void gameLost();
void playAgain();

int main()
{
    // start the game
    startGame();

    return 0;
}

// function to display the main menu
void displayMainMenu()
{
    system("clear"); // clear the console screen

    printf("\n\n\tWELCOME TO ADVENTURE GAME!");
    printf("\n\n\t1. Start Game");
    printf("\n\t2. Exit");
    printf("\n\n\tPlease enter your choice (1-2): ");
}

// function to start the game
void startGame()
{
    int choice;

    displayMainMenu();

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\n\n\tYou wake up in a dark room. There is no light and you can't see anything.\n\n");
            printf("\tYou feel around in the dark and find a matchbox. You light a match and look\n\taround. You see two doors in front of you. Which door do you choose?\n\n");
            printf("\t1. Door #1\n");
            printf("\t2. Door #2\n\n");

            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("\n\n\tYou open Door #1 and find a room with a chest. Do you want to open the chest?\n\n");
                printf("\t1. Yes\n");
                printf("\t2. No\n\n");

                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("\n\n\tYou open the chest and find a key! You can use the key to unlock a door later.\n\n");
                    printf("\tPress any key to continue...");
                    getchar();
                    getchar();

                    gameWon();
                }
                else
                {
                    printf("\n\n\tYou decide not to open the chest. You go back to the main room.\n\n");
                    printf("\tPress any key to continue...");
                    getchar();
                    getchar();

                    startGame();
                }
            }
            else if (choice == 2)
            {
                printf("\n\n\tYou open Door #2 and find a monster. You try to run but it's too late. The monster\n\tcatches up to you and you are never seen again.\n\n");
                printf("\tPress any key to continue...");
                getchar();
                getchar();

                gameLost();
            }
            else
            {
                printf("\n\n\tInvalid choice. Please try again.\n");
                printf("\tPress any key to continue...");
                getchar();
                getchar();

                startGame();
            }
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("\n\n\tInvalid choice. Please try again.\n");
            printf("\tPress any key to continue...");
            getchar();
            getchar();

            startGame();
            break;
    }
}

// function to display "you won" message
void gameWon()
{
    printf("\n\n\tCONGRATULATIONS! YOU WON THE GAME!\n\n");
    printf("\tPress any key to play again...");
    getchar();
    getchar();

    playAgain();
}

// function to display "you lost" message
void gameLost()
{
    printf("\n\n\tGAME OVER! YOU LOST!\n\n");
    printf("\tPress any key to play again...");
    getchar();
    getchar();

    playAgain();
}

// function to ask user if they want to play again
void playAgain()
{
    int choice;

    printf("\n\n\tDo you want to play again? (1 = yes, 2 = no) ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            startGame();
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("\n\n\tInvalid choice. Please try again.\n");
            printf("\tPress any key to continue...");
            getchar();
            getchar();

            playAgain();
            break;
    }
}