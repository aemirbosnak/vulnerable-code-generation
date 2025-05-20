//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>
#define ROWS 5
#define COLS 5

void print_pattern(int row, int col) {
    int i, j;

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid row or column\n");
        return;
    }

    switch (row) {
        case 0:
            for (i = 0; i < COLS; i++) {
                printf("%c ", 'A' + i);
            }
            printf("\n");
            break;
        case ROWS - 1:
            for (i = COLS - 1; i >= 0; i--) {
                printf("%c ", 'A' + i);
            }
            printf("\n");
            break;
        default:
            for (i = 0; i < col; i++) {
                printf("%c ", 'A' + i);
            }
            for (j = ROWS - 2; j > row; j--) {
                printf(" %c ", ' ');
            }
            for (i = col; i < COLS; i++) {
                printf("%c ", 'A' + i);
            }
            printf("\n");
            break;
    }
}

int main() {
    int row, col;

    printf("Enter row number: ");
    scanf("%d", &row);
    printf("Enter column number: ");
    scanf("%d", &col);

    print_pattern(row, col);

    return 0;
}