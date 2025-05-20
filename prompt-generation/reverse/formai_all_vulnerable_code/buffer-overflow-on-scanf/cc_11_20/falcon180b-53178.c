//Falcon-180B DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0, computerScore = 0;
    char choice;

    do {
        system("clear");
        printf("Welcome to Rock Paper Scissors!\n");
        printf("You are playing against the computer.\n");
        printf("Please choose Rock, Paper or Scissors.\n");
        scanf("%c", &choice);

        int computerChoice = rand() % 3;

        if (computerChoice == 0) {
            printf("The computer chose Rock.\n");
        } else if (computerChoice == 1) {
            printf("The computer chose Paper.\n");
        } else {
            printf("The computer chose Scissors.\n");
        }

        if (choice == 'r' && computerChoice == 2) {
            printf("You win! Rock crushes Scissors.\n");
            playerScore++;
        } else if (choice == 'p' && computerChoice == 0) {
            printf("You win! Paper covers Rock.\n");
            playerScore++;
        } else if (choice =='s' && computerChoice == 1) {
            printf("You win! Scissors cuts Paper.\n");
            playerScore++;
        } else if (choice == 'r' && computerChoice == 1) {
            printf("You lose! Paper covers Rock.\n");
            computerScore++;
        } else if (choice == 'p' && computerChoice == 2) {
            printf("You lose! Scissors cuts Paper.\n");
            computerScore++;
        } else if (choice =='s' && computerChoice == 0) {
            printf("You lose! Rock crushes Scissors.\n");
            computerScore++;
        } else {
            printf("It's a tie!\n");
        }

        printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n): ");
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}