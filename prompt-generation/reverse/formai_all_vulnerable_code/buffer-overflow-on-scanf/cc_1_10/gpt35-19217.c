//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_table(int table[][3]);
int has_won(int table[][3], int row, int col);
int make_move(int table[][3], int player);

int main() {
    int table[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1, winner = 0;

    while (!winner) {
        printf("\nPlayer %d's turn:\n", player);
        print_table(table);
        winner = has_won(table, 3, 3);
        if (winner) {
            printf("\nCongratulations Player %d, you have won!\n", player);
            break;
        }
        if (make_move(table, player)) {
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        } else {
            printf("\nInvalid move. Please try again.\n");
        }
    }
    print_table(table);
    return 0;
}

void print_table(int table[][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int has_won(int table[][3], int row, int col) {
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
            return table[i][0];
        }
    }
    for (int j = 0; j < 3; j++) {
        if (table[0][j] == table[1][j] && table[1][j] == table[2][j]) {
            return table[0][j];
        }
    }
    if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
        return table[0][0];
    }
    if (table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
        return table[0][2];
    }
    return 0;
}

int make_move(int table[][3], int player) {
    int row, col;
    printf("Enter row and column position (0-2): ");
    scanf("%d %d", &row, &col);
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    } else if (table[row][col] != 0) {
        return 0;
    } else {
        table[row][col] = player;
        return 1;
    }
}