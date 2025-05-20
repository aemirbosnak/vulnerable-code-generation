//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define CARDS 16

int cards[CARDS];
int revealed[ROWS][COLS] = {0};

void shuffle(int *array, int length) {
    int i, j, temp;
    for (i = 0; i < length - 1; i++) {
        j = rand() % (length - i) + i;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j])
                printf("%d ", cards[i * COLS + j]);
            else
                printf("__ ");
        }
        printf("\n");
    }
}

void reveal_card(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || revealed[row][col]) {
        printf("Invalid move! Try again.\n");
        return;
    }

    revealed[row][col] = 1;
    int card = cards[row * COLS + col];
    printf("You revealed card %d.\n", card);
    print_board();

    int check_win();
    if (check_win()) {
        printf("\nCongratulations! You won the game!\n");
        exit(0);
    }
}

int check_win() {
    int i, j, flag = 1;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (revealed[i][j] && cards[i * COLS + j] != (i * COLS + j) % 2 + 1) {
                flag = 0;
                break;
            }
        }
        if (flag)
            break;
        else
            flag = 1;
    }

    return flag;
}

int main() {
    int i;
    srand(time(NULL));

    for (i = 0; i < CARDS; i++)
        cards[i] = i % 2 + 1;

    shuffle(cards, CARDS);

    print_board();

    while (1) {
        int row, col;
        scanf("%d %d", &row, &col);
        reveal_card(row, col);
    }

    return 0;
}