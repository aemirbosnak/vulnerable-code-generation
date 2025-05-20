//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBingo(int board[][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            board[i][j] = rand() % 50 + 1;
        }
    }
}

void printBingo(int board[][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkBingo(int board[][5], int player[][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == player[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int board[5][5];
    int player[5][5];
    
    srand(time(NULL));
    generateBingo(board);
    printBingo(board);
    
    printf("Enter your numbers: ");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d", &player[i][j]);
        }
    }
    printf("\n");
    
    if(checkBingo(board, player)) {
        printf("You got a Bingo!\n");
    } else {
        printf("No Bingo, better luck next time.\n");
    }
    
    return 0;
}