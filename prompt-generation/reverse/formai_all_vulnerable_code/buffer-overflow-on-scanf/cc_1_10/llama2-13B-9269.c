//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

void printPattern(int size);
void printStar(int size);
void printSpiral(int size);

int main() {
    int size;

    printf("Welcome to the C Pattern Printing Program!\n");
    printf("Please enter the size of the pattern: ");
    scanf("%d", &size);

    if (size < MIN_VALUE || size > MAX_VALUE) {
        printf("Invalid size. Please enter a value between %d and %d.\n", MIN_VALUE, MAX_VALUE);
        return 1;
    }

    printPattern(size);

    return 0;
}

void printPattern(int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printStar(int size) {
    int i;

    for (i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSpiral(int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}