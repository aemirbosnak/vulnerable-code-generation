//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void generate_fibonacci_sequence(int terms) {
    printf("Fibonacci Sequence for %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int sum_of_fibonacci(int terms) {
    if (terms <= 0)
        return 0;
    return fibonacci(terms - 1) + sum_of_fibonacci(terms - 1);
}

int count_even_odd(int terms, int *even_count, int *odd_count) {
    if (terms <= 0)
        return 0;
    int fib_num = fibonacci(terms - 1);
    if (fib_num % 2 == 0)
        (*even_count)++;
    else
        (*odd_count)++;
    count_even_odd(terms - 1, even_count, odd_count);
}

int main() {
    int terms;
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &terms);

    generate_fibonacci_sequence(terms);
    
    int sum = sum_of_fibonacci(terms);
    printf("Sum of first %d Fibonacci terms: %d\n", terms, sum);

    int even_count = 0, odd_count = 0;
    count_even_odd(terms, &even_count, &odd_count);
    printf("Count of even terms: %d\n", even_count);
    printf("Count of odd terms: %d\n", odd_count);

    return 0;
}