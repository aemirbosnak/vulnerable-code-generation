//Falcon-180B DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define SYMBOLS 4

void print_board(char board[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(char board[ROWS][COLS]) {
    int i;

    // Check rows
    for(i=0; i<ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for(i=0; i<COLS; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    char board[ROWS][COLS];
    int i, j, player = 1;
    srand(time(NULL));

    // Initialize board with random symbols
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = rand() % SYMBOLS + 'A';
        }
    }

    while(1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn.\n", player);
        int choice;
        scanf("%d", &choice);

        if(choice < 1 || choice > COLS) {
            printf("Invalid choice.\n");
            continue;
        }

        if(board[0][choice-1]!= 'A') {
            printf("Column %c is full.\n", board[0][choice-1] + 'A' - 1);
            continue;
        }

        board[player][choice-1] = player + 'A';
        player =!player;

        if(check_win(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
    }

    return 0;
}