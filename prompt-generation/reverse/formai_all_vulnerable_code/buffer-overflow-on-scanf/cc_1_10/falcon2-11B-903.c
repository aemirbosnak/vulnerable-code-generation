//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[9];
} Sudoku;

int isValid(Sudoku* s, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (s->data[i] == num && i!= row)
            return 0;
        if (s->data[row] == num && i!= col)
            return 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (s->data[i] == num && j!= row && i!= col)
                return 0;
            if (s->data[row] == num && j!= col && i!= row)
                return 0;
        }
    }
    return 1;
}

int backtrack(Sudoku* s) {
    int row = 0, col = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (s->data[i] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row!= 0)
            break;
    }
    if (row == 0)
        return 1;
    for (int i = 1; i <= 9; i++) {
        if (isValid(s, row, col, i)) {
            s->data[row] = i;
            if (backtrack(s))
                return 1;
            s->data[row] = 0;
        }
    }
    return 0;
}

int main() {
    Sudoku s;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &s.data[i]);
            if (s.data[i]!= 0)
                break;
        }
        if (i == 9)
            break;
    }
    if (backtrack(&s))
        printf("The Sudoku is solved!\n");
    else
        printf("The Sudoku is unsolvable!\n");
    return 0;
}