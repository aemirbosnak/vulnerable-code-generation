//Falcon-180B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int playerScore = 0;
    int computerScore = 0;
    int choice;
    int computerChoice;
    char playAgain;

    do {
        // Player's turn
        printf("Let's play Rock Paper Scissors!\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You chose Rock.\n");
        } else if (choice == 2) {
            printf("You chose Paper.\n");
        } else if (choice == 3) {
            printf("You chose Scissors.\n");
        } else {
            printf("Invalid choice, defaulting to Rock.\n");
            choice = 1;
        }

        // Computer's turn
        computerChoice = rand() % 3 + 1;

        if (computerChoice == 1) {
            printf("Computer chose Rock.\n");
        } else if (computerChoice == 2) {
            printf("Computer chose Paper.\n");
        } else if (computerChoice == 3) {
            printf("Computer chose Scissors.\n");
        } else {
            printf("Computer chose an invalid option.\n");
            exit(1);
        }

        if (choice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((choice == 1 && computerChoice == 3) ||
                   (choice == 2 && computerChoice == 1) ||
                   (choice == 3 && computerChoice == 2)) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("You lose this round.\n");
            computerScore++;
        }

        printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}