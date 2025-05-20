//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10

// Function to generate a random number between min and max
int random_generator(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to print the game board
void print_board(char board[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the game board
void initialize_board(char board[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = '.';
        }
    }
}

// Function to place the treasure on the board
void place_treasure(char board[][COLS]) {
    int treasure_row = random_generator(0, ROWS-1);
    int treasure_col = random_generator(0, COLS-1);
    board[treasure_row][treasure_col] = '$';
}

// Function to play the game
void play_game(char board[][COLS]) {
    int row_guess, col_guess;
    printf("Welcome to the treasure hunt game!\n");
    printf("You have 5 attempts to find the treasure\n");
    for(int i=1; i<=5; i++) {
        printf("Attempt %d:\n", i);
        printf("Enter row and column number to search (between 0 and 9)\n");
        scanf("%d %d", &row_guess, &col_guess);
        if(board[row_guess][col_guess] == '$') {
            printf("Congratulations! You found the treasure in %d attempts\n", i);
            return;
        }
        else {
            printf("Oops! The treasure is not here\n");
        }
    }
    printf("Sorry, you could not find the treasure in 5 attempts\n");
    return;
}

// Main function
int main() {
    char board[ROWS][COLS];
    srand(time(0)); // To generate a different random number every time the program runs
    initialize_board(board);
    place_treasure(board);
    print_board(board);
    play_game(board);
    return 0;
}