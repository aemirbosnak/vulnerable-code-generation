//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

// Function to initialize the game board
void initBoard(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = '*';
        }
    }
}

// Function to print the game board
void printBoard(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if two positions match
int match(char board[SIZE][SIZE], int x, int y) {
    if(board[x][y]!= '*' && board[x][y] == board[x][y+1])
        return 1;
    else
        return 0;
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        if(match(board, i, 0) && match(board, i, 1) && match(board, i, 2))
            return 1;
    }
    for(int j=0; j<SIZE; j++) {
        if(match(board, 0, j) && match(board, 1, j) && match(board, 2, j))
            return 1;
    }
    if(match(board, 0, 0) && match(board, 1, 1) && match(board, 2, 2))
        return 1;
    if(match(board, 0, 2) && match(board, 1, 1) && match(board, 2, 0))
        return 1;
    return 0;
}

// Function to play the game
void playGame(char board[SIZE][SIZE]) {
    int player = 0;
    int choice;
    while(1) {
        printf("Player %d's turn\n", player+1);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > SIZE*SIZE) {
            printf("Invalid choice\n");
            continue;
        }
        if(board[choice/3][choice%3] == '*') {
            board[choice/3][choice%3] = (player == 0)? 'X' : 'O';
            if(checkWin(board)) {
                printf("Player %d wins!\n", player+1);
                break;
            }
            player =!player;
        }
        else {
            printf("Invalid choice\n");
        }
    }
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    initBoard(board);
    playGame(board);
    return 0;
}