//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void printTable(int table[ROW][COL])
{
    printf("\n------------\n");
    for (int i = 0; i < ROW; i++) {
        printf("|");
        for (int j = 0; j < COL; j++) {
            printf(" %c |", table[i][j]);
        }
        printf("\n------------\n");
    }
}

void selectCell(int table[ROW][COL], int player)
{
    int row, col;
    printf("Player %d, select a cell (row, col): ", player);
    scanf("%d, %d", &row, &col);
    if (table[row][col] != ' ') {
        printf("This cell has been selected, please select another one.\n");
        selectCell(table, player);
    } else {
        table[row][col] = (player == 1) ? 'X' : 'O';
    }
}

int checkWin(int table[ROW][COL])
{
    for (int i = 0; i < ROW; i++) {
        // Check rows
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
            if (table[i][0] == 'X') {
                return 1;
            } else if (table[i][0] == 'O') {
                return 2;
            }
        }

        // Check columns
        if (table[0][i] == table[1][i] && table[1][i] == table[2][i]) {
            if (table[0][i] == 'X') {
                return 1;
            } else if (table[0][i] == 'O') {
                return 2;
            }
        }
    }

    // Check diagonals
    if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
        if (table[0][0] == 'X') {
            return 1;
        } else if (table[0][0] == 'O') {
            return 2;
        }
    }
    if (table[2][0] == table[1][1] && table[1][1] == table[0][2]) {
        if (table[2][0] == 'X') {
            return 1;
        } else if (table[2][0] == 'O') {
            return 2;
        }
    }

    return 0;
}

int main()
{
    int table[ROW][COL] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1, winner = 0, count = 0;
    srand(time(NULL));

    printf("Welcome to the C table game! Player 1 is X and Player 2 is O.\n");
    printTable(table);

    while (winner == 0 && count < 9) {
        if (player == 1) {
            selectCell(table, player);
        } else {
            int row = rand() % 3;
            int col = rand() % 3;
            while (table[row][col] != ' ') {
                row = rand() % 3;
                col = rand() % 3;
            }
            printf("Player %d selected cell (%d, %d).\n", player, row, col);
            table[row][col] = 'O';
        }

        winner = checkWin(table);
        printTable(table);

        if (winner == 0) {
            player = (player == 1) ? 2 : 1;
            count++;
        }
    }

    if (winner == 1) {
        printf("Congratulations! Player 1 wins!\n");
    } else if (winner == 2) {
        printf("Congratulations! Player 2 wins!\n");
    } else {
        printf("It's a tie! Good game!\n");
    }

    return 0;
}