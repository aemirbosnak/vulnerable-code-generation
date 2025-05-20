//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int option, userChoice, compChoice;
    int countUserWin = 0;
    int countCompWin = 0;
    int countTies = 0;
    
    printf("Welcome to the classic C Table Game!\n\n");
    printf("Rules:\n");
    printf("- Choose 1 for rock, 2 for paper, or 3 for scissors.\n");
    printf("- Rock beats scissors, paper beats rock, and scissors beats paper.\n");
    printf("- The game is played for 10 rounds and the player with the most wins at the end is the winner.\n\n");

    srand(time(NULL)); //initialize random seed
    
    for (int round = 1; round <= 10; round++) {
        printf("Round %d:\n", round);
        printf("Choose 1 for rock, 2 for paper, or 3 for scissors: ");
        scanf("%d", &userChoice);
        
        while (userChoice < 1 || userChoice > 3) { //validating user input
            printf("Invalid input! Choose 1 for rock, 2 for paper, or 3 for scissors: ");
            scanf("%d", &userChoice);
        }

        compChoice = rand() % 3 + 1; //randomizing computer's choice

        if (userChoice == compChoice) { //tie
            printf("Tie!\n");
            countTies++;
        } else if ((userChoice == 1 && compChoice == 3) || (userChoice == 2 && compChoice == 1) || (userChoice == 3 && compChoice == 2)) { //user wins
            printf("You win!\n");
            countUserWin++;
        } else { //computer wins
            printf("Computer wins!\n");
            countCompWin++;
        }
    }

    printf("\nGame Over!\n");

    if (countUserWin > countCompWin) {
        printf("Congratulations, you win the game with %d wins, %d losses and %d ties!\n", countUserWin, countCompWin, countTies);
    } else if (countUserWin < countCompWin) {
        printf("Sorry, you lost the game with %d wins, %d losses and %d ties.\n", countUserWin, countCompWin, countTies);
    } else {
        printf("It's a tie game with %d wins, %d losses, and %d ties.\n", countUserWin, countCompWin, countTies);
    }

    return 0;
}