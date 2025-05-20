//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4
#define NUM_PAIRS 8

char board[ROW][COL];

void initBoard() {
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
}

void placeCard(int row, int col) {
    board[row][col] = '*';
}

int checkMatch(int row, int col) {
    if(row < 0 || row >= ROW || col < 0 || col >= COL || board[row][col]!= '*') {
        return 0;
    }
    return 1;
}

void flipCard(int row, int col) {
    if(checkMatch(row, col)) {
        if(board[row][col] == '*') {
            board[row][col] = '1';
        } else if(board[row][col] == '1') {
            board[row][col] = '2';
        } else {
            board[row][col] = '*';
        }
    }
}

void displayBoard() {
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int i, j, matches = 0;
    initBoard();
    for(i = 0; i < NUM_PAIRS; i++) {
        int row1 = rand() % ROW;
        int col1 = rand() % COL;
        int row2 = rand() % ROW;
        int col2 = rand() % COL;
        while(row1 == row2 && col1 == col2) {
            row1 = rand() % ROW;
            col1 = rand() % COL;
            row2 = rand() % ROW;
            col2 = rand() % COL;
        }
        placeCard(row1, col1);
        placeCard(row2, col2);
    }
    while(matches < NUM_PAIRS) {
        int row1, col1, row2, col2;
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &row2, &col2);
        if(checkMatch(row1, col1) && checkMatch(row2, col2)) {
            flipCard(row1, col1);
            flipCard(row2, col2);
            if(board[row1][col1] == '2' && board[row2][col2] == '2') {
                matches++;
            }
        } else {
            printf("Invalid input!\n");
        }
        displayBoard();
        sleep(1);
    }
    if(matches == NUM_PAIRS) {
        printf("Congratulations! You won the game!\n");
    } else {
        printf("Sorry, you lost the game.\n");
    }
    return 0;
}