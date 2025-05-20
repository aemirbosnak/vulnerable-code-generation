//Falcon-180B DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    char choice;

    srand(time(NULL));

    printf("Welcome to the Futuristic Table Game!\n");
    printf("You will be playing against a computer AI.\n");
    printf("Choose your move:\n");
    printf("R - Rock\n");
    printf("P - Paper\n");
    printf("S - Scissors\n");
    scanf("%c", &choice);

    while (player_score < 5 && computer_score < 5) {
        int computer_move = rand() % 3;
        if (computer_move == 0) {
            printf("Computer chose Rock.\n");
        } else if (computer_move == 1) {
            printf("Computer chose Paper.\n");
        } else {
            printf("Computer chose Scissors.\n");
        }

        if (choice == 'R' && computer_move == 2) {
            printf("You win!\n");
            player_score++;
        } else if (choice == 'P' && computer_move == 0) {
            printf("You win!\n");
            player_score++;
        } else if (choice == 'S' && computer_move == 1) {
            printf("You win!\n");
            player_score++;
        } else if (choice == 'R' && computer_move == 0) {
            printf("You lose.\n");
            computer_score++;
        } else if (choice == 'P' && computer_move == 2) {
            printf("You lose.\n");
            computer_score++;
        } else if (choice == 'S' && computer_move == 0) {
            printf("You lose.\n");
            computer_score++;
        } else {
            printf("It's a tie.\n");
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
        printf("Play again? (y/n)\n");
        scanf(" %c", &choice);
    }

    if (player_score == 5) {
        printf("You win the game!\n");
    } else {
        printf("You lose the game.\n");
    }

    return 0;
}