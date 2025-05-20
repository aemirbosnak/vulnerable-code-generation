//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000
#define MAX_DIGITS 1000

int main() {
    int num_terms;
    int max_digits = 0;
    int terms[MAX_TERMS];
    int digits[MAX_TERMS];
    int i, j;

    srand(time(NULL));
    num_terms = rand() % MAX_TERMS + 1;

    for (i = 0; i < num_terms; i++) {
        terms[i] = rand() % MAX_DIGITS + 1;
        if (terms[i] > max_digits) {
            max_digits = terms[i];
        }
    }

    printf("Enter the number of Fibonacci terms you want to visualize: ");
    scanf("%d", &num_terms);

    if (num_terms > MAX_TERMS) {
        printf("Error: Number of terms exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter the maximum number of digits per term: ");
    scanf("%d", &max_digits);

    if (max_digits > MAX_DIGITS) {
        printf("Error: Maximum digits per term exceeds maximum limit.\n");
        return 1;
    }

    printf("\n");
    for (i = 0; i < num_terms; i++) {
        printf("Fibonacci term %d: ", i + 1);
        for (j = 0; j < terms[i]; j++) {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}