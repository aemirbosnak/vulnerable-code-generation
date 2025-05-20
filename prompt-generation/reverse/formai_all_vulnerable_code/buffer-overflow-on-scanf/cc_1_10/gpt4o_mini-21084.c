//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

// Function prototypes
void generatePassword(int length, char *password);
void printPassword(char *password);

int main() {
    int length;
    char password[SIZE];

    // Seed the random number generator
    srand(time(NULL));

    // User input for password length
    printf("Enter the desired length of the password (at least 8): ");
    scanf("%d", &length);

    // Validate password length
    if (length < 8 || length > SIZE - 1) {
        printf("Password length must be between 8 and %d characters.\n", SIZE - 1);
        return 1;
    }

    // Generate and print the password
    generatePassword(length, password);
    printPassword(password);

    return 0;
}

// Function to generate a secure password
void generatePassword(int length, char *password) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    // Ensure that we include at least one character from each category
    password[0] = upper[rand() % strlen(upper)];
    password[1] = lower[rand() % strlen(lower)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = specialChars[rand() % strlen(specialChars)];

    // Fill the rest of the password with random characters from all categories
    const char *allChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:,.<>?";
    for (int i = 4; i < length; i++) {
        password[i] = allChars[rand() % strlen(allChars)];
    }

    // Shuffle the password to make it more random
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password
    password[length] = '\0';
}

// Function to print the generated password
void printPassword(char *password) {
    printf("Your secure password is: %s\n", password);
}