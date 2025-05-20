//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Function to display the Tic Tac Toe board
void display_board() {
    printf("\n");
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the game is over
int check_game_over() {
    // Check for horizontal win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // Check for vertical win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    // Check for diagonal win
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    // Check if board is full
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 2;
}

// Function to get the user's move
void get_user_move(int *x, int *y) {
    printf("Enter the row and column of your move (separated by a space): ");
    scanf("%d %d", x, y);
    *x -= 1;
    *y -= 1;
}

// Function to get the AI's move
void get_ai_move(int *x, int *y) {
    srand(time(NULL));
    do {
        *x = rand() % BOARD_SIZE;
        *y = rand() % BOARD_SIZE;
    } while (board[*x][*y] != ' ');
}

int main() {
    int x, y, turn = 0;
    printf("Welcome to Tic Tac Toe!\n");
    display_board();
    while (check_game_over() == 0) {
        if (turn % 2 == 0) {
            printf("Player's turn\n");
            get_user_move(&x, &y);
            board[x][y] = 'X';
        } else {
            printf("AI's turn\n");
            get_ai_move(&x, &y);
            board[x][y] = 'O';
        }
        display_board();
        turn++;
    }
    int winner = check_game_over();
    if (winner == 1) {
        if ((turn - 1) % 2 == 0) {
            printf("Player wins!\n");
        } else {
            printf("AI wins!\n");
        }
    } else {
        printf("Draw!\n");
    }
    return 0;
}