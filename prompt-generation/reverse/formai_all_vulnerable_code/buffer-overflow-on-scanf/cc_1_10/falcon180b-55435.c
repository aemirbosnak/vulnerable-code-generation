//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000

struct term {
    int index;
    int value;
};

void print_fibonacci(struct term *terms, int num_terms) {
    for (int i = 0; i < num_terms; i++) {
        printf("%d ", terms[i].value);
    }
    printf("\n");
}

struct term *generate_fibonacci(int num_terms) {
    struct term *terms = malloc(sizeof(struct term) * num_terms);
    terms[0].index = 0;
    terms[0].value = 0;
    terms[1].index = 1;
    terms[1].value = 1;

    for (int i = 2; i < num_terms; i++) {
        terms[i].index = i;
        terms[i].value = fibonacci(i);
    }

    return terms;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num_terms;
    printf("Enter the number of terms to generate (<= %d): ", MAX_TERMS);
    scanf("%d", &num_terms);

    if (num_terms > MAX_TERMS) {
        printf("Error: Number of terms must be <= %d\n", MAX_TERMS);
        return 1;
    }

    struct term *terms = generate_fibonacci(num_terms);
    print_fibonacci(terms, num_terms);

    free(terms);
    return 0;
}