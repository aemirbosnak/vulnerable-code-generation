//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PARANOIA_LEVEL 10

// Obfuscation macros to protect our precious secrets
#define SECURE_ROLLED_VALUE(v) ((v) ^ (PARANOIA_LEVEL * (v)))
#define DECRYPT_ROLLED_VALUE(v) ((v) ^ (PARANOIA_LEVEL * (v)))

// The ultimate paranoia-proof dice roller
int roll_die(int num_sides) {
    // Initialize the random number generator with a highly secure seed
    srand(time(NULL) ^ (PARANOIA_LEVEL * rand()));

    // Generate a random number within the desired range
    int rolled_value = rand() % num_sides + 1;

    // Obfuscate the rolled value to prevent prying eyes from deciphering it
    rolled_value = SECURE_ROLLED_VALUE(rolled_value);

    // Return the obfuscated rolled value
    return rolled_value;
}

// Main function to showcase our impenetrable dice roller
int main() {
    int num_sides;

    // Prompt the user to enter the number of sides for the die
    printf("Enter the number of sides for the die (1-100): ");
    scanf("%d", &num_sides);

    // Validate the user's input to prevent malicious attempts to crash our program
    if (num_sides < 1 || num_sides > 100) {
        printf("Invalid number of sides. Please enter a valid value between 1 and 100.\n");
        return 1;
    }

    // Roll the die multiple times to demonstrate the randomness of our algorithm
    for (int i = 0; i < 10; i++) {
        // Generate a random number within the specified range
        int rolled_value = roll_die(num_sides);

        // Decrypt the obfuscated rolled value to reveal the true result
        rolled_value = DECRYPT_ROLLED_VALUE(rolled_value);

        // Display the rolled value to the user
        printf("Rolled value: %d\n", rolled_value);
    }

    return 0;
}