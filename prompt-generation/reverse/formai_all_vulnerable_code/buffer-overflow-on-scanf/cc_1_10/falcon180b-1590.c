//Falcon-180B DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBoard(char board[][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][3], char symbol) {
    int i, j;

    // Check horizontal lines
    for (i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Check vertical lines
    for (j = 0; j < 3; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return 1;
        }
    }

    // Check diagonal lines
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[3][3];
    generateBoard(board);
    int player = 1;
    int choice;
    int validInput = 0;

    while (1) {
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d%d", &choice, &choice);
        if (choice < 1 || choice > 3) {
            printf("Invalid input\n");
        } else {
            validInput = 1;
            if (board[choice - 1][0] == '-') {
                board[choice - 1][0] = (player % 2 == 0)? 'X' : 'O';
                player++;
            } else {
                printf("Spot already taken\n");
            }
        }
        if (checkWin(board, (player % 2 == 0)? 'X' : 'O')) {
            printf("\nPlayer %d wins!\n", player);
            break;
        } else if (validInput == 0) {
            printf("Invalid input\n");
        } else if (player == 9) {
            printf("\nTie game\n");
            break;
        }
        validInput = 0;
        player++;
    }

    return 0;
}