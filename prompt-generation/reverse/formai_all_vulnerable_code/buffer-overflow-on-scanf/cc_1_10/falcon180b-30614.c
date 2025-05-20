//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    char board[SIZE][SIZE];
    int i, j;
    srand(time(NULL));
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }
    int x, y, flag = 0, count = 0;
    printf("Welcome to the Memory Game!\n");
    printf("There are %d boxes in the game.\n", SIZE*SIZE);
    printf("You need to find %d pairs of matching symbols.\n", SIZE);
    int box1, box2;
    while(flag == 0) {
        printf("Player 1's turn:\n");
        scanf("%d %d", &x, &y);
        if(board[x][y]!= '*') {
            printf("You have already chosen this box!\n");
        } else {
            board[x][y] = (char)(rand() % 26 + 'A');
            count++;
            if(count == SIZE) {
                flag = 1;
            }
        }
    }
    printf("Player 2's turn:\n");
    while(flag == 0) {
        scanf("%d %d", &box1, &box2);
        if(board[box1][box2] == '*') {
            printf("You have not chosen this box yet!\n");
        } else if(board[box1][box2]!= board[0][0]) {
            printf("The symbols do not match!\n");
        } else {
            flag = 1;
        }
    }
    if(flag == 1) {
        printf("Congratulations! You have won the game!\n");
    } else {
        printf("Sorry, you have lost the game.\n");
    }
    return 0;
}