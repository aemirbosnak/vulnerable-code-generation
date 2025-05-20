//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

int main() {
    srand(time(0));

    char playerChoice;
    char computerChoice;
    int score = 0;

    do {
        printf("Choose your option (R for Rock, P for Paper, S for Scissors): ");
        scanf(" %c", &playerChoice);

        switch (playerChoice) {
            case 'R':
                computerChoice = ROCK;
                break;
            case 'P':
                computerChoice = PAPER;
                break;
            case 'S':
                computerChoice = SCISSORS;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("Computer chooses %c.\n", computerChoice);

        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((playerChoice == ROCK && computerChoice == PAPER) ||
               (playerChoice == PAPER && computerChoice == SCISSORS) ||
               (playerChoice == SCISSORS && computerChoice == ROCK)) {
            printf("You win!\n");
            score++;
        } else {
            printf("Computer wins!\n");
        }
    } while (score < 1);

    printf("Game over. Your final score is %d.\n", score);

    return 0;
}