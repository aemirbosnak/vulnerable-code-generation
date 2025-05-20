//Falcon-180B DATASET v1.0 Category: Game ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void print_board(int board[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int board[SIZE][SIZE]) {
    int i;

    // Check horizontal lines
    for(i = 0; i < SIZE; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }

    // Check vertical lines
    for(i = 0; i < SIZE; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // Check diagonal lines
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

void play_game(int player) {
    int board[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int choice;
    int i, j;

    srand(time(0));

    while(1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn\n", player);

        if(player == 1)
            printf("Enter your choice (1-%d): ", SIZE*SIZE-1);
        else
            printf("Enter your choice (1-%d): ", SIZE*SIZE-2);

        scanf("%d", &choice);
        choice--;

        if(board[choice/3][choice%3]!= 0) {
            printf("Invalid move\n");
            continue;
        }

        board[choice/3][choice%3] = player;

        if(check_win(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        if(player == 1)
            player = 2;
        else
            player = 1;
    }
}

int main() {
    int choice;

    printf("Welcome to Tic Tac Toe!\n");
    printf("1. Play Game\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        play_game(1);
    } else if(choice == 2) {
        exit(0);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}