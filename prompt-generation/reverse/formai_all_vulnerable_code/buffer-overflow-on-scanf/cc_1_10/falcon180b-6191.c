//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBingoCard(int card[5][5], int freeSpace) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == freeSpace && j == freeSpace) {
                card[i][j] = 0;
            } else {
                card[i][j] = rand() % 15 + 1;
            }
        }
    }
}

void printBingoCard(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int checkBingo(int card[5][5]) {
    int i, j, count = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
    }
    if (count == 24) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(0));
    int card[5][5], freeSpace, i, j, win = 0;
    printf("Welcome to Bingo Simulator!\n");
    printf("How many players? ");
    scanf("%d", &freeSpace);
    generateBingoCard(card, freeSpace);
    printf("\n");
    while (win == 0) {
        printf("Current state of the card:\n");
        printBingoCard(card);
        printf("\n");
        int calledNumber;
        printf("Enter a number between 1 and 75: ");
        scanf("%d", &calledNumber);
        int row, col;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (card[i][j] == calledNumber) {
                    card[i][j] = 0;
                    if (i == freeSpace && j == freeSpace) {
                        win = 1;
                    }
                }
            }
        }
    }
    printf("Congratulations! You won!\n");
    return 0;
}