//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printCard(int* card) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

int isBingo(int* card) {
    int row, col;
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            if (card[row*5+col] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void markCard(int* card, int num) {
    int row, col;
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            if (card[row*5+col] == num) {
                card[row*5+col] = -1;
            }
        }
    }
}

void generateCard(int* card) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card[i*5+j] = rand() % 16;
        }
    }
}

void playBingo(int* card) {
    int num;
    while (!isBingo(card)) {
        printf("Enter a number between 1 and 15: ");
        scanf("%d", &num);
        markCard(card, num);
        generateCard(card);
        printCard(card);
    }
    printf("Bingo!\n");
}

int main() {
    int card[25];
    generateCard(card);
    playBingo(card);
    return 0;
}