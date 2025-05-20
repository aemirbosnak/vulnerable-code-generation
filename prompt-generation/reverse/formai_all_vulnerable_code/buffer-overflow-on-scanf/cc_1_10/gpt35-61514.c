//FormAI DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int rollDice();
void displayTable(int playerScore, int computerScore, int turnScore);
int playTurn(int score, char playerName[]);
void printBanner();
void clearScreen();

// Main function
int main()
{
    // Initialize game variables
    int playerScore = 0;
    int computerScore = 0;
    int turnScore = 0;
    char playerName[20];

    printBanner();

    printf("\nEnter your name: ");
    scanf("%s", playerName);

    clearScreen();

    printf("Welcome, %s!\n\n", playerName);

    do {
        // Player's turn
        printf("%s's turn:\n", playerName);
        turnScore = playTurn(turnScore, playerName);
        playerScore += turnScore;

        if (playerScore >= 100) {
            break;
        }

        // Computer's turn
        printf("Computer's turn:\n");
        turnScore = playTurn(turnScore, "Computer");
        computerScore += turnScore;

        if (computerScore >= 100) {
            break;
        }

        // Display the current scores on the table
        displayTable(playerScore, computerScore, turnScore);

    } while (1);

    // Display the final scores on the table
    displayTable(playerScore, computerScore, turnScore);

    // Check the winner
    if (playerScore >= 100) {
        printf("Congratulations, %s! You have won the game!\n", playerName);
    } else {
        printf("Computer has won the game!\n");
    }

    return 0;
}

// Function to roll the dice
int rollDice()
{
    return (rand() % 6) + 1;
}

// Function to display the table
void displayTable(int playerScore, int computerScore, int turnScore)
{
    printf("-----------------------------------------------------------------\n");
    printf("| %10s | %10s | %10s |\n", "Player", "Computer", "Turn");
    printf("| %10d | %10d | %10d |\n", playerScore, computerScore, turnScore);
    printf("-----------------------------------------------------------------\n\n");
}

// Function for a player's turn
int playTurn(int score, char playerName[])
{
    int diceResult = 0;
    char choice;

    do {
        // Roll the dice
        diceResult = rollDice();

        printf("You have rolled a %d.\n", diceResult);

        if (diceResult == 1) {
            printf("You lost your turn!\n\n");
            return 0;
        }

        score += diceResult;

        printf("Your current score is %d.\n", score);

        if (score >= 100) {
            return score;
        }

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            printf("\n");
            return score;
        } else {
            clearScreen();
            printf("%s's turn:\n", playerName);
        }
    } while (choice == 'y');

    return score;
}

// Function to print a banner
void printBanner()
{
    printf("***************************************************************\n");
    printf("*                                                             *\n");
    printf("*                       C Table Game                          *\n");
    printf("*                                                             *\n");
    printf("***************************************************************\n\n");
}

// Function to clear the screen
void clearScreen()
{
    system("cls || clear");
}