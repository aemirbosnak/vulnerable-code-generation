//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main() {
    // Print a curious message
    printf("Hello curious folks! Let's print a unique pattern.\n");

    // Get user input for pattern size
    int size;
    printf("Enter size of pattern (must be odd): ");
    scanf("%d", &size);

    // Check if size is odd
    if(size % 2 == 0) {
        printf("Please enter an odd number for the size.\n");
        exit(0);
    }

    // Initialize variables for pattern
    int i, j, k, n;
    n = size / 2 + 1;

    // Print pattern
    for(i = 1; i <= size; i++) {
        if(i <= n) {
            // Print left side of pattern
            for(j = 1; j <= n - i; j++)
                printf(" ");

            for(k = 1; k <= 2 * i - 1; k++)
                printf("*");

            printf("\n");
        } else {
            // Print right side of pattern
            for(j = 1; j <= i - n; j++)
                printf(" ");

            for(k = 1; k <= 2 * (size - i) + 1; k++)
                printf("*");

            printf("\n");
        }
    }

    // Print a goodbye message
    printf("Hope you enjoyed this unique C pattern!\n");

    return 0;
}