//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for character sets
#define UPPERCASE_A 65
#define UPPERCASE_Z 90
#define DIGITS 48
#define UPPERCASE_LETTERS (UPPERCASE_A - DIGITS + 1)
#define LOWERCASE_LETTERS (UPPERCASE_Z - UPPERCASE_A + 1)
#define TOTAL_CHARACTER_SETS (UPPERCASE_LETTERS + LOWERCASE_LETTERS + DIGITS)

void generatePassword(int length, int uppercase, int lowercase, int digits) {
    srand(time(NULL));  // Initialize random seed

    // Array to store the password
    char password[length];

    // Iterate through the length of the password
    for (int i = 0; i < length; i++) {
        // Determine the character set for this position
        int characterSet = (rand() % TOTAL_CHARACTER_SETS) + 1;

        // Check if it's an uppercase letter
        if (characterSet <= UPPERCASE_LETTERS) {
            password[i] = (rand() % 26) + UPPERCASE_A;  // Generate random uppercase letter
        }
        // Check if it's a lowercase letter
        else if (characterSet <= UPPERCASE_LETTERS + LOWERCASE_LETTERS) {
            password[i] = (rand() % 26) + UPPERCASE_A + (characterSet - UPPERCASE_LETTERS);  // Generate random lowercase letter
        }
        // Check if it's a digit
        else {
            password[i] = (rand() % 10) + DIGITS;  // Generate random digit
        }
    }

    // Print the generated password
    printf("Your secure password is: %s\n", password);
}

int main() {
    int length = 10;
    int uppercase = 1;
    int lowercase = 1;
    int digits = 1;

    printf("Enter the length of the password: ");
    scanf("%d", &length);

    printf("Enter the number of uppercase letters: ");
    scanf("%d", &uppercase);

    printf("Enter the number of lowercase letters: ");
    scanf("%d", &lowercase);

    printf("Enter the number of digits: ");
    scanf("%d", &digits);

    generatePassword(length, uppercase, lowercase, digits);

    return 0;
}