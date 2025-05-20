//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int round_number = 0;
    char choice;

    printf("Welcome to the exciting game of Rock Paper Scissors!\n");
    printf("Press any key to start the game.\n");
    getchar();

    while (player_score < 5 && computer_score < 5) {
        printf("\nRound %d:\n", round_number + 1);
        printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
        scanf(" %c", &choice);

        if (choice == 'R' || choice == 'r') {
            if (rand() % 2 == 0) {
                printf("Computer chose Rock. It's a tie!\n");
            } else {
                printf("Computer chose Scissors. You win!\n");
                player_score++;
            }
        } else if (choice == 'P' || choice == 'p') {
            if (rand() % 2 == 0) {
                printf("Computer chose Paper. You win!\n");
                player_score++;
            } else {
                printf("Computer chose Scissors. You lose!\n");
                computer_score++;
            }
        } else if (choice == 'S' || choice =='s') {
            if (rand() % 2 == 0) {
                printf("Computer chose Rock. You lose!\n");
                computer_score++;
            } else {
                printf("Computer chose Paper. It's a tie!\n");
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        round_number++;
    }

    if (player_score == 5) {
        printf("\nCongratulations! You won the game!\n");
    } else if (computer_score == 5) {
        printf("\nSorry, you lost the game.\n");
    } else {
        printf("\nThe game ended in a tie.\n");
    }

    return 0;
}