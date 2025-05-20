//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototype(s)
void displayIntro();
void displayInstructions();
void displayMap();
void enterName();
void enterLocation();
void startGame();
void playAgain();

// global variable(s)
char playerName[20];
char location[20];
char playAgainChoice;

int main()
{
    printf("\nWelcome to the Text-Based Adventure Game!");
    displayIntro(); // displays game intro
    displayInstructions(); // displays game instructions
    displayMap(); // displays game map
    enterName(); // allows player to enter name
    enterLocation(); // allows player to enter location
    startGame(); // starts game loop
    
    return 0;
}

// function(s)
void displayIntro()
{
    printf("\n\nYou have just embarked on a treacherous journey through the wilds of ");
    printf("ancient Babylonia.");
    printf("\nYou must find your way through the twisted streets and alleyways of the city ");
    printf("and seek out the mystical items that will lead you to your ultimate goal.");
}

void displayInstructions()
{
    printf("\n\nINSTRUCTIONS:");
    printf("\n\t1. Use the W,A,S and D keys to move your character around the game map.");
    printf("\n\t2. Avoid the dangerous obstacles and traps that litter the path ahead.");
    printf("\n\t3. Collect the mystical items that will aid you on your journey.");
    printf("\n\t4. Find the hidden gateway that will lead you to your ultimate goal.");
}

void displayMap()
{
    printf("\n\nMAP:");
    printf("\n\t######     ####\t\t\t     #####");
    printf("\n\t#    #     #  #\t\t\t     #");
    printf("\n\t#    #/////   #   #####   //////     #");
    printf("\n\t#             #   #   #              #");
    printf("\n\t#   ######    #   #####   #######    #");
    printf("\n\t#   #         #           #          #");
    printf("\n\t#   #/////   #    ///////  ///////  #");
    printf("\n\t#                                      #");
    printf("\n\t########################################\n");
}

void enterName()
{
    printf("\nPlease enter your name (up to 20 characters): ");
    scanf("%s", playerName);
    printf("\nWelcome, %s!\n", playerName);
}

void enterLocation()
{
    printf("\nPlease enter your starting location (up to 20 characters): ");
    scanf("%s", location);
    printf("\nYou have started at %s.\n", location);
}

void startGame()
{
    printf("\nAre you ready to start the game? (y/n): ");
    scanf(" %c", &playAgainChoice);
    
    while (playAgainChoice == 'y')
    {
        printf("\n\nGame Started!\n");
        // Add game logic here
        playAgain(); // ask if player wants to play again or not
    }
}

void playAgain()
{
    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &playAgainChoice);
    
    if (playAgainChoice == 'n')
    {
        printf("\nThank you for playing! Goodbye, %s!\n", playerName);
        exit(0);
    }
    else if (playAgainChoice == 'y')
    {
        printf("\nRestarting game...\n");
    }
    else
    {
        printf("\nInvalid choice! Please enter either 'y' or 'n'.\n");
        playAgain();
    }
}