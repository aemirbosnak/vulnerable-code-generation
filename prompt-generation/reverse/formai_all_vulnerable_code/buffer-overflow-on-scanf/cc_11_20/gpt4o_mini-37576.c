//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void printPixelArt(int size) {
    int i, j;

    // Ensure that size is within bounds
    if (size < 2 || size > MAX_SIZE) {
        printf("Size must be between 2 and %d\n", MAX_SIZE);
        return;
    }

    // Print top of the face
    for (i = 0; i < size; i++) {
        for (j = 0; j < size * 2; j++) {
            if (i == 0) {
                if (j == size || j == (size * 2 - 1)) {
                    printf(" ");
                } else {
                    printf("O");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print eyes
    for (i = 0; i < size; i++) {
        for (j = 0; j < size * 2; j++) {
            if (i == size / 4) {
                if (j == size / 2 - 1 || j == size / 2 + 1) {
                    printf("O");
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print mouth
    for (i = size / 4; i < size / 2; i++) {
        for (j = 0; j < size * 2; j++) {
            if (i == size / 2 - 1) {
                if (j >= size / 2 - 2 && j <= size / 2 + 2) {
                    printf("O");
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print bottom of the face
    for (i = 0; i < size; i++) {
        for (j = 0; j < size * 2; j++) {
            if (i == size - 1) {
                if (j == 0 || j == (size * 2 - 1)) {
                    printf(" ");
                } else {
                    printf("_");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Welcome to the Pixel Art Generator!\n");
    printf("Please enter a size for your pixel art (2 to %d): ", MAX_SIZE);
    scanf("%d", &size);

    printPixelArt(size);

    return 0;
}