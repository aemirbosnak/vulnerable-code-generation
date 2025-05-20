//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int board[3][3];
int player, turn;

int win(int a, int b, int c, int d, int e, int f, int g, int h) {
    if (a == b && b == c && c == d || a == e && e == f && f == g || a == h && h == g && g == f)
        return 1;
    if (a == d && d == f && f == g || a == h && h == g && g == f)
        return 1;
    if (a == e && e == h && h == g || a == f && f == h && h == g)
        return 1;
    if (b == d && d == f && f == h || b == e && e == h && h == g || b == g && g == f && f == e)
        return 1;
    if (c == d && d == f && f == g || c == e && e == h && h == g || c == g && g == f && f == e)
        return 1;
    if (b == h && h == g && g == f || b == e && e == h && h == g)
        return 1;
    return 0;
}

int isFull(int a, int b, int c, int d, int e, int f, int g, int h) {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == 0 || board[i][1] == 0 || board[i][2] == 0)
            return 0;
    }
    return 1;
}

int isBoardFull(int a, int b, int c, int d, int e, int f, int g, int h) {
    if (isFull(a, b, c, d, e, f, g, h) || isFull(a, b, c, d, e, f, g, h))
        return 1;
    return 0;
}

void printBoard(int a, int b, int c, int d, int e, int f, int g, int h) {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" | ");
        for (int j = 0; j < 3; j++) {
            printf("%d | ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int getInput(int a, int b, int c, int d, int e, int f, int g, int h) {
    int i;
    printf("Enter the row: ");
    scanf("%d", &i);
    if (board[i][0] == 0) {
        board[i][0] = player;
        return 1;
    } else
        return 0;
}

int main() {
    int a, b, c, d, e, f, g, h;
    player = 1;
    turn = 1;
    printf("Welcome to Tic Tac Toe!\n");
    while (!isBoardFull(a, b, c, d, e, f, g, h)) {
        printBoard(a, b, c, d, e, f, g, h);
        if (turn % 2 == 0) {
            if (getInput(a, b, c, d, e, f, g, h) == 1)
                player = 2;
            else
                player = 1;
        } else {
            if (getInput(a, b, c, d, e, f, g, h) == 1)
                player = 1;
            else
                player = 2;
        }
        if (win(a, b, c, d, e, f, g, h) || win(a, b, c, d, e, f, g, h) || win(a, b, c, d, e, f, g, h)) {
            if (win(a, b, c, d, e, f, g, h))
                printf("Player %d wins!\n", win(a, b, c, d, e, f, g, h));
            else if (win(a, b, c, d, e, f, g, h))
                printf("Player %d wins!\n", win(a, b, c, d, e, f, g, h));
            else
                printf("It's a draw!\n");
            break;
        }
        turn++;
    }
    if (isBoardFull(a, b, c, d, e, f, g, h))
        printf("It's a draw!\n");
    return 0;
}