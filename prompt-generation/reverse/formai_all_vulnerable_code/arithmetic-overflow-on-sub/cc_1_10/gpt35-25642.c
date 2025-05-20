//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <time.h>

#define MAX_ITERATIONS 1000000

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Performance testing function
double benchmark(int (*func)(int, int)) {
    double time_taken = 0.0;
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        clock_t t = clock();

        // Random integers between 1 and 1000 for testing purposes
        int a = rand() % 1000 + 1;
        int b = rand() % 1000 + 1;

        func(a, b);

        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;
    }
    return time_taken / MAX_ITERATIONS;
}

int main() {

    srand(time(0));

    // Function pointers for testing add and multiply functions
    int (*add_ptr)(int, int) = &add;
    int (*multiply_ptr)(int, int) = &multiply;

    // Run benchmarking tests on add and multiply functions
    double add_time = benchmark(add_ptr);
    double multiply_time = benchmark(multiply_ptr);

    printf("Add function took %lf seconds to execute on average\n", add_time);
    printf("Multiply function took %lf seconds to execute on average\n", multiply_time);

    return 0;
}