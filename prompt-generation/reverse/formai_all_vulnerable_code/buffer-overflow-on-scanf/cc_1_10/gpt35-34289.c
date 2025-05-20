//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Helper function to print the board
void printBoard(char board[][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Function to check if a player has won the game
int checkWin(char board[][3], char player) {
    //Check for horizontal win
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    //Check for vertical win
    for(int i=0; i<3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    //Check for diagonal win
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return 1;
    }
    return 0;
}

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char player1 = 'X';
    char player2 = 'O';
    srand(time(NULL)); //Seed for random number generation
    int currentPlayer = rand() % 2; //Randomly select starting player
    int turns = 0;
    int gameOver = 0;
    //Game loop
    while(turns < 9 && !gameOver) {
        printBoard(board);
        if(currentPlayer == 0) {
            printf("Player 1's turn (X):\n");
        } else {
            printf("Player 2's turn (O):\n");
        }
        int position;
        do {
            printf("Enter a position (1-9): ");
            scanf("%d", &position);
        } while(position < 1 || position > 9 || board[(position-1)/3][(position-1)%3] == 'X' || board[(position-1)/3][(position-1)%3] == 'O'); //Validate user input
        if(currentPlayer == 0) {
            board[(position-1)/3][(position-1)%3] = 'X';
            if(checkWin(board, 'X')) {
                printf("Player 1 (X) wins!\n");
                gameOver = 1;
            }
            currentPlayer = 1;
        } else {
            board[(position-1)/3][(position-1)%3] = 'O';
            if(checkWin(board, 'O')) {
                printf("Player 2 (O) wins!\n");
                gameOver = 1;
            }
            currentPlayer = 0;
        }
        turns++;
    }
    if(!gameOver) {
        printf("Game over! It's a tie.\n");
    }
    printBoard(board);
    return 0;
}