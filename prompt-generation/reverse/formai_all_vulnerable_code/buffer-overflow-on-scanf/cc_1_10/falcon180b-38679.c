//Falcon-180B DATASET v1.0 Category: Game ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void drawBoard(char board[][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][3]) {
    int i;

    // Check horizontal lines
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check vertical lines
    for(i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonal lines
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    char board[3][3];
    int player = 1;
    int choice;
    int flag = 0;

    srand(time(0));
    int compChoice = rand() % 9 + 1;

    printf("Player 1: X and Player 2: O\n");
    printf("Player %d's turn.\n", player);

    while(flag == 0) {
        system("clear");
        drawBoard(board);
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if(board[choice/3][choice%3]!= 'X' && board[choice/3][choice%3]!= 'O') {
            board[choice/3][choice%3] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move! Try again.\n");
            continue;
        }

        flag = checkWin(board);
    }

    drawBoard(board);
    if(player == 1) {
        printf("Player %d wins!\n", player);
    } else {
        printf("Player %d wins!\n", player);
    }

    return 0;
}