//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int number) {
    if (number <= 1) return 0; // 0 and 1 are not prime
    if (number <= 3) return 1; // 2 and 3 are prime

    if (number % 2 == 0 || number % 3 == 0) return 0; // Exclude multiples of 2 and 3

    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return 0;
    }

    return 1;
}

// Function to generate prime numbers in a given range
void generate_primes(int start, int end) {
    int prime_count = 0;
    int prime_sum = 0;

    printf("Prime numbers between %d and %d:\n", start, end);
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            prime_count++;
            prime_sum += num;
        }
    }

    if (prime_count > 0) {
        double average = (double)prime_sum / prime_count;
        printf("\n\nStatistical Summary:\n");
        printf("Total prime numbers found: %d\n", prime_count);
        printf("Sum of prime numbers: %d\n", prime_sum);
        printf("Average of prime numbers: %.2f\n", average);
    } else {
        printf("\nNo prime numbers found in the given range.\n");
    }
}

int main() {
    int start, end;

    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid range! Starting number should be less than or equal to ending number.\n");
        return 1;
    }

    generate_primes(start, end);

    return 0;
}