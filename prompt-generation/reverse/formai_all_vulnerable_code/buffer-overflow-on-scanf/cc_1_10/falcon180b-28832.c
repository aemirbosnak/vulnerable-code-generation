//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(char board[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[3][3]) {
    //check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    //check columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[3][3];
    int player = 1;
    int choice;
    int flag = 0;
    int compChoice;

    //initialize board with empty spaces
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }

    //game loop
    while(flag == 0) {
        system("clear");
        printf("Player 1: X, Player 2: O\n");
        printBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 9) {
            if(board[choice/3][choice%3] == '-') {
                board[choice/3][choice%3] = (player == 1)? 'X' : 'O';
                player++;
                flag = checkWin(board);
            }
            else {
                printf("Invalid move\n");
            }
        }
        else {
            printf("Invalid choice\n");
        }
        if(flag == 0) {
            compChoice = rand() % 9 + 1;
            if(board[compChoice/3][compChoice%3] == '-') {
                board[compChoice/3][compChoice%3] = (player == 1)? 'O' : 'X';
                player++;
                flag = checkWin(board);
            }
        }
    }

    if(player == 1) {
        printf("Player 1 wins!\n");
    }
    else {
        printf("Player 2 wins!\n");
    }

    return 0;
}