//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random character
char generateRandomCharacter() {
    int randomIndex = rand() % 94; // Generate a random index between 0 and 93
    if (randomIndex < 26) { // If the index is less than 26, return a lowercase letter
        return 'a' + randomIndex;
    } else if (randomIndex < 52) { // If the index is between 26 and 51, return an uppercase letter
        return 'A' + (randomIndex - 26);
    } else if (randomIndex < 78) { // If the index is between 52 and 77, return a number
        return '0' + (randomIndex - 52);
    } else { // If the index is between 78 and 93, return a special character
        return "!@#$%^&*()_+=-`~";
    }
}

// Function to generate a random password of a given length
char *generateRandomPassword(int length) {
    if (length <= 0) { // Base case: If the requested length is non-positive, return an empty string
        return "";
    }
     char *password = malloc(sizeof(char) * (length + 1)); // Allocate memory for the password
    password[length] = '\0'; // Null-terminate the password

    for (int i = 0; i < length; i++) { // Recursively generate each character of the password
        password[i] = generateRandomCharacter();
    }

    return password; // Return the generated password
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Prompt the user for the desired password length
    printf("Enter the desired password length: ");
    int length;
    scanf("%d", &length);

    // Generate a random password of the specified length
    char *password = generateRandomPassword(length);

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}