//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Tic Tac Toe board 

// A function to initialize the board with blank spaces
void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// A function to print the board
void print_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// A function to check if the game is over
int game_over() {
    int i, j;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    // Check for tie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 2;
}

// A function to get the computer's move
void computer_move(int *row, int *col) {
    // Seed the random number generator
    srand(time(NULL));
    // Choose a random position that is not already taken
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (board[*row][*col] != ' ');
}

// The main function that runs the game
void play_game() {
    int row, col, result;
    char player = 'X', computer = 'O';
    init_board();
    printf("Welcome to Tic Tac Toe!\n\n");
    print_board();
    while (1) {
        // Player's move
        printf("Enter row and column (eg. 2 3) or -1 to quit: ");
        scanf("%d", &row);
        if (row == -1) {
            printf("Quitting game...\n");
            return;
        }
        scanf("%d", &col);
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input! Please try again.\n\n");
            continue;
        } else if (board[row - 1][col - 1] != ' ') {
            printf("That space is already taken! Please try again.\n\n");
            continue;
        } else {
            board[row - 1][col - 1] = player;
            print_board();
        }
        // Check if the game is over
        result = game_over();
        if (result == 1) {
            printf("Congratulations! You win!\n");
            return;
        } else if (result == 2) {
            printf("It's a tie!\n");
            return;
        }
        // Computer's move
        printf("Computer is making a move...\n");
        computer_move(&row, &col);
        board[row][col] = computer;
        print_board();
        // Check if the game is over
        result = game_over();
        if (result == 1) {
            printf("Sorry, you lose. Better luck next time!\n");
            return;
        } else if (result == 2) {
            printf("It's a tie!\n");
            return;
        }
    }
}

// The main function
int main() {
    play_game();
    return 0;
}