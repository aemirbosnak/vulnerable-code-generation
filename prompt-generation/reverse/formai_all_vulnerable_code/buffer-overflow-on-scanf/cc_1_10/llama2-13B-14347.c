//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int random_number(void) {
    return (rand() % 10) + 1;
}

// Function to display the game board
void display_board(int board[][5]) {
    int i, j;

    printf("Game Board:\n");
    for (i = 0; i < 5; i++) {
        printf(" row %d: ", i + 1);
        for (j = 0; j < 5; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get user input and update the game board
void update_board(int board[][5], int user_input) {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (board[i][j] == 0) {
                board[i][j] = user_input;
                break;
            }
        }
    }
}

// Function to check if the game is over
int is_game_over(int board[][5]) {
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (board[i][j] == 0) {
                return 0; // Game is not over
            }
        }
        return 1; // Game is over
    }
}

int main() {
    int board[5][5] = {{0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}};
    int i, j, user_input;

    // Display the initial game board
    display_board(board);

    // Get user input and update the game board
    while (1) {
        printf("Enter a row and column (e.g. '1 2' to place a '2' in the first row and second column): ");
        scanf("%d %d", &user_input, &user_input);
        update_board(board, user_input);

        // Check if the game is over
        if (is_game_over(board)) {
            break;
        }

        // Display the updated game board
        display_board(board);
    }

    return 0;
}