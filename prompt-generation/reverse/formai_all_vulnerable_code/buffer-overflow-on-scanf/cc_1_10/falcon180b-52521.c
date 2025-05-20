//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int main() {
    int board[ROWS][COLS] = {{0}};
    int start_row, start_col, end_row, end_col;
    int number, guess;
    char choice;
    srand(time(NULL));

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Press any key to start...\n");
    getchar();

    // Initialize the board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
        }
    }

    // Print the board
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Get the user's choice
    printf("\nChoose a difficulty level:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d", &choice);

    printf("\nChoose a range of elements:\n");
    printf("1. Alkali metals\n2. Alkaline earth metals\n3. Transition metals\n4. Other metals\n5. Nonmetals\n6. Halogens\n7. Noble gases\n");
    scanf("%d", &choice);

    printf("\nChoose a number of guesses:\n");
    printf("1. 10\n2. 20\n3. 30\n");
    scanf("%d", &number);

    // Get the user's first guess
    printf("\nGuess an element on the board:\n");
    scanf(" %c", &guess);

    start_row = rand() % ROWS;
    start_col = rand() % COLS;
    end_row = start_row;
    end_col = start_col;

    // Check if the guess is correct
    while (guess!= board[start_row][start_col] && number > 0) {
        printf("\nIncorrect guess! Try again:\n");
        scanf(" %c", &guess);
        number--;
    }

    // Check if the user has won
    if (guess == board[start_row][start_col]) {
        printf("\nCongratulations! You have won the game!\n");
    } else {
        printf("\nSorry, you have lost the game.\n");
    }

    return 0;
}