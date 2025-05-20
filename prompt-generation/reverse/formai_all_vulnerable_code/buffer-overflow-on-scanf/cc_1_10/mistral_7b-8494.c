//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define ELEM_TYPE int

typedef struct {
    ELEM_TYPE table[SIZE][SIZE];
    int row, col;
} Table;

Table create_table() {
    Table t;
    int i, j;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            t.table[i][j] = rand() % 10 + 1;
        }
    }

    t.row = rand() % SIZE;
    t.col = rand() % SIZE;

    return t;
}

int check_win(Table t, int guess_row, int guess_col) {
    if (guess_row == t.row && guess_col == t.col) {
        printf("Congratulations! You found the number %d at row %d and column %d!\n", t.table[t.row][t.col], t.row, t.col);
        return 1;
    }

    if (guess_row < 0 || guess_row >= SIZE || guess_col < 0 || guess_col >= SIZE) {
        printf("Invalid move. Please enter a valid row and column number.\n");
        return 0;
    }

    if (t.table[guess_row][guess_col] > t.table[t.row][t.col]) {
        printf("The number %d at row %d and column %d is greater than the hidden number. Try again!\n", t.table[guess_row][guess_col], guess_row, guess_col);
        return 0;
    }

    if (t.table[guess_row][guess_col] < t.table[t.row][t.col]) {
        printf("The number %d at row %d and column %d is smaller than the hidden number. Try again!\n", t.table[guess_row][guess_col], guess_row, guess_col);
        return 0;
    }

    printf("You guessed correctly! But the game is over. The hidden number was %d at row %d and column %d.\n", t.table[t.row][t.col], t.row, t.col);
    return 1;
}

int main() {
    Table table = create_table();
    int guess_row, guess_col;

    while (1) {
        printf("Welcome to the Surprising Number Game! I have hidden a number in a %d x %d table. Try to find it by guessing a row and column number.\n", SIZE, SIZE);
        printf("Your turn! Enter a row number (0-%d): ", SIZE-1);
        scanf("%d", &guess_row);
        printf("Enter a column number (0-%d): ", SIZE-1);
        scanf("%d", &guess_col);

        if (check_win(table, guess_row, guess_col)) {
            break;
        }
    }

    return 0;
}