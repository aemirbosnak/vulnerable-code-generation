//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    char board[ROWS][COLS];
    int i, j, matches = 0;
    char choice;
    int flag = 0;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2 + '1';
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    while (1) {
        printf("\nEnter your choice (row and column): ");
        scanf("%d%c", &i, &choice);
        if (choice!= 'r' && choice!= 'c') {
            printf("Invalid choice.\n");
            continue;
        }
        if (i >= 0 && i < ROWS && (choice == 'r' || j >= 0 && j < COLS)) {
            if (board[i][j] == board[i][j+1]) {
                matches++;
                board[i][j] = '*';
                board[i][j+1] = '*';
                flag = 1;
            } else {
                board[i][j] = '-';
                board[i][j+1] = '-';
            }
        } else {
            printf("Invalid choice.\n");
        }
        if (flag) {
            flag = 0;
        } else {
            if (matches == 8) {
                printf("\nYou win!\n");
                break;
            } else if (matches == 0) {
                printf("\nYou lose.\n");
                break;
            }
        }
    }

    return 0;
}