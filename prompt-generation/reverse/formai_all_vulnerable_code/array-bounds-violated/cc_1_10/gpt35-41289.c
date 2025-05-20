//FormAI DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillBoard(char board[][4], int size);
void displayBoard(char board[][4], int size);
void shuffleBoard(char board[][4], int size);
void getCoords(int* row, int* col);
void revealBoard(char board[][4], int row1, int col1, int row2, int col2);
int checkMatch(char board[][4], int row1, int col1, int row2, int col2);

int main() {
    char board[4][4] = { {'A', 'B', 'C', 'D'},
                         {'E', 'F', 'G', 'H'},
                         {'A', 'B', 'C', 'D'},
                         {'E', 'F', 'G', 'H'} };
    char mask[4][4] = { {'*', '*', '*', '*'},
                        {'*', '*', '*', '*'},
                        {'*', '*', '*', '*'},
                        {'*', '*', '*', '*'} };

    fillBoard(board, 4);
    displayBoard(mask, 4);
    shuffleBoard(board, 4);

    int row1, col1, row2, col2;
    int numAttempts = 0;
    int numMatches = 0;
    
    while (numMatches < 8) {
        printf("Enter the row and column of the first card: ");
        getCoords(&row1, &col1);

        printf("Enter the row and column of the second card: ");
        getCoords(&row2, &col2);
        
        revealBoard(board, row1, col1, row2, col2);
        displayBoard(mask, 4);
        
        if (checkMatch(board, row1, col1, row2, col2)) {
            numMatches++;
            printf("\nYou have a match! There are %d matches remaining.\n\n", (8-numMatches));
            mask[row1][col1] = board[row1][col1];
            mask[row2][col2] = board[row2][col2];
        }
        else {
            printf("\nSorry, those cards don't match. Try again.\n\n");
            mask[row1][col1] = '*';
            mask[row2][col2] = '*';
        }
        
        numAttempts++;
    }
    
    printf("\nCongratulations! You completed the game in %d attempts.\n", numAttempts);
    
    return 0;
}

void fillBoard(char board[][4], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = (char)('A' + (i*size + j)%8);
        }
    }
}

void displayBoard(char board[][4], int size) {
    printf("\n    0 1 2 3\n");
    printf("   ---------\n");
    for (int i = 0; i < size; i++) {
        printf("%d | ", i);
        for (int j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   ---------\n");
}

void shuffleBoard(char board[][4], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int row = rand() % size;
            int col = rand() % size;
            char temp = board[i][j];
            board[i][j] = board[row][col];
            board[row][col] = temp;
        }
    }
}

void getCoords(int* row, int* col) {
    scanf("%d %d", row, col);
}

void revealBoard(char board[][4], int row1, int col1, int row2, int col2) {
    printf("\nYou chose: %c and %c\n", board[row1][col1], board[row2][col2]);
}

int checkMatch(char board[][4], int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    }
    return 0;
}