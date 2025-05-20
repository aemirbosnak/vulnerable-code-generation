//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>
#include <stdbool.h>

// Welcome to the Prime Number Circus! 🎉
// Where we generate prime numbers like a magician pulls rabbits out of hats!

void welcome_message() {
    printf("🎩 Welcome to the Prime Number Generator Circus! 🎪\n");
    printf("Get ready to see some magical prime numbers!\n");
    printf("Are you ready? Let's get this show on the road! 🤹‍♂️\n\n");
}

bool is_prime(int number) {
    // Start clapping for our number!
    if (number <= 1) {
        printf("%d is not a prime number! Boo! 👎\n", number);
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            printf("%d is not a prime number! Pfft! 🍅\n", number);
            return false;
        }
    }
    printf("%d is a prime number! Hooray! 🎉\n", number);
    return true;
}

void generate_primes(int limit) {
    printf("🧙 Generating prime numbers up to %d...\n", limit);
    for (int num = 2; num <= limit; num++) {
        // Time for a little inspection on the number!
        if (is_prime(num)) {
            printf("✨ Found a prime: %d\n", num);
        }
    }
}

int main() {
    welcome_message();
    
    int limit;
    printf("🤔 Please enter the limit up to which you want to find prime numbers: ");
    
    // Let's take a guess!
    while (scanf("%d", &limit) != 1 || limit < 0) {
        printf("Oops! That doesn't seem like a valid number! Try again with a positive number. 🤕\n");
        while(getchar() != '\n'); // Clear the input buffer like a magician removing a scarf from their sleeve!
    }

    generate_primes(limit);

    printf("\n🎉 That's all folks! Remember, prime numbers are like unicorns - rare and magical! 🦄\n");
    printf("Make sure to visit us again at the Prime Number Circus! Byeeeee! 👋\n");
    
    return 0;
}