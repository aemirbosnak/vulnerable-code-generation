//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Table Game: Rock, Paper, Scissors
 * Developed by Visionary AI
 */

int main() {
    int user_choice, computer_choice, win = 0, lose = 0, tie = 0;
    char play_again = 'y';

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to Rock, Paper, Scissors!\n");

    while (play_again == 'y') { // loop until user doesn't want to play again
        printf("\nChoose your weapon:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &user_choice);

        if (user_choice < 1 || user_choice > 3) {
            printf("Invalid choice. Please choose a number between 1 and 3.\n");
            continue; // go back to beginning of loop
        }

        computer_choice = rand() % 3 + 1; // generate random number between 1 and 3

        printf("You chose %s.\n", (user_choice == 1) ? "rock" : (user_choice == 2) ? "paper" : "scissors");
        printf("The computer chose %s.\n", (computer_choice == 1) ? "rock" : (computer_choice == 2) ? "paper" : "scissors");

        if ((user_choice == 1 && computer_choice == 3) || 
            (user_choice == 2 && computer_choice == 1) || 
            (user_choice == 3 && computer_choice == 2)) {
            printf("You win!\n");
            win++;
        } else if ((user_choice == 1 && computer_choice == 2) || 
                   (user_choice == 2 && computer_choice == 3) || 
                   (user_choice == 3 && computer_choice == 1)) {
            printf("You lose!\n");
            lose++;
        } else {
            printf("It's a tie!\n");
            tie++;
        }

        printf("Wins: %d, Losses: %d, Ties: %d\n", win, lose, tie);

        printf("\nWould you like to play again? (y/n) ");
        scanf(" %c", &play_again);
    }

    printf("Thanks for playing!\n");

    return 0;
}