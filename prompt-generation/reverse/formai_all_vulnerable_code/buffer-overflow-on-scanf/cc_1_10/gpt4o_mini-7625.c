//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 20

void generateFibonacci(int terms, int *fibArray) {
    if (terms < 1) return; // No terms to generate
    
    fibArray[0] = 0; // First Fibonacci number
    if (terms > 1) {
        fibArray[1] = 1; // Second Fibonacci number
        for (int i = 2; i < terms; i++) {
            fibArray[i] = fibArray[i-1] + fibArray[i-2]; // Compute next Fibonacci number
        }
    }
}

void displayFibonacci(int terms, int *fibArray) {
    printf("\n--- FIBONACCI SEQUENCE UP TO %d TERMS ---\n", terms);
    printf("Index:\t");
    for (int i = 0; i < terms; i++) {
        printf("%d\t", i);
    }
    printf("\n\nValues:\t");
    for (int i = 0; i < terms; i++) {
        printf("%d\t", fibArray[i]);
    }
    printf("\n");
}

void visualizeFibonacci(int terms, int *fibArray) {
    printf("\n--- VISUALIZE THE FIBONACCI SEQUENCE! ---\n");
    for (int i = 0; i < terms; i++) {
        printf("\nTerm %d: ", i);
        for (int j = 0; j < fibArray[i]; j++) {
            printf("*"); // Represent Fibonacci values with asterisks
        }
        printf(" (%d)", fibArray[i]);
    }
    printf("\n");
}

int main() {
    int terms;
    int fibArray[MAX_TERMS];

    printf("WELCOME TO THE SHOCKING FIBONACCI SEQUENCE VISUALIZER!\n");
    printf("Enter the number of terms to visualize (max %d): ", MAX_TERMS);
    scanf("%d", &terms);

    if (terms > MAX_TERMS) {
        printf("ALERT! Exceeds maximum limit. Adjusting to %d terms.\n", MAX_TERMS);
        terms = MAX_TERMS;
    }

    generateFibonacci(terms, fibArray);
    displayFibonacci(terms, fibArray);
    visualizeFibonacci(terms, fibArray);

    printf("\nThat's how Fibonacci numbers progress! Mind-blowing, isn’t it?\n");
    return 0;
}