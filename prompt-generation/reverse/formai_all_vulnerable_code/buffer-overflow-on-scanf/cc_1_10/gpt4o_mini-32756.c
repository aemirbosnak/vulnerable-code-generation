//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a single character based on character set
char getRandomChar(const char *charset, int length) {
    return charset[rand() % length];
}

// Function to check if password meets the specified requirements
int isPasswordValid(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        } else if (strchr("!@#$%^&*()-_=+[]{};:'\",.<>?|", password[i])) {
            hasSpecial = 1;
        }
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Function to generate a secure password
void generatePassword(char *password, int length) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-_=+[]{};:'\",.<>?|";
    
    const char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{};:'\",.<>?|";
    const int totalSetLength = strlen(charset);
    
    // Ensure at least one character from each category
    password[0] = getRandomChar(upper, strlen(upper));
    password[1] = getRandomChar(lower, strlen(lower));
    password[2] = getRandomChar(digits, strlen(digits));
    password[3] = getRandomChar(special, strlen(special));
    
    // Fill the rest of the password with random characters
    for (int i = 4; i < length; i++) {
        password[i] = getRandomChar(charset, totalSetLength);
    }
    
    // Shuffle the password to mix up the character positions
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // Null-terminate the password string
    password[length] = '\0';
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int passwordLength;

    printf("Welcome to the Energetic Secure Password Generator!\n");
    printf("Please enter the desired length of your password (minimum 8 characters): ");
    scanf("%d", &passwordLength);

    // Ensure the requested length is valid
    if (passwordLength < 8) {
        printf("Minimum password length is 8. Please try again!\n");
        return 1;
    }

    // Prepare the password storage
    char password[passwordLength + 1];

    // Generate a valid password
    generatePassword(password, passwordLength);

    // Check if the generated password is valid
    while (!isPasswordValid(password)) {
        generatePassword(password, passwordLength);
    }

    printf("Your secure password is: %s\n", password);
    printf("Remember to keep it safe and secure!\n");
    
    return 0;
}