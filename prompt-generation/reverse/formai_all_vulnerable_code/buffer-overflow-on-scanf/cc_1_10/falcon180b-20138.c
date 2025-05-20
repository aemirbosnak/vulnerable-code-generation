//Falcon-180B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int row;
    int col;
    int value;
} Cell;

Cell data[MAX_ROWS][MAX_COLS];

void generateRandomData(int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j].value = rand() % 10;
        }
    }
}

void printData() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", data[i][j].value);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Data Mining Retro Program!\n");
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Input values are too large.\n");
        return 1;
    }

    generateRandomData(rows, cols);
    printf("\nRandom data generated:\n");
    printData();

    return 0;
}