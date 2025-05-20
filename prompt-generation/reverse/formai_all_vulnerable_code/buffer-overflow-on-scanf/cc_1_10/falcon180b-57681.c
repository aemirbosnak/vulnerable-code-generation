//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000000 // Maximum number to check for primality

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate prime numbers
void generate_primes(int start_num, int end_num) {
    int count = 0;
    for (int i = start_num; i <= end_num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        if (count == 10) {
            printf("\n");
            count = 0;
        }
    }
}

int main() {
    int start_num, end_num;

    // Get input from user
    printf("Enter start number: ");
    scanf("%d", &start_num);
    printf("Enter end number: ");
    scanf("%d", &end_num);

    // Check if input is valid
    if (start_num > end_num || start_num < 2 || end_num > MAX_NUM) {
        printf("Invalid input\n");
        return 1;
    }

    // Generate prime numbers
    printf("Prime numbers between %d and %d:\n", start_num, end_num);
    generate_primes(start_num, end_num);

    return 0;
}