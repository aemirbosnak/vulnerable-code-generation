//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// function to print game board
void printBoard(char board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if game is won
int checkWin(char board[3][3]) {
    // check horizontal lines
    int i;
    for(i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // check vertical lines
    for(i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // check diagonal lines
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// function to check if game is tied
int checkTie(char board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j]!= 'X' && board[i][j]!= 'O') {
                return 0;
            }
        }
    }
    return 1;
}

// function to play game
int playGame(char board[3][3]) {
    int player = 1;
    int x, y;
    while(1) {
        printf("Player %d's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d%d", &x, &y);
        if(x < 1 || x > 3 || y < 1 || y > 3) {
            printf("Invalid move\n");
            continue;
        }
        if(board[x-1][y-1]!= 'X' && board[x-1][y-1]!= 'O') {
            board[x-1][y-1] = (player % 2 == 0)? 'X' : 'O';
            player++;
            if(checkWin(board)) {
                printf("Player %d wins!\n", player - 1);
                return 1;
            } else if(checkTie(board)) {
                printf("Tie game!\n");
                return 0;
            }
        } else {
            printf("Invalid move\n");
        }
    }
}

int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int result = playGame(board);
    if(result == 1) {
        printf("Do you want to play again? (y/n) ");
        char choice;
        scanf("%c", &choice);
        if(choice == 'y' || choice == 'Y') {
            main();
        }
    }
    return 0;
}