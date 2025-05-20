//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int color;
    int value;
} Piece;

Piece pieces[12];

void init() {
    srand(time(NULL));

    Position pos;
    int i;
    for (i = 0; i < SIZE; i++) {
        pos.x = 0;
        pos.y = i;
        pieces[i].pos = pos;
        pieces[i].color = (i % 2)? 1 : 0;
        pieces[i].value = (i == 0 || i == 7)? 1 : 0;
    }
}

void print_board() {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", pieces[i].value);
    }
    printf("\n");
}

int check_mate(int color) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (pieces[i].color == color && pieces[i].value == 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    init();

    while (1) {
        print_board();
        printf("Enter your move (row col): ");
        scanf("%d %d", &pieces[0].pos.x, &pieces[0].pos.y);
        int x = pieces[0].pos.x;
        int y = pieces[0].pos.y;

        if (x < 0 || x > 7 || y < 0 || y > 7) {
            printf("Invalid move\n");
            continue;
        }

        if (pieces[y * SIZE + x].color!= 0) {
            printf("Piece already there\n");
            continue;
        }

        pieces[y * SIZE + x].color = 1 - pieces[0].color;
        pieces[y * SIZE + x].value = pieces[0].value;
        pieces[0].color = 1 - pieces[0].color;
        pieces[0].value = 0;

        if (check_mate(1 - pieces[0].color)) {
            printf("Checkmate!\n");
            break;
        }
    }

    return 0;
}