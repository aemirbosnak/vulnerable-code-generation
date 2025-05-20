//FormAI DATASET v1.0 Category: Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
    char matrix[3][3]; // 3x3 matrix to represent game board
    int i, j, players = 1, row, column, move;

    // fill matrix with blank spaces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }

    // game loop
    while (1) {
        // print game board
        printf("\n");
        printf(" %c | %c | %c \n", matrix[0][0], matrix[0][1], matrix[0][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", matrix[1][0], matrix[1][1], matrix[1][2]);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", matrix[2][0], matrix[2][1], matrix[2][2]);

        // check if game is over
        if ((matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && matrix[0][0] != ' ') ||
            (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][0] != ' ') ||
            (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && matrix[2][0] != ' ') ||
            (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0] && matrix[0][0] != ' ') ||
            (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && matrix[0][1] != ' ') ||
            (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2] && matrix[0][2] != ' ') ||
            (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != ' ') ||
            (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != ' ')) {
            printf("\nPlayer %d wins!\n", players);
            break;
        }

        // check if game is tied
        if (move == 9) {
            printf("\nTie game!\n");
            break;
        }

        // get move from player
        printf("\nPlayer %d's move (%c): ", players, (players == 1) ? 'X' : 'O');
        scanf("%d", &move);
        row = (move - 1) / 3;
        column = (move - 1) % 3;

        // check if move is valid
        if (matrix[row][column] != ' ') {
            printf("\nInvalid move! Try again.\n");
            continue;
        }

        // make move 
        matrix[row][column] = (players == 1) ? 'X' : 'O';
        players = (players == 1) ? 2 : 1;
        move++;
    }

    return 0;
}