//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_between(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a pattern of asterisks
void print_pattern(int width, int height, int border) {
    int i, j;
    for (i = 0; i < border; i++) {
        printf("*");
    }
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 0; i < border; i++) {
        printf("*");
    }
}

// Function to generate a random pattern
void generate_pattern(int width, int height, int min_size, int max_size) {
    int i, j, size;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            size = rand_between(min_size, max_size);
            if (size == 1) {
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
    int width, height, border, min_size, max_size;
    printf("Enter the width of the pattern: ");
    scanf("%d", &width);
    printf("Enter the height of the pattern: ");
    scanf("%d", &height);
    printf("Enter the size of the border: ");
    scanf("%d", &border);
    printf("Enter the minimum size of the asterisks: ");
    scanf("%d", &min_size);
    printf("Enter the maximum size of the asterisks: ");
    scanf("%d", &max_size);
    printf("\n");
    print_pattern(width + 2 * border, height + 2 * border, border);
    printf("\n");
    generate_pattern(width, height, min_size, max_size);
    return 0;
}