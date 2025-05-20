//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_SIZE 255

int main() {
    char password[MAX_PASS_SIZE];
    int passwordLength;
    int specialCharCount;
    int numberCount;
    int lowercaseCount;
    int uppercaseCount;
    int totalChars;

    printf("Welcome to the Romantic Password Generator!\n");
    printf("Let's create a password that's as unique as your love.\n");

    // Get the desired password length from the user.
    printf("How many characters should your password be? (min: 8, max: 255): ");
    scanf("%d", &passwordLength);

    // Validate the password length.
    if (passwordLength < 8 || passwordLength > MAX_PASS_SIZE) {
        printf("Invalid password length. Please choose a value between 8 and %d.\n", MAX_PASS_SIZE);
        return 1;
    }

    // Get the number of special characters, numbers, lowercase letters, and uppercase letters the user wants in the password.
    printf("How many special characters should your password contain? (min: 1, max: %d): ", passwordLength / 2);
    scanf("%d", &specialCharCount);

    printf("How many numbers should your password contain? (min: 1, max: %d): ", passwordLength / 2);
    scanf("%d", &numberCount);

    printf("How many lowercase letters should your password contain? (min: 1, max: %d): ", passwordLength / 2);
    scanf("%d", &lowercaseCount);

    printf("How many uppercase letters should your password contain? (min: 1, max: %d): ", passwordLength / 2);
    scanf("%d", &uppercaseCount);

    // Validate the character counts.
    totalChars = specialCharCount + numberCount + lowercaseCount + uppercaseCount;
    if (totalChars > passwordLength) {
        printf("Invalid character counts. The total number of characters cannot exceed the password length.\n");
        return 1;
    }

    // Generate the password.
    int i;
    int charIndex;
    char charSet[] = "!@#$%^&*()-_=+[]{};:<>,.?/0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < passwordLength; i++) {
        charIndex = rand() % (sizeof(charSet) - 1);
        password[i] = charSet[charIndex];
    }

    // Ensure that the password contains the required number of special characters, numbers, lowercase letters, and uppercase letters.
    int specialCharIndex = 0;
    int numberIndex = 0;
    int lowercaseIndex = 0;
    int uppercaseIndex = 0;
    for (i = 0; i < passwordLength; i++) {
        if (password[i] >= '!' && password[i] <= '/') {
            if (specialCharIndex < specialCharCount) {
                specialCharIndex++;
            } else {
                password[i] = charSet[rand() % (sizeof(charSet) - 1)];
            }
        } else if (password[i] >= '0' && password[i] <= '9') {
            if (numberIndex < numberCount) {
                numberIndex++;
            } else {
                password[i] = charSet[rand() % (sizeof(charSet) - 1)];
            }
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            if (lowercaseIndex < lowercaseCount) {
                lowercaseIndex++;
            } else {
                password[i] = charSet[rand() % (sizeof(charSet) - 1)];
            }
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            if (uppercaseIndex < uppercaseCount) {
                uppercaseIndex++;
            } else {
                password[i] = charSet[rand() % (sizeof(charSet) - 1)];
            }
        }
    }

    // Add a null terminator to the end of the password.
    password[passwordLength] = '\0';

    // Display the generated password to the user.
    printf("Your romantic password is: %s\n", password);

    return 0;
}