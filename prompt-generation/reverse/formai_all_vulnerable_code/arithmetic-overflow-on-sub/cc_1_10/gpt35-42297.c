//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

/* Function prototypes */
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int get_player_move(char board[BOARD_SIZE][BOARD_SIZE]);
int get_computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
char check_win(char board[BOARD_SIZE][BOARD_SIZE]);

/* Main function */
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player = 'X';
    char winner = '\0';
    int move;

    srand(time(NULL));

    /* Initialize the board */
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = ' ';
        }
    }

    /* Play the game */
    do {
        /* Print the current state of the board */
        print_board(board);

        /* Get the current player's move */
        if (current_player == 'X') {
            move = get_player_move(board);
        }
        else {
            move = get_computer_move(board);
        }

        /* Update the board */
        board[move / BOARD_SIZE][move % BOARD_SIZE] = current_player;

        /* Check for a winner */
        winner = check_win(board);

        /* Switch to the other player */
        if (current_player == 'X') {
            current_player = 'O';
        }
        else {
            current_player = 'X';
        }

    } while (winner == '\0');

    /* Print the final state of the board */
    print_board(board);

    /* Print the result of the game */
    if (winner == 'X') {
        printf("Congratulations! You won!\n");
    }
    else if (winner == 'O') {
        printf("Sorry, you lost. Better luck next time.\n");
    }
    else {
        printf("It's a tie.\n");
    }

    return 0;
}

/* Function to print the Tic Tac Toe board */
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf(" %c | %c | %c ", board[row][0], board[row][1], board[row][2]);
        if (row < BOARD_SIZE - 1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

/* Function to get the player's move */
int get_player_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int move;
    do {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        move--;
    } while (move < 0 || move >= BOARD_SIZE * BOARD_SIZE || board[move / BOARD_SIZE][move % BOARD_SIZE] != ' ');
    return move;
}

/* Function to get the computer's move */
int get_computer_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int move;
    do {
        move = rand() % (BOARD_SIZE * BOARD_SIZE);
    } while (board[move / BOARD_SIZE][move % BOARD_SIZE] != ' ');
    printf("Computer's move: %d\n", move + 1);
    return move;
}

/* Function to check for a winner */
char check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    /* Check rows */
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            return board[row][0];
        }
    }
    /* Check columns */
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[0][col] == board[2][col]) {
            return board[0][col];
        }
    }
    /* Check diagonals */
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    /* Check for a tie */
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == ' ') {
                return '\0';
            }
        }
    }
    return ' ';
}