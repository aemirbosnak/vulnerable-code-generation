//Falcon-180B DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void drawBoard(char board[ROW][COL]) {
    printf(" %d | %d | %d \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf(" %d | %d | %d \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf(" %d | %d | %d \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |      \n");
}

int checkWin(char board[ROW][COL]) {
    for(int i=0; i<ROW; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    srand(time(0));
    char board[ROW][COL] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int player = 1;
    int choice;

    while(1) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter your move: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 9) {
            printf("Invalid move, try again.\n");
            continue;
        }
        if(board[0][choice-1]!= 'X' && board[0][choice-1]!= 'O') {
            board[0][choice-1] = (player % 2 == 0)? 'X' : 'O';
            player++;
        } else {
            printf("Invalid move, try again.\n");
        }
        if(checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", (player % 2) + 1);
            break;
        }
    }

    return 0;
}