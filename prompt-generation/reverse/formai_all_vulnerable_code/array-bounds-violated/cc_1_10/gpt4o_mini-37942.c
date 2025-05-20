//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define P1 'X'
#define P2 'O'

char b[SIZE][SIZE]; // The board
char turn = P1; // Current turn
int x1, y1, x2, y2; // Coordinates

void init() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            b[i][j] = (i % 2 == j % 2) ? ' ' : ((i < 3) ? P2 : (i > 4) ? P1 : ' ');
}

void print() {
    printf("  a b c d e f g h\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", SIZE - i);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
}

int valid_move(int x1, int y1, int x2, int y2) {
    if(b[x1][y1] != turn || b[x2][y2] != ' ') return 0;
    if(turn == P1) return (y2 - y1 == 1 && abs(x2 - x1) == 1) || (y2 - y1 == 2 && abs(x2 - x1) == 2 && b[(x1 + x2) / 2][(y1 + y2) / 2] == P2);
    return (y1 - y2 == 1 && abs(x1 - x2) == 1) || (y1 - y2 == 2 && abs(x1 - x2) == 2 && b[(x1 + x2) / 2][(y1 + y2) / 2] == P1);
}

void move(int x1, int y1, int x2, int y2) {
    b[x2][y2] = turn;
    b[x1][y1] = ' ';
    if(abs(x2 - x1) == 2) 
        b[(x1 + x2) / 2][(y1 + y2) / 2] = ' ';
}

int main() {
    init();
    while(1) {
        print();
        printf("Turn: %c\n", turn);
        char col1, col2;
        int row1, row2;
        printf("Enter move (e.g. 'a3 b4'): ");
        scanf(" %c%d %c%d", &col1, &row1, &col2, &row2);
        x1 = SIZE - row1; y1 = col1 - 'a';
        x2 = SIZE - row2; y2 = col2 - 'a';

        if(valid_move(x1, y1, x2, y2)) {
            move(x1, y1, x2, y2);
            turn = (turn == P1) ? P2 : P1; // Switch turns
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return 0;
}