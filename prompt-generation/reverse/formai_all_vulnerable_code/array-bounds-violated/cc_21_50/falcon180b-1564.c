//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);

    // Remove the newline character from the password
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    // Check the length of the password
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Password must be between 8 and %d characters long.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Check for uppercase letters
    int has_uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    // Check for lowercase letters
    int has_lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    // Check for digits
    int has_digits = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digits = 1;
            break;
        }
    }
    if (!has_digits) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    // Check for special characters
    int has_special_chars = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_chars = 1;
            break;
        }
    }
    if (!has_special_chars) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    // Calculate the password strength
    int strength = 0;
    if (length >= 12) {
        strength++;
    }
    if (has_uppercase && has_lowercase && has_digits && has_special_chars) {
        strength++;
    }

    // Print the password strength
    printf("Password strength: %d\n", strength);

    return 0;
}