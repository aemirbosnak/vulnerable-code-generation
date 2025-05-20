//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci Sequence with %d terms:\n\n", n);
    printf("Index      | Value     | Visual Representation\n");
    printf("-----------|-----------|----------------------\n");

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%-11d | %-10d | ", i, a);
            for (int j = 0; j < a; j++) printf("#");
            printf("\n");
            continue;
        }
        if (i == 1) {
            printf("%-11d | %-10d | ", i, b);
            for (int j = 0; j < b; j++) printf("#");
            printf("\n");
            continue;
        }
        next = a + b;
        printf("%-11d | %-10d | ", i, next);
        for (int j = 0; j < next; j++) printf("#");
        printf("\n");
        a = b;
        b = next;
    }
    printf("\nEnjoy the sequence and visualization!\n");
}

int getNumberOfTerms() {
    int n;
    printf("Enter the number of Fibonacci terms you'd like to see (greater than 0): ");
    while (1) {
        scanf("%d", &n);
        if (n > 0) {
            break;
        }
        printf("Please enter a positive integer: ");
    }
    return n;
}

int main() {
    printf("🎉 Welcome to the Fibonacci Sequence Visualizer! 🎉\n");
  
    int terms = getNumberOfTerms();
  
    printFibonacci(terms);
    
    printf("Thank you for participating! Remember, numbers can be beautiful! 🌟\n");
    return 0;
}