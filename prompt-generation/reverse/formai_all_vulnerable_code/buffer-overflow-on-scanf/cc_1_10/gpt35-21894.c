//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>

// Function to display the game board
void displayBoard(char board[3][3]) {
    printf("\nCurrent Board state:\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if game has ended
int checkEnded(char board[3][3]) {
    int i, j;
    int ended = 0;
    for (i = 0; i < 3; i++) {
        if ((board[i][0] != '-') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            ended = 1;
            break;
        } else if ((board[0][i] != '-') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            ended = 1;
            break;
        }
    }
    if ((board[0][0] != '-') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        ended = 1;
    } else if ((board[0][2] != '-') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        ended = 1;
    }
    return ended;
}

int main() {
    char board[3][3] = { {'-', '-', '-'},
                         {'-', '-', '-'},
                         {'-', '-', '-'} };
    int i, j, row, col;
    char move;
    int movesLeft = 9;
    
    printf("Welcome to Tic Tac Toe!\n");
    displayBoard(board);

    while (movesLeft > 0) {
        // Player 1's move
        printf("Player 1 (X): Enter your move (row col): ");
        scanf("%d %d", &row, &col);
        move = 'X';
        if ((row >= 1) && (row <= 3) && (col >= 1) && (col <= 3) && (board[row-1][col-1] == '-')) {
            board[row-1][col-1] = move;
            displayBoard(board);
            if (checkEnded(board)) {
                printf("Congratulation! Player 1 won!\n");
                break;
            }
            movesLeft--;
        } else {
            printf("Invalid move. Try again.\n");
        }

        if (movesLeft <= 0) {
            printf("The game ended in a tie.\n");
            break;
        }
        
        // Player 2's move
        printf("Player 2 (O): Enter your move (row col): ");
        scanf("%d %d", &row, &col);
        move = 'O';
        if ((row >= 1) && (row <= 3) && (col >= 1) && (col <= 3) && (board[row-1][col-1] == '-')) {
            board[row-1][col-1] = move;
            displayBoard(board);
            if (checkEnded(board)) {
                printf("Congratulation! Player 2 won!\n");
                break;
            }
            movesLeft--;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}