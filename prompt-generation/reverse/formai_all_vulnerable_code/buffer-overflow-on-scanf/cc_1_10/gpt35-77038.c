//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numTerms, i;

    // Ask user for input
    printf("How many terms of the Fibonacci sequence do you want to see? ");
    scanf("%d", &numTerms);

    // Initialize array with first two terms of sequence
    int sequence[numTerms];
    sequence[0] = 0;
    sequence[1] = 1;

    // Populate array with remaining terms of sequence
    for (i = 2; i < numTerms; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    // Output the sequence visually
    int j, k, maxDigits = 0, numSpaces;
    for (i = 0; i < numTerms; i++) {
        // Find maximum number of digits in any term of sequence
        j = sequence[i];
        k = 0;
        while (j != 0) {
            k++;
            j /= 10;
        }
        if (k > maxDigits) {
            maxDigits = k;
        }
    }
    for (i = 0; i < numTerms; i++) {
        // Output each term with leading spaces to make all terms line up vertically
        numSpaces = maxDigits - 1;
        j = sequence[i];
        while (j != 0) {
            numSpaces--;
            j /= 10;
        }
        for (k = 0; k < numSpaces; k++) {
            printf(" ");
        }
        printf("%d\n", sequence[i]);
    }

    return 0;
}