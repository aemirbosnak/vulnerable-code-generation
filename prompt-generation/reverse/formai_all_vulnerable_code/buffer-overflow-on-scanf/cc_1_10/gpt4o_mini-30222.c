//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random password
void generatePassword(int length, char *password) {
    // Define character sets to use for password generation
    const char *upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *specialChars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    // Combined string of all allowed characters
    const char *allChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    int numChars = strlen(allChars);  // Total number of characters available

    // Seed the random number generator
    srand(time(0));

    // Ensure the password is at least one character from each character set
    password[0] = upperCase[rand() % strlen(upperCase)];
    password[1] = lowerCase[rand() % strlen(lowerCase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = specialChars[rand() % strlen(specialChars)];

    // Fill the remaining length of the password with random characters
    for (int i = 4; i < length; i++) {
        password[i] = allChars[rand() % numChars];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        // Swap characters at positions i and j
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password string
    password[length] = '\0';
}

int main() {
    // Greeting message
    printf("Welcome to the Secure Password Generator!\n");

    // Memory allocation for user-input length
    int length;
    printf("Enter desired password length (minimum 4): ");
    scanf("%d", &length);

    // Check the validity of the input length
    if (length < 4) {
        printf("Password length should be at least 4.\n");
        return 1;  // Exit with error
    }

    // Allocate memory for the password
    char *password = (char *)malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }

    // Call the password generation function
    generatePassword(length, password);

    // Display the generated password
    printf("Your secure password is: %s\n", password);

    // Free allocated memory
    free(password);
    
    // Farewell message
    printf("Thank you for using the Secure Password Generator!\n");

    return 0;  // Successful program termination
}