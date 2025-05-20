//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>

// function to check if a number is prime
bool isPrime(int num)
{
    // return false if num is 1 or less than 1
    if (num <= 1) {
        return false;
    }

    // check if num is divisible by any number less than it
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    // if num is not divisible by any number less than it, it is prime
    return true;
}

int main()
{
    int num;

    printf("-- CYBERPUNK PRIME NUMBER GENERATOR --\n\n");

    // ask user for input
    printf("Enter a number to generate primes up to: ");

    // get user input
    scanf("%d", &num);

    // print header for prime numbers
    printf("\n-- PRIME NUMBERS UP TO %d --\n\n", num);

    // loop through numbers from 2 to user input
    for (int i = 2; i <= num; i++) {
        if (isPrime(i)) {
            // if number is prime, print it out in green text
            printf("\033[0;32m%d \033[0m", i);
        } else {
            // if number is not prime, print it out in red text
            printf("\033[0;31m%d \033[0m", i);
        }
    }

    return 0;
}