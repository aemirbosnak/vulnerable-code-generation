//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 10000

int term_count = 0;
int fib_terms[MAX_TERMS];
int term_width = 0;

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random term for the Fibonacci sequence
int generate_term() {
    int term = fib_terms[term_count - 1] + rand_int(0, 100);
    while (term <= 0) {
        term = fib_terms[term_count - 1] + rand_int(0, 100);
    }
    fib_terms[term_count] = term;
    term_count++;
    return term;
}

// Function to print the Fibonacci sequence
void print_fibonacci() {
    printf("Fibonacci sequence:\n");
    for (int i = 0; i < term_count; i++) {
        printf("%d ", fib_terms[i]);
    }
    printf("\n");
}

// Function to calculate the width of each term in the sequence
void calculate_term_width() {
    int max_width = 0;
    for (int i = 0; i < term_count; i++) {
        int term_len = (int)log10(fib_terms[i]) + 1;
        if (term_len > max_width) {
            max_width = term_len;
        }
    }
    term_width = max_width;
}

// Function to print the Fibonacci sequence with each term centered
void print_centered_fibonacci() {
    printf("Fibonacci sequence:\n");
    for (int i = 0; i < term_count; i++) {
        int term_len = (int)log10(fib_terms[i]) + 1;
        printf("%*d ", term_width - term_len, fib_terms[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_TERMS; i++) {
        generate_term();
    }
    calculate_term_width();
    print_centered_fibonacci();

    return 0;
}