//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// function prototypes
bool isBingo(int bingoCard[5][5]);
bool checkRow(int row[5]);
bool checkColumn(int column[5]);

int main() {
    // initialize the bingo card
    int bingoCard[5][5] = {{5, 12, 23, 33, 44},
                           {1, 16, 26, 36, 51},
                           {4, 14, 0, 31, 49},
                           {9, 19, 28, 0, 56},
                           {10, 22, 41, 46, 57}};
    // display the bingo card
    printf("B  I  N  G  O\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (bingoCard[i][j] == 0) {
                printf("   ");
            } else {
                printf("%2d ", bingoCard[i][j]);
            }
        }
        printf("\n");
    }

    // play the game
    int num;
    for (int i = 0; i < 75; i++) {
        printf("Enter a number (1 - 75): ");
        scanf("%d", &num);

        // check if the number is already on the card
        bool found = false;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (bingoCard[j][k] == num) {
                    bingoCard[j][k] = 0;
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            printf("%d is on the card!\n", num);
        } else {
            printf("%d is not on the card.\n", num);
        }

        // check if there is a bingo
        if (isBingo(bingoCard)) {
            printf("BINGO!\n");
            break;
        }
    }

    return 0;
}

// check if there is a bingo
bool isBingo(int bingoCard[5][5]) {
    // check rows
    for (int i = 0; i < 5; i++) {
        if (checkRow(bingoCard[i])) {
            return true;
        }
    }

    // check columns
    for (int i = 0; i < 5; i++) {
        int column[5];
        for (int j = 0; j < 5; j++) {
            column[j] = bingoCard[j][i];
        }
        if (checkColumn(column)) {
            return true;
        }
    }

    // check diagonals
    int diagonal1[5];
    int diagonal2[5];
    for (int i = 0; i < 5; i++) {
        diagonal1[i] = bingoCard[i][i];
        diagonal2[i] = bingoCard[i][4-i];
    }
    if (checkColumn(diagonal1) || checkColumn(diagonal2)) {
        return true;
    }

    // no bingo
    return false;
}

// check if a row contains all zeroes
bool checkRow(int row[5]) {
    for (int i = 0; i < 5; i++) {
        if (row[i] != 0) {
            return false;
        }
    }
    return true;
}

// check if a column contains all zeroes
bool checkColumn(int column[5]) {
    for (int i = 0; i < 5; i++) {
        if (column[i] != 0) {
            return false;
        }
    }
    return true;
}