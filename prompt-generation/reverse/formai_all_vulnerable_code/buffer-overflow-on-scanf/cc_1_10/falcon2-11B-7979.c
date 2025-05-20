//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // Seed the random number generator with time
    srand(time(NULL));

    // Set minimum length of password to 8 characters
    int minLength = 8;

    // Set maximum length of password to 16 characters
    int maxLength = 16;

    // Prompt user for length of password
    printf("Enter password length (min 8, max 16): ");
    int length;
    scanf("%d", &length);

    // Check if length is valid
    if (length < minLength || length > maxLength) {
        printf("Invalid length. Minimum length is 8 characters, maximum length is 16 characters.\n");
        return 1;
    }

    // Create an array to store characters
    char password[length];

    // Loop to generate random characters until length is reached
    int i = 0;
    while (i < length) {
        // Generate random character from 'a' to 'z', 'A' to 'Z', '0' to '9'
        char randomChar = (char)('a' + rand() % 26);

        // Check if character is already in password
        int j = 0;
        while (j < i) {
            if (password[j] == randomChar) {
                i = j;
                break;
            }
            j++;
        }

        // Add character to password
        password[i] = randomChar;
        i++;
    }

    // Print password
    printf("Your secure password is: %s\n", password);

    return 0;
}