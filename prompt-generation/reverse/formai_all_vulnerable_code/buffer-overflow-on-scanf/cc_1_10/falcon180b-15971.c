//Falcon-180B DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void generate_board(char board[MAX_ROWS][MAX_COLS]) {
    for(int i = 0; i < MAX_ROWS; i++) {
        for(int j = 0; j < MAX_COLS; j++) {
            board[i][j] = rand() % 2? 'X' : 'O';
        }
    }
}

int check_winner(char board[MAX_ROWS][MAX_COLS]) {
    for(int i = 0; i < MAX_ROWS; i++) {
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
    srand(time(NULL));
    char board[MAX_ROWS][MAX_COLS];
    generate_board(board);
    int player = 1;
    int choice;
    while(1) {
        system("clear");
        for(int i = 0; i < MAX_ROWS; i++) {
            for(int j = 0; j < MAX_COLS; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &choice, &choice);
        if(choice < 0 || choice > 2) {
            printf("Invalid move\n");
            continue;
        }
        int row = (player - 1) / 3 * 3 + choice;
        int col = (player - 1) % 3 * 3 + choice;
        if(board[row][col]!= 'X' && board[row][col]!= 'O') {
            board[row][col] = (player % 2)? 'X' : 'O';
            player++;
            if(check_winner(board)) {
                printf("\nPlayer %d wins!\n", player - 1);
                break;
            }
        } else {
            printf("Invalid move\n");
        }
    }
    return 0;
}