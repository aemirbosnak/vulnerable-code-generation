//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 5 // defines the size of the board
#define PLAYER 1 // represents the human player
#define AI 2 // represents the computer player

// function to display the game board
void displayBoard(char board[][SIZE]);

// function to check if a move is possible
int isMovePossible(char board[][SIZE], int row, int col);

// function to check if the game is over
int isGameOver(char board[][SIZE], char player);

// function to get the value of a cell
char getValue(char board[][SIZE], int row, int col);

// function to set the value of a cell
void setValue(char board[][SIZE], int row, int col, char value);

// function to make the computer's move
void makeAIMove(char board[][SIZE]);

// function to get the human player's move
void getHumanMove(char board[][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char choice;
    int turn, gameover;

    srand(time(NULL));

    printf("Welcome to the Tic Tac Toe game!\n");
    printf("Would you like to go first? (y/n) ");
    scanf("%c", &choice);

    if(choice == 'y' || choice == 'Y') {
        turn = PLAYER;
    }
    else {
        turn = AI;
    }

    // initialize the board
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // display the board
    displayBoard(board);
    printf("\n");

    // loop until the game is over
    do {
        // check whose turn it is
        if(turn == AI) {
            printf("Computer's turn...\n");
            makeAIMove(board);
            turn = PLAYER;
        }
        else {
            printf("Your turn...\n");
            getHumanMove(board);
            turn = AI;
        }

        // display the board
        displayBoard(board);
        printf("\n");

        // check if the game is over
        gameover = isGameOver(board, PLAYER);
        if(gameover == 1) {
            printf("You win!\n");
            break;
        }
        else if(gameover == 2) {
            printf("Computer wins!\n");
            break;
        }
        else if(gameover == 3) {
            printf("Game over, it's a tie!\n");
            break;
        }

    } while(1);

    return 0;
}

void displayBoard(char board[][SIZE]) {
    printf("   ");
    for(int i=0; i<SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0; i<SIZE; i++) {
        printf("%d  ", i);
        for(int j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isMovePossible(char board[][SIZE], int row, int col) {
    if(board[row][col] == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

int isGameOver(char board[][SIZE], char player) {
    int rowSum, colSum, diagSum1=0, diagSum2=0, count=0;

    // check rows and columns
    for(int i=0; i<SIZE; i++) {
        rowSum = 0;
        colSum = 0;
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == player) {
                rowSum++;
            }
            if(board[j][i] == player) {
                colSum++;
            }
            if(board[i][j] != '-') {
                count++;
            }
        }
        if(rowSum == SIZE || colSum == SIZE) {
            return player == PLAYER ? 1 : 2;
        }
    }

    // check diagonals
    for(int i=0; i<SIZE; i++) {
        if(board[i][i] == player) {
            diagSum1++;
        }
        if(board[i][SIZE-i-1] == player) {
            diagSum2++;
        }
    }
    if(diagSum1 == SIZE || diagSum2 == SIZE) {
        return player == PLAYER ? 1 : 2;
    }

    // check for tie
    if(count == SIZE*SIZE) {
        return 3;
    }

    return 0;
}

char getValue(char board[][SIZE], int row, int col) {
    return board[row][col];
}

void setValue(char board[][SIZE], int row, int col, char value) {
    board[row][col] = value;
}

void makeAIMove(char board[][SIZE]) {
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while(!isMovePossible(board, row, col));
    setValue(board, row, col, 'O');
}

void getHumanMove(char board[][SIZE]) {
    int row, col;
    printf("Enter row and column number: ");
    scanf("%d %d", &row, &col);
    while(!isMovePossible(board, row, col)) {
        printf("Invalid move, try again...\n");
        printf("Enter row and column number: ");
        scanf("%d %d", &row, &col);
    }
    setValue(board, row, col, 'X');
}