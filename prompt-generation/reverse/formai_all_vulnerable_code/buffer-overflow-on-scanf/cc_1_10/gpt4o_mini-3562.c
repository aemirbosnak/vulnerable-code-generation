//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_intro() {
    printf("==============================================\n");
    printf("          Prime Number Generator              \n");
    printf("==============================================\n");
    printf("This program generates all prime numbers up to a given limit.\n");
    printf("Enter a positive integer to find all primes up to that number.\n");
    printf("==============================================\n");
}

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    print_intro();
    
    int limit;
    
    printf("Enter the upper limit: ");
    if (scanf("%d", &limit) != 1 || limit <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }
    
    generate_primes(limit);
    
    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}