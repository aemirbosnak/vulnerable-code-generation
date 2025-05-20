//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAB_SIZE 5
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct {
    int value;
    int isEven;
} Cell;

void initTable(Cell table[NUM_ROWS][NUM_COLS]) {
    srand(time(NULL));
    int i, j;

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            table[i][j].value = rand() % 11;
            table[i][j].isEven = table[i][j].value % 2 == 0;
        }
    }
}

void printTable(Cell table[NUM_ROWS][NUM_COLS]) {
    int i, j;

    printf("+----+----+----+----+----+\n");
    for (i = 0; i < NUM_ROWS; i++) {
        printf("|");
        for (j = 0; j < NUM_COLS; j++) {
            printf("%2d%c", table[i][j].value, (j == NUM_COLS - 1) ? '|' : ' ');
        }
        printf("|\n");
        if (i < NUM_ROWS - 1) {
            printf("+----+----+----+----+----+\n");
        }
    }
}

int main() {
    Cell gameTable[NUM_ROWS][NUM_COLS];

    initTable(gameTable);
    printTable(gameTable);

    int guess;
    int row, col;
    int correctGuess = 0;

    do {
        printf("Enter a row and column number to guess an even number: ");
        scanf("%d%d", &row, &col);

        if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
            guess = gameTable[row][col].value;
            printf("You guessed number %d which is %s.\n", guess,
                gameTable[row][col].isEven ? "even" : "odd");

            if (gameTable[row][col].isEven && guess % 2 == 0) {
                correctGuess = 1;
            }
        } else {
            printf("Invalid row or column number.\n");
        }

        printTable(gameTable);

    } while (!correctGuess);

    printf("Congratulations, you guessed an even number correctly.\n");

    return 0;
}