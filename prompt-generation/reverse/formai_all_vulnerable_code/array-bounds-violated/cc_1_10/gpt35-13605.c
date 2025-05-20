//FormAI DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>

char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player1[20], player2[20];
int player = 1;

void drawBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}

void playerMove() {
    int choice, row, column;
    char mark;

    if (player == 1) {
        mark = 'X';
        printf("%s's turn (X): ", player1);
    } else {
        mark = 'O';
        printf("%s's turn (O): ", player2);
    }

    scanf("%d", &choice);

    row = --choice / 3;
    column = choice % 3;

    if (matrix[row][column] == choice + '1')
        matrix[row][column] = mark;
    else {
        printf("Invalid move. Try again...\n");
        playerMove();
    }
}

int gameOver() {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
            return 1;
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
            return 1;
    }

    // Check diagonals
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return 1;

    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return 1;

    // Check if board is full
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                return 0;
        }
    }

    return 2;
}

int main() {
    int status;

    printf("Enter player1's name (X): ");
    scanf("%s", player1);

    printf("Enter player2's name (O): ");
    scanf("%s", player2);

    drawBoard();

    while (1) {
        playerMove();
        drawBoard();
        status = gameOver();

        if (status == 1) {
            printf("Game over. ");

            if (player == 1)
                printf("%s wins!\n", player1);
            else
                printf("%s wins!\n", player2);

            break;
        } else if (status == 2) {
            printf("Game over. It's a tie!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}