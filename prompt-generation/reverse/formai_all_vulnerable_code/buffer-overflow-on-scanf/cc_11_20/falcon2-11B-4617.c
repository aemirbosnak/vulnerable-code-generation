//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int x = 0, y = 0;
    int player = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is X, Player 2 is O\n");
    printf("Enter a row number (1-3): ");
    scanf("%d", &x);
    while (x < 1 || x > 3) {
        printf("Invalid row number. Please enter a number between 1 and 3.\n");
        printf("Enter a row number (1-3): ");
        scanf("%d", &x);
    }
    printf("Enter a column number (1-3): ");
    scanf("%d", &y);
    while (y < 1 || y > 3) {
        printf("Invalid column number. Please enter a number between 1 and 3.\n");
        printf("Enter a column number (1-3): ");
        scanf("%d", &y);
    }
    board[x-1][y-1] = player;
    printf("Player %d placed %c at position (%d, %d)\n", player, 'X' + 1, x, y);
    if (player == 0) {
        player = 1;
    } else {
        player = 0;
    }

    int t = 0;
    while (t < 9) {
        if (board[x-1][y-1]!= 0) {
            printf("%c wins!\n", 'X' + 1);
            break;
        }
        if (board[x-1][y-1] == 0) {
            printf("Player %d's turn\n", player);
            printf("Enter a row number (1-3): ");
            scanf("%d", &x);
            while (x < 1 || x > 3) {
                printf("Invalid row number. Please enter a number between 1 and 3.\n");
                printf("Enter a row number (1-3): ");
                scanf("%d", &x);
            }
            printf("Enter a column number (1-3): ");
            scanf("%d", &y);
            while (y < 1 || y > 3) {
                printf("Invalid column number. Please enter a number between 1 and 3.\n");
                printf("Enter a column number (1-3): ");
                scanf("%d", &y);
            }
            board[x-1][y-1] = player;
            printf("Player %d placed %c at position (%d, %d)\n", player, 'X' + 1, x, y);
            if (player == 0) {
                player = 1;
            } else {
                player = 0;
            }
        } else {
            printf("It's a draw!\n");
            break;
        }
        t++;
    }
    return 0;
}