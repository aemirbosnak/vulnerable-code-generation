//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 1000

typedef struct {
    int term;
    int index;
} FibonacciTerm;

void generateFibonacciSequence(int numTerms, FibonacciTerm* terms) {
    terms[0].term = 0;
    terms[0].index = -1;
    terms[1].term = 1;
    terms[1].index = 0;

    for (int i = 2; i < numTerms; i++) {
        FibonacciTerm currentTerm = {0, 0};
        int j = i - 2;
        while (terms[j].term <= terms[j-1].term + terms[j-2].term) {
            currentTerm.term = terms[j].term + terms[j-1].term;
            currentTerm.index = i;
            j++;
        }
        terms[i] = currentTerm;
    }
}

void printFibonacciSequence(FibonacciTerm* terms, int numTerms) {
    for (int i = 0; i < numTerms; i++) {
        printf("%d ", terms[i].term);
    }
    printf("\n");
}

int main() {
    int numTerms;
    printf("Enter the number of terms to generate: ");
    scanf("%d", &numTerms);

    if (numTerms <= 0 || numTerms > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    FibonacciTerm terms[MAX_TERMS];
    generateFibonacciSequence(numTerms, terms);
    printFibonacciSequence(terms, numTerms);

    return 0;
}