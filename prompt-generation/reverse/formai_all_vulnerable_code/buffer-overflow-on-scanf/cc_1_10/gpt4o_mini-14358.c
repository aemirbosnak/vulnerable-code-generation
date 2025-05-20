//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>
#include <stdbool.h>

// Welcome to the Prime Number Circus! 🎪
// The greatest show on Earth where numbers defy divisibility!
void displayprimes(int limit) {
    printf("🎩 🎉 Welcome to the Prime Number Circus! 🎉 🎩\n");
    printf("We will be generating prime numbers up to: %d\n\n", limit);
    
    int primeCount = 0;
    printf("The prime numbers are:\n");
    
    for (int num = 2; num <= limit; num++) {
        bool isPrime = true; // Assume the number is a prime until proven guilty!

        // Let's check if 'num' has any divisors other than 1 and itself.
        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            // If 'num' can be divided evenly by 'divisor', it's not a prime! 🚫
            if (num % divisor == 0) {
                isPrime = false; // Oh no! Caught red-handed!
                break;
            }
        }

        // If the number is still considered prime, let’s put it on the stage!
        if (isPrime) {
            printf("🎉 %d is a prime superstar! 🎉\n", num);
            primeCount++;
        }
        // Just a little performance to keep everyone entertained!
        else {
            printf("🤡 %d is just another ordinary number... next!\n", num);
        }
    }

    printf("\n👏 A round of applause for our prime numbers! 👏\n");
    printf("Total prime numbers found: %d\n", primeCount);
}

// The main tent of our program
int main() {
    int upperLimit;

    printf("🤖 Enter the upper limit for prime number generation (positive integer): ");
    scanf("%d", &upperLimit);

    // Check if the input is a positive number. If not, start the fun with a grand exit!
    if (upperLimit < 2) {
        printf("🎭 You must enter a number greater than 1 to see our primes perform! 🎭\n");
        return 0;
    }

    // Let the prime number generating circus begin!
    displayprimes(upperLimit);

    // Thank you for visiting our Prime Number Circus! Come back soon! 🎪💖
    printf("\n💖 Thanks for being a part of our prime adventure! Until next time! 💖\n");
    
    return 0; // All’s well that ends well; our circus flows away gracefully.
}