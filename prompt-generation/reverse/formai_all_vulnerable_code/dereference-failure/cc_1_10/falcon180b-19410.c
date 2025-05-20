//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v, int capacity) {
    v->data = malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_push(Vector *v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int vector_pop(Vector *v) {
    if (v->size == 0) {
        return -1;
    }
    return v->data[--v->size];
}

int vector_peek(Vector *v, int index) {
    if (index >= v->size) {
        return -1;
    }
    return v->data[index];
}

int vector_size(Vector *v) {
    return v->size;
}

void vector_free(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int n = rand() % 1000 + 2; // generate a random prime number between 2 and 1000
    printf("Generating prime numbers up to %d...\n", n);
    Vector primes;
    vector_init(&primes, 1000); // initialize a vector with a capacity of 1000
    vector_push(&primes, 2); // add the first prime number to the vector
    int count = 1;
    while (vector_size(&primes) < n) {
        int num = rand() % n + 2; // generate a random number between 2 and n
        if (is_prime(num)) {
            vector_push(&primes, num); // add the prime number to the vector
            count++;
        }
    }
    printf("Found %d prime numbers:\n", count);
    for (int i = 0; i < vector_size(&primes); i++) {
        printf("%d ", vector_peek(&primes, i));
    }
    printf("\n");
    vector_free(&primes); // free the memory used by the vector
    return 0;
}