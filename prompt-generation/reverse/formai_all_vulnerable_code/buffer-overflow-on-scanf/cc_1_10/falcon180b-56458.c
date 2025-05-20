//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBERS 15

void generateCard(int card[ROWS][COLS]) {
    int i, j, num;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            do {
                num = rand() % MAX_NUMBERS;
            } while (num == 0);
            card[i][j] = num;
        }
    }
}

void printCard(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void checkWin(int card[ROWS][COLS], int num) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == num) {
                printf("Bingo! You won!\n");
                return;
            }
        }
    }
}

int main() {
    int card[ROWS][COLS];
    int i, j, num;
    srand(time(NULL));
    generateCard(card);
    printCard(card);
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        checkWin(card, num);
    }
    return 0;
}