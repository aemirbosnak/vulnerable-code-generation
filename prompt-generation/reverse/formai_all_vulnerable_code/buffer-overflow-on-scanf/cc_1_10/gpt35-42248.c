//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 3
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

void printBoard(char board[][BOARD_SIZE]);
void makeMove(char board[][BOARD_SIZE], int row, int col, char player);
int getComputerMove(char board[][BOARD_SIZE], int *row, int *col);
char checkWinner(char board[][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    char winner = '\0', player = '\0', choice = '\0';
    int rows, cols, totalMoves = 0;

    // Random seed for computer move
    srand(time(NULL));

    // Select player to start
    printf("Select which player you want to be (X/O): ");
    scanf(" %c", &player);

    // Game loop
    do {
        printBoard(board);

        // Player's turn
        if (player == PLAYER_ONE) {
            printf("Player One's Turn (%c): ", player);
            scanf("%d %d", &rows, &cols);
        }
        else {
            printf("Player Two's Turn (%c): ", player);
            getComputerMove(board, &rows, &cols);
            printf("%d %d\n", rows, cols);
        }

        // Check if the move is valid
        if (rows < 1 || rows > 3 || cols < 1 || cols > 3) {
            printf("Invalid move. Please enter a row and column between 1 and 3.\n");
            continue;
        }

        if (board[rows-1][cols-1] != 'X' && board[rows-1][cols-1] != 'O') {
            makeMove(board, rows-1, cols-1, player);
            totalMoves++;

            // Check if there is a winner
            winner = checkWinner(board);
            if (winner != '\0')
                break;

            // Switch player
            player = (player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
        }
        else {
            printf("Invalid move. Please select an empty cell.\n");
            continue;
        }

    } while (totalMoves < BOARD_SIZE * BOARD_SIZE);

    // Print out the final board and winner
    printBoard(board);
    if (winner == PLAYER_ONE)
        printf("Player One (%c) is the winner!\n", PLAYER_ONE);
    else if (winner == PLAYER_TWO)
        printf("Player Two (%c) is the winner!\n", PLAYER_TWO);
    else
        printf("It's a tie!\n");

    return 0;
}

// Function to print out the current board
void printBoard(char board[][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j != BOARD_SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i != BOARD_SIZE - 1)
            printf("-----------\n");
    }
    printf("\n");
}

// Function to update the board with the player's move
void makeMove(char board[][BOARD_SIZE], int row, int col, char player) {
    board[row][col] = player;
}

// Function to get the computer's move
int getComputerMove(char board[][BOARD_SIZE], int *row, int *col) {
    int emptyCells[BOARD_SIZE * BOARD_SIZE][2];
    int index = 0;

    // Find all empty cells on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                emptyCells[index][0] = i;
                emptyCells[index][1] = j;
                index++;
            }
        }
    }

    // Randomly select an empty cell
    if (index > 0) {
        index = rand() % index;
        *row = emptyCells[index][0];
        *col = emptyCells[index][1];
        return 1;
    }
    // No empty cells left
    else {
        return 0;
    }
}

// Function to check if there is a winner
char checkWinner(char board[][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // No winner yet
    return '\0';
}