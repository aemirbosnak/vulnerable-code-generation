//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>

// function to print the board
void printBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if(i < 2) {
            printf("---+---+---\n");
        }
    }
}

// function to check if the board is full
int isFull(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// function to check if a player has won the game
int checkWin(char board[3][3], char player) {
    // check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// function to make the AI move
void aiMove(char board[3][3], char ai, char human) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // check if the spot is empty
            if(board[i][j] == ' ') {
                // create a copy of the board
                char temp[3][3];
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        temp[k][l] = board[k][l];
                    }
                }
                // make the move
                temp[i][j] = ai;
                // check if the move wins the game
                if(checkWin(temp, ai)) {
                    board[i][j] = ai;
                    return;
                }
            }
        }
    }
    // choose a random spot to move to
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while(board[x][y] != ' ');
    board[x][y] = ai;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char ai = 'X';
    char human = 'O';
    int turn = 0;
    srand(time(NULL));
    while(!isFull(board) && !checkWin(board, ai) && !checkWin(board, human)) {
        // print the board
        printBoard(board);
        printf("\n");
        if(turn % 2 == 0) {
            printf("AI's turn:\n");
            aiMove(board, ai, human);
        } else {
            printf("Human's turn:\n");
            int x, y;
            printf("Enter x coordinate: ");
            scanf("%d", &x);
            printf("Enter y coordinate: ");
            scanf("%d", &y);
            board[x][y] = human;
        }
        turn++;
    }
    printBoard(board);
    if(checkWin(board, ai)) {
        printf("AI wins!\n");
    } else if(checkWin(board, human)) {
        printf("Human wins!\n");
    } else {
        printf("Tie game!\n");
    }
    return 0;
}