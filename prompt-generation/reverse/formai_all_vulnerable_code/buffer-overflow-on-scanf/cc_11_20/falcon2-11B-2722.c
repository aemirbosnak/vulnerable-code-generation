//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game board as an array of characters
char board[3][3] = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'}
};

int main() {
    // Print the initial game board
    printf("Initial Game Board: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Shuffle the board randomly
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int r = rand() % 3;
            int c = rand() % 3;
            char temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }

    // Print the shuffled game board
    printf("Shuffled Game Board: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Start the memory game
    char userInput;
    while (1) {
        printf("Guess the correct character: ");
        scanf(" %c", &userInput);

        // Check if the user input is correct
        int correct = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (userInput == board[i][j]) {
                    correct++;
                }
            }
        }

        // Print the results of the memory game
        if (correct == 9) {
            printf("Congratulations! You have won the memory game!\n");
            break;
        } else {
            printf("Sorry, your guess was incorrect. Please try again!\n");
        }
    }

    return 0;
}