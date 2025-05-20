//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_welcome_message();
int get_user_input();
bool is_prime(int num);
void generate_primes(int limit);

int main() {
    print_welcome_message();
    int limit = get_user_input();
    
    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return 1;
    }
    
    printf("Prime numbers up to %d are:\n", limit);
    generate_primes(limit);
    
    return 0;
}

void print_welcome_message() {
    printf("****************************************\n");
    printf("          Prime Number Generator        \n");
    printf("****************************************\n");
    printf("This program generates all the prime numbers up to a given limit.\n");
}

int get_user_input() {
    int limit;
    printf("Enter the upper limit (integer greater than 1): ");
    while (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Invalid input. Please enter an integer greater than 1: ");
        while(getchar() != '\n'); // clear the input buffer
    }
    return limit;
}

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int limit) {
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}