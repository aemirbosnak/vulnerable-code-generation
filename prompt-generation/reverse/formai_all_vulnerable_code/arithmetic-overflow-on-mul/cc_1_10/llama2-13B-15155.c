//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_VALUE -1000000
#define MAX_VALUE 1000000

// Function to generate a random number between min and max
int random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // if num is divisible by i, return 0
    }
    return 1; // if num is not divisible by any of 2 to num-1, it is prime
}

// Function to find the largest prime factor of a number
int largest_prime_factor(int num) {
    int prime = num; // start with the given number
    while (prime > 1) {
        if (is_prime(prime)) {
            if (prime * prime <= num) break; // if we find a prime factor, break
            num /= prime; // reduce num by the found prime factor
        }
        prime--; // decrease prime by 1 to try the next one
    }
    return prime; // return the largest prime factor of num
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int num1, num2, largest_factor;

    // Exercise 1: Generate two random numbers and find their product
    num1 = random_num(MIN_VALUE, MAX_VALUE);
    num2 = random_num(MIN_VALUE, MAX_VALUE);
    largest_factor = num1 * num2;
    printf("The product of two random numbers is: %d\n", largest_factor);

    // Exercise 2: Generate a random number and find its largest prime factor
    num1 = random_num(MIN_VALUE, MAX_VALUE);
    largest_factor = largest_prime_factor(num1);
    printf("The largest prime factor of a random number is: %d\n", largest_factor);

    // Exercise 3: Generate a random number between 1 and 100, and find its square root
    num1 = random_num(1, 100);
    int square_root = sqrt(num1);
    printf("The square root of a random number between 1 and 100 is: %d\n", square_root);

    return 0;
}