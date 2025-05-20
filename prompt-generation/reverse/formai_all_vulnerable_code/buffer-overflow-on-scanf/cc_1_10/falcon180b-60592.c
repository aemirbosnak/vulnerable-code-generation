//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1;
        }
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int player = 1;
    int choice;
    int flag = 0;

    while(flag == 0) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        print_board(board);
        printf("\nPlayer %d's Turn\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 9) {
            printf("Invalid Move! Try Again.\n");
            continue;
        }

        if(board[choice/3][choice%3]!= 'X' && board[choice/3][choice%3]!= 'O') {
            if(player % 2 == 1) {
                board[choice/3][choice%3] = 'X';
            } else {
                board[choice/3][choice%3] = 'O';
            }
            player++;
        } else {
            printf("Sorry the row %d is already marked with %c\n", choice, board[choice/3][choice%3]);
        }

        flag = check_win(board);
    }

    if(player % 2 == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}