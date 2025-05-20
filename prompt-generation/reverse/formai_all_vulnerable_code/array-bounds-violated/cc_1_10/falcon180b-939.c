//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void drawBoard(int board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int checkWin(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    int board[3][3] = {{1,2,0},{2,1,2},{0,2,1}};
    int player = 1;
    int choice;
    int flag = 0;

    while (1) {
        printf("\nPlayer %d's Turn\n", player);
        system("clear");
        drawBoard(board);

        printf("\nEnter your move (1-%d): ", 9);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("\nInvalid Move! Try Again.\n");
            continue;
        }

        if (board[choice/3][choice%3]!= 0) {
            printf("\nCell Already Filled! Try Again.\n");
            continue;
        }

        board[choice/3][choice%3] = player;

        if (checkWin(board)) {
            printf("\nPlayer %d Wins!\n", player);
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    return 0;
}