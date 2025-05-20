//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_binary(unsigned int num) {
    printf("Binary representation: ");
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

unsigned int bitwise_operations(unsigned int guess) {
    // Bitwise AND with a mask to isolate certain bits
    unsigned int mask = 0xAA; // 10101010 in binary
    unsigned int modified_guess = guess & mask;
    return modified_guess;
}

int main() {
    unsigned int target_number, player_guess;
    int attempts = 0;

    // Seed the random number generator
    srand(time(NULL));
    target_number = rand() % 256; // Random number between 0 and 255

    printf("Welcome to the Bitwise Guessing Game!\n");
    printf("Try to guess the secret number between 0 and 255.\n");

    // Show the target number's binary representation (hidden initially)
    printf("Target number (in binary): ");
    print_binary(target_number);
    printf("\n");

    do {
        printf("Enter your guess: ");
        scanf("%u", &player_guess);

        attempts++;

        unsigned int modified_guess = bitwise_operations(player_guess);
        printf("Your modified guess after bitwise AND with the mask (0xAA): ");
        print_binary(modified_guess);

        if (player_guess > target_number) {
            printf("Your guess is too high!\n");
        } else if (player_guess < target_number) {
            printf("Your guess is too low!\n");
        } else {
            printf("Congratulations! You've guessed the number %u in %d attempts!\n", target_number, attempts);
        }

    } while (player_guess != target_number);

    printf("Thank you for playing the Bitwise Guessing Game!\n");

    return 0;
}