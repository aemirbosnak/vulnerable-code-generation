//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    char playerChoice;
    char computerChoice;

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("To play, type 'r' for rock, 'p' for paper, or's' for scissors.\n");
    printf("Computer's choice: ");
    scanf(" %c", &computerChoice);

    do {
        printf("Player's choice: ");
        scanf(" %c", &playerChoice);

        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if (playerChoice == 'r' && computerChoice == 'p') {
            printf("Player wins!\n");
            playerScore++;
        } else if (playerChoice == 'r' && computerChoice =='s') {
            printf("Computer wins!\n");
            computerScore++;
        } else if (playerChoice == 'p' && computerChoice == 'r') {
            printf("Player wins!\n");
            playerScore++;
        } else if (playerChoice == 'p' && computerChoice =='s') {
            printf("Computer wins!\n");
            computerScore++;
        } else if (playerChoice =='s' && computerChoice == 'p') {
            printf("Player wins!\n");
            playerScore++;
        } else if (playerChoice =='s' && computerChoice == 'r') {
            printf("Computer wins!\n");
            computerScore++;
        } else {
            printf("Invalid choice. Try again.\n");
        }

        printf("Computer's choice: ");
        scanf(" %c", &computerChoice);
    } while (playerChoice!= 'q');

    if (playerScore > computerScore) {
        printf("Congratulations, you won!\n");
    } else if (playerScore < computerScore) {
        printf("Sorry, you lost.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}