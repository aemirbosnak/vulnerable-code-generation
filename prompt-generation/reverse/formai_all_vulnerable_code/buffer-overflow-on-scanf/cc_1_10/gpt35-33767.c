//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A fun and unique C table game! */

int main() {
    srand(time(0)); // seed the random number generator
    int player_score = 0;
    int computer_score = 0;
    int total_rounds = 3;
    
    printf("Welcome to the C Table Game!\n");
    printf("You will be playing against the computer.\n");
    printf("You have to guess the sum of two random numbers between 1 and 6.\n");
    printf("If you get it right, you win the round! If you get it wrong, the computer wins the round!\n");
    printf("The player with the most wins at the end of %d rounds wins the game!\n", total_rounds);
    
    for (int i = 1; i <= total_rounds; i++) {
        printf("Round %d:\n", i);
        int num1 = rand() % 6 + 1;
        int num2 = rand() % 6 + 1;
        int sum = num1 + num2;
        
        printf("Player's turn:\n");
        int guess;
        printf("What is the sum of %d and %d?\n", num1, num2);
        scanf("%d", &guess);
        if (guess == sum) {
            printf("You won this round!\n");
            player_score++;
        } else {
            printf("You lost this round!\n");
            computer_score++;
        }
        
        printf("Computer's turn:\n");
        guess = rand() % 11;
        printf("What is the sum of %d and %d?\n", num1, num2);
        if (guess == sum) {
            printf("The computer won this round!\n");
            computer_score++;
        } else {
            printf("The computer lost this round!\n");
            player_score++;
        }
        
        printf("Scores:\nPlayer: %d\nComputer: %d\n", player_score, computer_score);
    }
    
    if (player_score > computer_score) {
        printf("Congratulations! You won the game!\n");
    } else if (computer_score > player_score) {
        printf("Sorry, you lost the game!\n");
    } else {
        printf("It's a tie game!\n");
    }
    
    return 0;
}