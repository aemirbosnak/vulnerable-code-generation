//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4
#define TREASURES 4

char board[ROWS][COLUMNS];
int treasuresFound = 0;

void displayBoard();
void placeTreasures();
int chooseBox(int row, int col);
void playGame();

int main() {
    srand(time(NULL));
    placeTreasures();
    playGame();
    return 0;
}

void displayBoard() {
    printf("\nGame Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 'X') {
                printf("[ ] ");
            } else {
                printf("[%c] ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void placeTreasures() {
    int count = 0;
    while (count < TREASURES) {
        int row = rand() % ROWS;
        int col = rand() % COLUMNS;
        if (board[row][col] != 'T') {
            board[row][col] = 'T';
            count++;
        }
    }
    
    // Initialize the rest of the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] != 'T') {
                board[i][j] = 'X'; // Box is initially empty
            }
        }
    }
}

int chooseBox(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS || board[row][col] == 'O') {
        printf("Invalid choice! Try again.\n");
        return 0;
    }
    
    if (board[row][col] == 'T') {
        printf("Congratulations! You found a treasure!\n");
        board[row][col] = 'O'; // Mark the treasure as found
        treasuresFound++;
        return 1;
    } else {
        printf("Sorry! This box is empty.\n");
        board[row][col] = 'O'; // Mark the empty box as opened
        return 0;
    }
}

void playGame() {
    while (treasuresFound < TREASURES) {
        displayBoard();
        int row, col;
        printf("Enter the row (0-%d) and column (0-%d) to choose a box: ", ROWS - 1, COLUMNS - 1);
        scanf("%d %d", &row, &col);
        if (chooseBox(row, col)) {
            if (treasuresFound == TREASURES) {
                printf("You've found all the treasures! Game over!\n");
            }
        } else {
            printf("Try again!\n");
        }
    }
    
    displayBoard();
}