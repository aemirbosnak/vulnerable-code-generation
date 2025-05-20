//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of all possible characters
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+=-";

    // Get the desired password length from the user
    int passwordLength;
    printf("How long should the password be? ");
    scanf("%d", &passwordLength);

    // Create a new password
    char password[MAX_PASSWORD_LENGTH];
    for (int i = 0; i < passwordLength; i++) {
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    password[passwordLength] = '\0';

    // Check the strength of the password
    int strength = 0;
    if (passwordLength >= 8) {
        strength++;
    }
    if (passwordLength >= 12) {
        strength++;
    }
    if (passwordLength >= 16) {
        strength++;
    }
    if (passwordLength >= 20) {
        strength++;
    }

    for (int i = 0; i < passwordLength; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
        }
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
        }
        if (password[i] >= '0' && password[i] <= '9') {
            strength++;
        }
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '_' || password[i] == '+' || password[i] == '=' || password[i] == '-') {
            strength++;
        }
    }

    // Print the password strength
    printf("The password strength is %d\n", strength);

    // Print the password
    printf("The password is %s\n", password);

    return 0;
}