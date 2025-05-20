//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to generate a random number between 1 and n
int randomNumber(int n) {
    return rand() % n + 1;
}

// Function to measure the time taken by a function
double measureTime(void (*function)()) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    function();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main() {
    int n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // Calculate the factorial of 1000
    printf("\nCalculating the factorial of 1000...\n");
    double timeTaken = measureTime(factorial);
    printf("Time taken: %lf seconds\n", timeTaken);

    // Generate 1000 random numbers between 1 and 1000
    printf("\nGenerating 1000 random numbers between 1 and 1000...\n");
    for (int i = 0; i < n; i++) {
        int random = randomNumber(1000);
        printf("%d ", random);
    }
    printf("\n");

    return 0;
}