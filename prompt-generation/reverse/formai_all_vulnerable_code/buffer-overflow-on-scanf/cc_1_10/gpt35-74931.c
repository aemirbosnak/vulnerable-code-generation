//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

void initialize(char arr[][COLS]) {
    int count = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i == 0 && j == 2) || (i == 1 && j == 2) || (i == 3 && j == 2) || (i == 4 && j == 2)) {
                arr[i][j] = 'X';
            } else {
                arr[i][j] = ' ';
            }
        }
    }
}

void display(char arr[][COLS], int numArr[]) {
    printf("\n  B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("===================\n");
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", arr[i][j]);
        }
        printf("|\t%d\n", numArr[i]);
    }
    printf("===================\n");
}

int checkBingo(char arr[][COLS]) {
    int bingoCount = 0;

    // check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] == 'X') {
                count++;
            }
        }
        if (count == COLS) {
            bingoCount++;
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        int count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (arr[j][i] == 'X') {
                count++;
            }
        }
        if (count == ROWS) {
            bingoCount++;
        }
    }

    // check diagonal
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (arr[i][i] == 'X') {
            count++;
        }
    }
    if (count == ROWS) {
        bingoCount++;
    }

    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (arr[i][ROWS - i - 1] == 'X') {
            count++;
        }
    }
    if (count == ROWS) {
        bingoCount++;
    }

    return bingoCount;
}

void printGameOver() {
    printf("==== GAME OVER ====\n");
    printf("You got a BINGO!\n");
}

int main() {
    char board[ROWS][COLS];
    int numbers[ROWS];
    initialize(board);

    // generate unique random numbers
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        int number;
        do {
            number = rand() % 15 + 1 + (i * 15);
        } while (number == 0);
        numbers[i] = number;
    }

    // display board and numbers
    display(board, numbers);

    // game loop
    int bingoCount = 0;
    while (bingoCount < 5) {
        // get user input
        int userInput;
        printf("Enter the number: ");
        scanf("%d", &userInput);

        // mark board
        int marked = 0;
        for (int i = 0; i < ROWS; i++) {
            if (numbers[i] == userInput) {
                board[i][2] = 'X';
                marked = 1;
                break;
            }
        }

        if (!marked) {
            printf("Invalid number! Try Again.\n");
            continue;
        }

        // check bingo
        bingoCount = checkBingo(board);
        display(board, numbers);
    }

    // game over
    printGameOver();

    return 0;
}