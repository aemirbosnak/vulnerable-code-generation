//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: ultraprecise
#include <stdio.h>

void printHeart(int size) {
    int i, j;

    // Top part of the heart
    for (i = size / 2; i <= size; i += 2) {
        // Print leading spaces
        for (j = 1; j < size - i; j += 2) {
            printf(" ");
        }
        // Print first part of heart
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        // Print spaces between the two halves of heart
        for (j = 1; j <= size - i; j++) {
            printf(" ");
        }
        // Print second part of heart
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Bottom part of the heart
    for (i = size; i >= 1; i--) {
        // Print leading spaces for the bottom part
        for (j = i; j < size; j++) {
            printf(" ");
        }
        // Print stars
        for (j = 1; j <= (i * 2) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int size;
    
    // Prompt user for size of the heart
    printf("Enter the size of the heart (even number recommended): ");
    scanf("%d", &size);

    // Ensure the size is positive
    if(size <= 0) {
        printf("Size must be a positive integer.\n");
        return 1;
    }

    // Size correction for an even heart shape
    if(size % 2 != 0) {
        printf("Please enter an even number for a more symmetrical heart.\n");
        size++; // Increment size to make it even
    }

    // Print the heart pattern
    printHeart(size);

    return 0;
}