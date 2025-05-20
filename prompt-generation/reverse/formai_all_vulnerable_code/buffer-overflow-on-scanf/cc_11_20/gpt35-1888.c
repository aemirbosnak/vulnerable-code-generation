//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if the number generated is already present in the array
int isUnique(int arr[ROWS][COLS], int num);

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define and initialize the Bingo game board
    int board[ROWS][COLS] = {{0}};
    int numCount = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = numCount;
            numCount++;
        }
    }

    // Shuffle the board array to randomize the numbers
    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = COLS - 1; j >= 0; j--) {
            int randRow = rand() % (i + 1);
            int randCol = rand() % (j + 1);

            int temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }

    // Loop through the shuffled board array to simulate the game
    printf("Welcome to Bingo Simulator!\n");
    printf("First player to get five in a row wins!\n\n");
    printf("B     I     N     G     O\n\n");
    int winner = 0;
    int numCalls = 0;
    while (!winner) {
        // Print the current board with numbers called marked with an X
        printf("----------------------------\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'X') {
                    printf("|  X  ");
                } else {
                    printf("|  %d  ", board[i][j]);
                }
            }
            printf("|\n");
        }
        printf("----------------------------\n");
        printf("Number of calls: %d\n", numCalls);

        // Prompt the user to enter the number called
        int calledNum;
        printf("Enter the called number: ");
        scanf("%d", &calledNum);

        // Check if the number called is valid and unique
        if (calledNum < 1 || calledNum > ROWS * COLS) {
            printf("Invalid number called. Please try again.\n");
            continue;
        } else if (!isUnique(board, calledNum)) {
            printf("Number has already been called. Please try again.\n");
            continue;
        }

        // Mark the number called with an X on the board array
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == calledNum) {
                    board[i][j] = 'X';
                    break;
                }
            }
        }

        // Check for five in a row to determine if there is a winner
        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X' && board[i][3] == 'X' && board[i][4] == 'X') {
                winner = 1;
                printf("Congratulations! Player 1 wins!\n");
                break;
            } else if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X' && board[3][i] == 'X' && board[4][i] == 'X') {
                winner = 1;
                printf("Congratulations! Player 1 wins!\n");
                break;
            } else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X' && board[4][4] == 'X') {
                winner = 1;
                printf("Congratulations! Player 1 wins!\n");
                break;
            } else if (board[0][4] == 'X' && board[1][3] == 'X' && board[2][2] == 'X' && board[3][1] == 'X' && board[4][0] == 'X') {
                winner = 1;
                printf("Congratulations! Player 1 wins!\n");
                break;
            }
        }

        // Increase the number of calls made in this game
        numCalls++;
    }

    return 0;
}

// Function to check if the number generated is already present in the array
int isUnique(int arr[ROWS][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}