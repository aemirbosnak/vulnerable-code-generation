//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 50
#define MAX_COLS 80

void print_pattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_random_pattern(int rows, int cols) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (rand() % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_gradient_pattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == j) {
                printf("*");
            } else if (i > j) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void print_wave_pattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_spiral_pattern(int rows, int cols) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == j) {
                printf("*");
            } else if ((i + j) % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, rows, cols;
    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    printf("Choose a pattern:\n");
    printf("1. Simple pattern\n");
    printf("2. Random pattern\n");
    printf("3. Gradient pattern\n");
    printf("4. Wave pattern\n");
    printf("5. Spiral pattern\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_pattern(rows, cols);
            break;
        case 2:
            print_random_pattern(rows, cols);
            break;
        case 3:
            print_gradient_pattern(rows, cols);
            break;
        case 4:
            print_wave_pattern(rows, cols);
            break;
        case 5:
            print_spiral_pattern(rows, cols);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}