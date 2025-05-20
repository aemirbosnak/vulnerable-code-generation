//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));
    char player_choice;
    char computer_choice;
    char player_score;
    char computer_score;
    int score = 0;
    int computer_wins = 0;
    int player_wins = 0;

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Please enter your choice: ");
    scanf(" %c", &player_choice);
    printf("The computer has chosen %c\n", player_choice);

    do {
        if (player_choice == 'R') {
            computer_choice = 'P';
        } else if (player_choice == 'P') {
            computer_choice = 'S';
        } else if (player_choice == 'S') {
            computer_choice = 'R';
        }

        if (player_choice == computer_choice) {
            printf("It's a tie!\n");
        } else if (player_choice == 'R' && computer_choice == 'S') {
            printf("You win!\n");
            score++;
            player_wins++;
        } else if (player_choice == 'P' && computer_choice == 'R') {
            printf("You win!\n");
            score++;
            player_wins++;
        } else if (player_choice == 'S' && computer_choice == 'P') {
            printf("You win!\n");
            score++;
            player_wins++;
        } else {
            printf("The computer wins!\n");
            computer_wins++;
        }

        printf("Score: %c - %c\n", player_choice, computer_choice);
        printf("Score: %d - %d\n", score, computer_wins);
        printf("Player wins: %d\n", player_wins);
        printf("Computer wins: %d\n", computer_wins);
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &player_choice);
        printf("\n");
    } while (player_choice == 'Y' || player_choice == 'y');

    return 0;
}