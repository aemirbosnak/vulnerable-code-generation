//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 30

// Function to print the pattern
void print_pattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random pattern
void rand_pattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (rand_num(0, 1) == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to animate the pattern
void animate_pattern(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (rand_num(0, 1) == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int choice, rows, cols;

    do {
        printf("Enter the number of rows (1-20): ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > MAX_ROWS);

    do {
        printf("Enter the number of columns (1-30): ");
        scanf("%d", &cols);
    } while (cols < 1 || cols > MAX_COLS);

    printf("Enter your choice:\n");
    printf("1. Print pattern\n");
    printf("2. Random pattern\n");
    printf("3. Animate pattern\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_pattern(rows, cols);
            break;
        case 2:
            rand_pattern(rows, cols);
            break;
        case 3:
            while (1) {
                animate_pattern(rows, cols);
                system("clear");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}