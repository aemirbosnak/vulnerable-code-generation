//FormAI DATASET v1.0 Category: Chess AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define chess board as a 2D array
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Function to print the current state of the board
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get user input and make a move
void make_move() {
    int initial_row, initial_col, final_row, final_col;
    printf("Enter the initial position (row column): ");
    scanf("%d %d", &initial_row, &initial_col);
    printf("Enter the final position (row column): ");
    scanf("%d %d", &final_row, &final_col);
    board[final_row][final_col] = board[initial_row][initial_col];
    board[initial_row][initial_col] = ' ';
}

int main() {
    // Print welcome statement!
    printf("Welcome to C Chess AI! Let's play some happy chess!\n");
    print_board();
    // Play until user exit
    char prompt[4];
    while (1) {
        printf("Do you want to move? (y/n): ");
        scanf("%s", prompt);
        if (prompt[0] == 'y') {
            printf("Let's make a move!\n");
            make_move();
            printf("Here is the updated board:\n");
            print_board();
            printf("Great move!\n");
        } else if (prompt[0] == 'n') {
            printf("Bye! Let's play again later!\n");
            return 0;
        } else {
            printf("I didn't understand that. Let's try again!\n");
            continue;
        }
    }
    return 0;
}