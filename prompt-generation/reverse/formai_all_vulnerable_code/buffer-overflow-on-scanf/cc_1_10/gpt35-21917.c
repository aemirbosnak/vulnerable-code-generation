//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

// function to generate random number within a given range
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int player_score = 0;
    int computer_score = 0;
    int rounds = 3;

    printf("Welcome to the game of Rock, Paper, Scissors!\n");
    printf("In this game, you will be playing against the computer.\n");
    printf("Each round, you will have to choose either rock, paper or scissors.\n");
    printf("The computer will also make a random choice.\n");
    printf("The winner of each round will get one point.\n");
    printf("The game will be played for %d rounds.\n", rounds);

    for (int i = 1; i <= rounds; i++) {
        printf("\nROUND %d\n", i);

        // get user input
        int player_choice;
        printf("Enter your choice (1 for rock, 2 for paper, 3 for scissors): ");
        scanf("%d", &player_choice);

        // generate computer choice
        int computer_choice = get_random(1, 3);

        // compare choices and update scores
        if (player_choice == 1 && computer_choice == 2) {
            printf("Computer chose paper. You lose this round.\n");
            computer_score++;
        } else if (player_choice == 1 && computer_choice == 3) {
            printf("Computer chose scissors. You win this round!\n");
            player_score++;
        } else if (player_choice == 2 && computer_choice == 1) {
            printf("Computer chose rock. You win this round!\n");
            player_score++;
        } else if (player_choice == 2 && computer_choice == 3) {
            printf("Computer chose scissors. You lose this round.\n");
            computer_score++;
        } else if (player_choice == 3 && computer_choice == 1) {
            printf("Computer chose rock. You lose this round.\n");
            computer_score++;
        } else if (player_choice == 3 && computer_choice == 2) {
            printf("Computer chose paper. You win this round!\n");
            player_score++;
        } else {
            printf("It's a tie!\n");
        }
    }

    printf("\nGAME OVER!\n");
    printf("Your score: %d\n", player_score);
    printf("Computer score: %d\n", computer_score);

    if (player_score > computer_score) {
        printf("Congratulations, you win the game!\n");
    } else if (player_score < computer_score) {
        printf("Sorry, you lost the game. Better luck next time!\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}