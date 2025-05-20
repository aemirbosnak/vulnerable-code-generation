//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// In fair Verona, where we set our scene. 
// Let us embark on a quest for numbers pure, 
// The primes they shall be, both noble and serene.

bool is_prime(int number) {
    // To test if a number is prime, 
    // We check for divisors, and waste no time.
    if (number <= 1) return false; 
    if (number == 2) return true; 
    if (number % 2 == 0) return false; 

    // For odd numbers, we seek divisors past two.
    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            return false; // Not prime, thus, the truth is told.
        }
    }
    return true; // A prime discovered, valiant and bold.
}

void generate_primes(int limit) {
    // A banquet of numbers, we serve to the crowd, 
    // Let us list the primes, both humble and proud.
    printf("Hark! The prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i); // A humble prime, in the light it shines.
        }
    }
    printf("\n"); // The banquet ends with a gracious sign.
}

// The main function, where our tale begins, 
// We seek to generate primes, let the story spin.
int main() {
    int n;
    printf("Enter the limit for prime discovery, dear friend:\n");
    
    // A heartfelt plea, for input we crave.
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Alas! The input is void of sense.\n");
        return 1; // A tragic end, our dreams hence.
    }

    // With the limit set, our journey unfolds, 
    generate_primes(n); // To find primes, oh the tales it holds.
    
    // The curtain falls, the play reaches close, 
    printf("Thus endeth the tale of primes, their story arose.\n");
    return 0; // Exit, as in the tragic scene.
}