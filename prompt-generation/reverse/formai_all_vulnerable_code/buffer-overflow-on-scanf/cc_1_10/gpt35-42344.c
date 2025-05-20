//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>

// Print the upper half of C pattern
void upper_half(int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        printf("*");
        for (j = 0; j < height - 1; j++) {
            if (i == 0 || j == height - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Print the lower half of C pattern
void lower_half(int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        printf("*");
        for (j = 0; j < height - 1; j++) {
            if (i == height - 1 || j == height - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Main function to print the C pattern
int main() {
    int height;

    printf("Enter the height of the C pattern: ");
    scanf("%d", &height);

    // Upper half
    upper_half(height / 2 + 1);

    // Lower half
    lower_half(height / 2);

    return 0;
}