//Falcon-180B DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int board[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int player = 1;
    int choice;
    int flag = 0;

    while(flag == 0) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Choose your symbol (X/O): ");
        scanf("%d", &choice);
        if(choice == 49 || choice == 111) {
            player = 1;
        } else if(choice == 48 || choice == 110) {
            player = 2;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    while(flag == 0) {
        system("clear");
        printf("Tic Tac Toe\n");
        printf("Player %d's turn\n", player);
        printf("Enter your move (1-9): ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 9) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        int row = choice / 3;
        int col = choice % 3;
        if(board[row - 1][col - 1]!= 1) {
            board[row - 1][col - 1] = player;
            player = 3 - player;
            flag = 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    system("clear");
    printf("Tic Tac Toe\n");
    printf("Player %d wins!\n", player);
    return 0;
}