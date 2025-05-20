//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

void print_matrix(int matrix[SIZE][SIZE], int player) {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            if(matrix[i][j] == player)
                printf("X ");
            else
                printf("O ");
        }
        printf("\n");
    }
}

int check_winner(int matrix[SIZE][SIZE], int player) {
    int i, j;
    // check rows
    for(i=0; i<SIZE; i++) {
        if(matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player)
            return 1;
    }
    // check columns
    for(j=0; j<SIZE; j++) {
        if(matrix[0][j] == player && matrix[1][j] == player && matrix[2][j] == player)
            return 1;
    }
    // check diagonals
    if(matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player)
        return 1;
    if(matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)
        return 1;
    return 0;
}

int main() {
    int matrix[SIZE][SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice, row, col;
    srand(time(0));
    while(1) {
        system("clear");
        print_matrix(matrix, player);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%d", &row, &col);
        if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && matrix[row][col] == 0) {
            matrix[row][col] = player;
            if(check_winner(matrix, player)) {
                printf("\nPlayer %d wins!\n", player);
                break;
            }
            player =!player;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}