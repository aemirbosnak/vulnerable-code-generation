//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 10000
#define M 1000

struct complex {
    double real;
    double imag;
};

void ComplexAdd(struct complex *a, struct complex *b) {
    a->real += b->real;
    a->imag += b->imag;
}

void ComplexMul(struct complex *a, struct complex *b) {
    a->real += b->real * b->real - b->imag * b->imag;
    a->imag += b->real * b->imag + b->real * b->real;
}

void ComplexDiv(struct complex *a, struct complex *b) {
    if (b->real == 0 && b->imag == 0) {
        printf("Error: Division by zero!\n");
        return;
    }
    a->real /= b->real;
    a->imag /= b->imag;
}

void ComplexPower(struct complex *a, int n) {
    for (int i = 0; i < n; i++) {
        ComplexMul(a, a);
    }
}

int main() {
    struct complex a, b, c;
    double start_time, end_time;

    // Initialize a, b, and c with random values
    for (int i = 0; i < N; i++) {
        a.real = drand48() * 10 - 5;
        a.imag = drand48() * 10 - 5;
        b.real = drand48() * 10 - 5;
        b.imag = drand48() * 10 - 5;
        c.real = 0;
        c.imag = 0;
    }

    // Warm-up loop
    for (int i = 0; i < M; i++) {
        ComplexAdd(&a, &b);
        ComplexAdd(&c, &c);
    }

    // Measure execution time for addition and multiplication
    start_time = clock();
    for (int i = 0; i < M; i++) {
        ComplexAdd(&a, &b);
    }
    end_time = clock();
    printf("Addition time: %f seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    for (int i = 0; i < M; i++) {
        ComplexMul(&a, &b);
    }
    end_time = clock();
    printf("Multiplication time: %f seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    // Measure execution time for division and power
    start_time = clock();
    for (int i = 0; i < M; i++) {
        ComplexDiv(&a, &b);
    }
    end_time = clock();
    printf("Division time: %f seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    for (int i = 0; i < M; i++) {
        ComplexPower(&a, 10);
    }
    end_time = clock();
    printf("Power time: %f seconds\n", (end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}