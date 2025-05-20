//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int num;
    int *fibSeq;

    printf("Enter the number of elements in the Fibonacci sequence: ");
    scanf("%d", &num);

    // Allocate memory for Fibonacci sequence array
    fibSeq = (int *)calloc(num, sizeof(int));
    if (!fibSeq) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Populate Fibonacci sequence array
    fibSeq[0] = 0;
    if (num > 1) {
        fibSeq[1] = 1;
        for (int i = 2; i < num; i++) {
            fibSeq[i] = fibSeq[i-1] + fibSeq[i-2];
        }
    }

    // Find maximum number of digits in a term of the sequence
    int maxSize = 1;
    for (int i = 0; i < num; i++) {
        int digits = 1;
        int n = fibSeq[i];
        while ((n /= 10) > 0) {
            digits++;
        }
        if (digits > maxSize) {
            maxSize = digits;
        }
    }

    // Print Fibonacci sequence
    printf("\nFibonacci sequence:");
    for (int i = 0; i < num; i++) {
        printf("\n%*d: ", maxSize, fibSeq[i]);
        for (int j = 0; j < fibSeq[i]; j++) {
            printf("*");
        }
    }
    printf("\n");

    // Free memory allocated for Fibonacci sequence array
    free(fibSeq);

    return 0;
}