//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBERS 75

typedef struct {
    int value;
    char *name;
} Number;

void generateCard(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            card[i][j] = rand() % MAX_NUMBERS + 1;
        }
    }
}

int compareNumbers(const void *a, const void *b) {
    const Number *num1 = a;
    const Number *num2 = b;
    return num1->value - num2->value;
}

void printCard(const int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int cards[10][ROWS][COLS];
    Number numbers[MAX_NUMBERS];
    int i, j, k;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < ROWS; j++) {
            for (k = 0; k < COLS; k++) {
                numbers[i * ROWS * COLS + j * COLS + k].value = i * ROWS * COLS + j * COLS + k + 1;
                numbers[i * ROWS * COLS + j * COLS + k].name = malloc(10);
                sprintf(numbers[i * ROWS * COLS + j * COLS + k].name, "Card %d", i + 1);
            }
        }
        generateCard(cards[i]);
    }

    qsort(numbers, MAX_NUMBERS, sizeof(Number), compareNumbers);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < ROWS; j++) {
            for (k = 0; k < COLS; k++) {
                printf("%s ", numbers[i * ROWS * COLS + j * COLS + k].name);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}