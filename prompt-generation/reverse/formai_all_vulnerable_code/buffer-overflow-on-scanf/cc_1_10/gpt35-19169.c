//FormAI DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to determine the winner
int determineWinner(int player, int computer) {
    // check for a tie
    if (player == computer) {
        return 0;
    }
    // check for player win scenarios
    else if (player == 1 && computer == 3 || 
             player == 2 && computer == 1 || 
             player == 3 && computer == 2) {
        return 1;
    }
    // all other scenarios result in a computer win
    else {
        return -1;
    }
}

// function to get the user's choice
int getUserChoice() {
    int choice;
    printf("\nEnter your choice:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    scanf("%d", &choice);
    return choice;
}

// function to get the computer's choice
int getComputerChoice() {
    // generate a random number between 1 and 3
    srand(time(NULL));
    int choice = rand() % 3 + 1;
    return choice;
}

int main() {
    int playerChoice, computerChoice, result;

    printf("Welcome to the Rock-Paper-Scissors game!\n");

    // loop allowing the user to play the game multiple times
    while (1) {
        playerChoice = getUserChoice();

        // print the user's choice
        if (playerChoice == 1) {
            printf("You chose Rock.\n");
        }
        else if (playerChoice == 2) {
            printf("You chose Paper.\n");
        }
        else {
            printf("You chose Scissors.\n");
        }

        computerChoice = getComputerChoice();

        // print the computer's choice
        if (computerChoice == 1) {
            printf("The computer chose Rock.\n");
        }
        else if (computerChoice == 2) {
            printf("The computer chose Paper.\n");
        }
        else {
            printf("The computer chose Scissors.\n");
        }

        // determine the winner and print the result
        result = determineWinner(playerChoice, computerChoice);
        if (result == 0) {
            printf("It's a tie!\n");
        }
        else if (result == 1) {
            printf("You win!\n");
        }
        else {
            printf("The computer wins!\n");
        }

        // ask the user if they want to play again
        char playAgain;
        printf("Would you like to play again? (y/n)\n");
        scanf(" %c", &playAgain);
        
        if (playAgain == 'n') {
            printf("Thanks for playing!\n");
            break;
        }
    }

    return 0;
}