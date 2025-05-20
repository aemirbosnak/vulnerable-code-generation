//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int main() {
    srand(time(NULL));  // seed the random number generator
    char gameboard[ROW][COL];  // create the gameboard
    int row_position = rand() % ROW;  // randomly select row position
    int col_position = rand() % COL;  // randomly select column position
    gameboard[row_position][col_position] = '*';  // place the star in a random position
    int row_guess, col_guess, correct_guess = 0;  // initialize game variables

    // display game rules
    printf("Welcome to the Star Hunt Game!\n");
    printf("The goal of the game is to find the hidden star.\n");
    printf("Enter your guess in the format row,column.\n");
    printf("You have 10 chances to find the star. Good luck!\n\n");

    // initialize gameboard with dashes
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            gameboard[i][j] = '-';
        }
    }

    // while loop for 10 chances to find the star
    for (int guess = 1; guess <= 10; guess++) {
        printf("Guess %d: ", guess);
        scanf("%d,%d", &row_guess, &col_guess);  // get row and column guess from user
        if (row_guess < 0 || row_guess >= ROW || col_guess < 0 || col_guess >= COL) {
            printf("Invalid guess. Try again.\n");
            guess--;  // do not count invalid guesses towards total guesses
        } else if (gameboard[row_guess][col_guess] == '*') {
            printf("Congratulations! You found the hidden star in %d guesses.\n", guess);
            gameboard[row_guess][col_guess] = '*';  // show the star on the gameboard
            correct_guess = 1;
            break;  // end the game if star is found
        } else if (gameboard[row_guess][col_guess] == '-') {
            printf("Missed! Try again.\n");
            gameboard[row_guess][col_guess] = 'X';  // mark the missed guess on the gameboard
        } else {
            printf("You already guessed that. Try again.\n");
            guess--;  // do not count repeated guesses towards total guesses
        }
    }

    // if star is not found, display game over message and show the hidden star on the gameboard
    if (correct_guess == 0) {
        printf("Game over. The hidden star was located at row %d, column %d.\n", row_position, col_position);
        gameboard[row_position][col_position] = '*';  // show the star on the gameboard
    }

    // display the final gameboard
    printf("\n\nFinal gameboard:\n");
    printf("  ");
    for (int i = 0; i < COL; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("%d ", i);
        for (int j = 0; j < COL; j++) {
            printf("%c ", gameboard[i][j]);
        }
        printf("\n");
    }

    return 0;  // end of game
}