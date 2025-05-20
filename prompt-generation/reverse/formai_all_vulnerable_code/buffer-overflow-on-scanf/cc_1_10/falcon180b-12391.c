//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_WIDTH 80

int main() {
    int num1 = 0, num2 = 1, nextTerm, i, j, n;
    int width;

    // Get the desired width from the user
    printf("Enter the desired width of the Fibonacci sequence: ");
    scanf("%d", &width);

    // Check if the width is within the valid range
    if (width < 1 || width > MAX_WIDTH) {
        printf("Invalid width! Please enter a value between 1 and %d.\n", MAX_WIDTH);
        return 1;
    }

    // Get the number of terms to generate from the user
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    // Check if the number of terms is within the valid range
    if (n < 1 || n > MAX_NUM) {
        printf("Invalid number of terms! Please enter a value between 1 and %d.\n", MAX_NUM);
        return 1;
    }

    // Print the first two terms of the sequence
    printf("Fibonacci Sequence:\n");
    printf("Term\tValue\n");
    printf("----\t-----\n");
    printf("1\t%d\n", num1);
    printf("2\t%d\n", num2);

    // Generate and print the remaining terms of the sequence
    for (i = 2; i < n; i++) {
        nextTerm = num1 + num2;
        num1 = num2;
        num2 = nextTerm;

        printf("%d\t%d\n", i, nextTerm);

        // Check if the width needs to be adjusted
        if ((i - 1) % width == 0) {
            printf("\n");
        }
    }

    return 0;
}