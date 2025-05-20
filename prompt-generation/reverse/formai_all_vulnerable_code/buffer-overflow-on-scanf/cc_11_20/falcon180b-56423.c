//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int userScore = 0;
    int computerScore = 0;
    char choice;
    int computerChoice;
    int result;

    do {
        printf("Welcome to Rock-Paper-Scissors!\n");
        printf("You have %d points.\n", userScore);
        printf("Computer has %d points.\n", computerScore);
        printf("Enter your choice (R/P/S): ");
        scanf("%c", &choice);

        computerChoice = rand() % 3; // Computer chooses randomly between rock, paper, or scissors

        if (choice == 'R' && computerChoice == 0) {
            printf("Rock beats scissors! You win!\n");
            userScore++;
        } else if (choice == 'P' && computerChoice == 1) {
            printf("Scissors beats paper! Computer wins!\n");
            computerScore++;
        } else if (choice == 'S' && computerChoice == 2) {
            printf("Paper beats rock! You win!\n");
            userScore++;
        } else if (choice == 'R' && computerChoice == 1) {
            printf("Scissors beats rock! Computer wins!\n");
            computerScore++;
        } else if (choice == 'P' && computerChoice == 0) {
            printf("Rock beats paper! You win!\n");
            userScore++;
        } else if (choice == 'S' && computerChoice == 2) {
            printf("Paper beats scissors! Computer wins!\n");
            computerScore++;
        } else {
            printf("It's a tie!\n");
        }

        printf("Score: You - %d, Computer - %d\n", userScore, computerScore);
        printf("Do you want to play again? (Y/N): ");
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}