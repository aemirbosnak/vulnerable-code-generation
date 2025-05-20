//Falcon-180B DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_board(int board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 1)
                printf("X ");
            else if (board[i][j] == -1)
                printf("O ");
            else
                printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int flag = 0;

    srand(time(0));

    while (flag == 0) {
        system("clear");
        printf("\nPlayer 1: X and Player 2: O\n");
        printf("Enter your choice of position:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    printf("%d ", i * 3 + j + 1);
                }
            }
        }
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid choice. Please enter again.\n");
            continue;
        }
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col]!= 0) {
            printf("Sorry the row %d column %d is already marked with %d\n", row + 1, col + 1, board[row][col]);
            continue;
        }
        board[row][col] = player;
        player = -player;
        flag = 1;
    }

    game_board(board);

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        printf("Player %d won!\n", board[0][0] + 1);
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        printf("Player %d won!\n", board[0][2] + 1);
    else
        printf("Draw\n");

    return 0;
}