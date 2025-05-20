//Falcon-180B DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char player = 'X';
int flag = 0;

void drawBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

void checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            printf("\nPlayer %c wins!", player);
            flag = 1;
            break;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            printf("\nPlayer %c wins!", player);
            flag = 1;
            break;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (board[i][0] == board[i + 1][0] && board[i][0] == board[i][2]) {
            printf("\nPlayer %c wins!", player);
            flag = 1;
            break;
        }
        if (board[i][2] == board[i + 1][1] && board[i + 1][1] == board[i][0]) {
            printf("\nPlayer %c wins!", player);
            flag = 1;
            break;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        printf("\nPlayer %c wins!", player);
        flag = 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        printf("\nPlayer %c wins!", player);
        flag = 1;
    }
}

void changePlayer() {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        system("clear");
        printf("\n\n\t\tTIC TAC TOE\n\n");
        printf("Player 1: X and Player 2: O\n");
        printf("Enter your choice of mark: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            player = 'X';
        } else {
            player = 'O';
        }
        int count = 0;
        while (count < 9) {
            int x, y;
            x = rand() % 3;
            y = rand() % 3;
            if (board[x][y]!= 'X' && board[x][y]!= 'O') {
                board[x][y] = player;
                drawBoard();
                count++;
                changePlayer();
            }
        }
        checkWin();
    } while (flag!= 1);
    return 0;
}