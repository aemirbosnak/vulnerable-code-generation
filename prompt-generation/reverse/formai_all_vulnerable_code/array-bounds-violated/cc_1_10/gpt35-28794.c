//FormAI DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

void shuffle(int *arr, int n) {
    int temp, pos;
    for(int i = n - 1; i > 0; i--) {
        pos = rand() % i;
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n\n\t\tMEMORY GAME\n\n");
    printf("\t ");
    for(int i = 1; i <= SIZE; i++)
        printf("%d\t", i);
    printf("\n\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d\t", i + 1);
        for(int j = 0; j < SIZE; j++)
            printf("%c\t", board[i][j]);
        printf("\n\n");
    }
}

void playGame(int *gameBoard) {
    int moves = SIZE * SIZE / 2, first, second, count = 0;
    char board[SIZE][SIZE] = {' '};
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++) {
            board[i][j] = 'O';
            if(gameBoard[i * SIZE + j] > (SIZE * SIZE / 2))
                gameBoard[i * SIZE + j] -= SIZE * SIZE / 2;
        }

    while(moves--) {
        printBoard(board);
        printf("\nMake a move\n");
        scanf("%d %d", &first, &second);
        if(gameBoard[(first - 1) * SIZE + second - 1] == gameBoard[(second - 1) * SIZE + first - 1]) {
            board[first - 1][second - 1] = gameBoard[(first - 1) * SIZE + second - 1] + 48;
            board[second - 1][first - 1] = gameBoard[(second - 1) * SIZE + first - 1] + 48;
            count++;
        } else {
            board[first - 1][second - 1] = gameBoard[(first - 1) * SIZE + second - 1] + 48;
            board[second - 1][first - 1] = gameBoard[(second - 1) * SIZE + first - 1] + 48;
            printBoard(board);
            board[first - 1][second - 1] = 'O';
            board[second - 1][first - 1] = 'O';
        }
        if(count == SIZE * SIZE / 2) {
            printBoard(board);
            printf("\nYOU WON!!!\n");
            exit(0);
        }
    }
    printBoard(board);
    printf("\nGAME OVER\n");
}

int main() {
    int board[SIZE * SIZE];
    for(int i = 1, j = 0; i <= SIZE * SIZE; i += 2, j += 2) {
        board[j] = i;
        board[j + 1] = i;
    }
    shuffle(board, SIZE * SIZE);
    playGame(board);
    return 0;
}