//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program visualizes the Fibonacci sequence up to the nth term provided by the user.
 * It uses a scientific style output to show the sequence as well as the golden ratio.
 */

int main() {
    int n, i;
    double golden_ratio, prev, curr, next;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Initialize first two terms of Fibonacci sequence
    prev = 0;
    curr = 1;

    // Print header for scientific output
    printf("Term\tValue\t\tGolden Ratio\n");
    printf("----\t-----\t\t------------\n");

    // Iterate through the sequence and calculate the golden ratio
    for (i = 1; i <= n; i++) {
        // Print the current term and value
        printf("%d\t%.0f\t\t", i, curr);

        if (i == 1) {
            // For the first term, the golden ratio is undefined
            printf("N/A\n");

        } else if (i == 2) {
            // For the second term, the ratio is 1
            printf("1.0000\n");
            prev = curr;

        } else {
            // For subsequent terms, calculate the next value and the golden ratio
            next = prev + curr;
            golden_ratio = curr / prev;
            printf("%.4f\n", golden_ratio);

            // Update previous and current values for next iteration
            prev = curr;
            curr = next;
        }
    }

    return 0;
}