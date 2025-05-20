//Falcon-180B DATASET v1.0 Category: Game ; Style: optimized
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
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(0));
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int player = 1;
    int choice;
    while(1) {
        system("clear");
        printBoard(board);
        printf("Player %d's turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 9) {
            printf("Invalid choice. Skipping turn.\n");
            continue;
        }
        if(board[choice/3][choice%3]!= 'X' && board[choice/3][choice%3]!= 'O') {
            board[choice/3][choice%3] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid choice. Skipping turn.\n");
        }
        if(checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
    }
    return 0;
}