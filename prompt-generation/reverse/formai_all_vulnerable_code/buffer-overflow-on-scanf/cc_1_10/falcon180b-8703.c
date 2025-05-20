//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: protected
// C Prime Number Generator example program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000000 // maximum number to check

int is_prime(int n); // function to check if a number is prime

int main() {
    int num, count = 0;
    printf("Enter a number to generate prime numbers up to: ");
    scanf("%d", &num);

    // check if input is valid
    if (num <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // generate prime numbers up to input
    for (int i = 2; i <= num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        if (count >= 10) { // limit to 10 prime numbers
            break;
        }
    }

    printf("\n");
    return 0;
}

// function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }

    // check for divisors up to the square root of n
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}
// End of code snippet ```