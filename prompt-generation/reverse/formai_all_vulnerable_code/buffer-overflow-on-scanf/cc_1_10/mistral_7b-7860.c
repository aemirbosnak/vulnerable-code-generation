//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    int row;
    int col;
    char symbol;
} Point;

void print_pattern(Point arr[], int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == arr[j].row && j == arr[j].col) {
                printf("%c", arr[j].symbol);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    Point patterns[MAX_SIZE * MAX_SIZE];

    int n, m, i, j;
    char symbol;

    printf("Enter number of rows and columns for the first pattern: ");
    scanf("%d%d", &n, &m);

    printf("Enter symbol for the first pattern: ");
    scanf(" %c", &symbol);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            patterns[i * m + j].row = i;
            patterns[i * m + j].col = j;
            patterns[i * m + j].symbol = symbol;
        }
    }

    print_pattern(patterns, n * m);

    printf("\nEnter number of rows and columns for the second pattern: ");
    scanf("%d%d", &n, &m);

    if (n * m != MAX_SIZE * MAX_SIZE) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            patterns[i * m + j].row = i;
            patterns[i * m + j].col = j;
            // Generate a unique symbol for the second pattern
            patterns[i * m + j].symbol = 'A' + (i + j) % 26;
        }
    }

    print_pattern(patterns, n * m);

    return 0;
}