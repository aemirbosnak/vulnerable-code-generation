//FormAI DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 4

void display(char board[BOARD_SIZE][BOARD_SIZE]);
int checkWin(char board[BOARD_SIZE][BOARD_SIZE]);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {0}, ch;
    int x1, x2, y1, y2, swapCount = 0;
    int row, col, picked[BOARD_SIZE * BOARD_SIZE] = {0}, n = 0;
    int i, j, find = 0;
    srand(time(NULL));
    printf("Welcome to the Memory Game\n\n");
    printf("Enter any character to begin...\n");
    scanf("%c", &ch);
    while(1) {
        if(swapCount == BOARD_SIZE * BOARD_SIZE) {
            printf("Congratulations! You have won!\n");
            break;
        }
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
        while(board[row][col] != 0) {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        }
        board[row][col] = swapCount / 2 + 'A';
        swapCount++;
        display(board);
        printf("\nEnter the row and column of the two cards that you want to flip: ");
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 < 0 || x1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if(board[x1][y1] == 0 || board[x2][y2] == 0) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if(x1 == x2 && y1 == y2) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        printf("\n");
        display(board);
        if(board[x1][y1] == board[x2][y2]) {
            printf("Match! Congratulations!\n");
            board[x1][y1] = board[x2][y2] = 0;
        } else {
            printf("Not a match. Please try again.\n");
        }
    }
    return 0;
}

void display(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j] == 0 ? '*' : board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}