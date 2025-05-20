//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void romeoJulietFibonacci(int n) {
    int a = 0, b = 1, c;
    
    printf("O there, gentle soul, lend me thy ears,\n");
    printf("For I shall weave a tale of Fibonacci's flares.\n\n");

    printf("In the hearts of men, two lovers do entwine,\n");
    printf("So too does the sequence, a pattern divine.\n");
    
    printf("The first two numbers, simple and true:\n");
    printf("0 (the humble beggar), and 1 (the hope anew).\n\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("A sequel begins, where a gleam meets the dusk:\n");
            printf("F(%d) = %d (a tale of silence yet)\n", i, a);
        } else if (i == 1) {
            printf("In sweet embrace, they share a spark:\n");
            printf("F(%d) = %d (the dawn does hark)\n", i, b);
        } else {
            c = a + b;
            printf("But hark! They spin, in fate's design:\n");
            printf("F(%d) = %d (the sum of thespians who entwine)\n", i, c);
            a = b;
            b = c;
        }
    }
    
    printf("\nThus unfolds the Fibonacci, a tale so grand,\n");
    printf("In each number, a story, in each sum, a band.\n");
    printf("Through love and loss, and joy and strife,\n");
    printf("This sequence portrays the dance of life.\n");
}

int main() {
    int n;

    printf("O fair user, how many terms dost thou seek?\n");
    printf("Speak softly, and I shall render the mystique:\n");
    scanf("%d", &n);
    
    // Validation of the input
    if (n < 0) {
        printf("A tragedy unfolds, for a negative count cannot be!\n");
        return EXIT_FAILURE;
    }

    romeoJulietFibonacci(n);

    printf("Thus ends our tale of numbers entwined,\n");
    printf("I bid thee farewell, dear friend, be kind.\n");

    return EXIT_SUCCESS;
}