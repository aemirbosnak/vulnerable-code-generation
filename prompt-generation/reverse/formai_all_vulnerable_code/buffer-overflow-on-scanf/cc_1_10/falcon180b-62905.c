//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 8
#define NUMBERS 1
#define SYMBOLS 2
#define LOWERCASE 4
#define UPPERCASE 8
#define SPECIAL 16

int check_password_strength(char *password);

int main() {
    char password[LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);
    int strength = check_password_strength(password);
    printf("Password strength: %d\n", strength);
    return 0;
}

int check_password_strength(char *password) {
    int strength = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    // Check for uppercase letters
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Calculate password strength
    if (strlen(password) < LENGTH) {
        strength += 1;
    }
    if (has_uppercase) {
        strength += UPPERCASE;
    }
    if (has_lowercase) {
        strength += LOWERCASE;
    }
    if (has_number) {
        strength += NUMBERS;
    }
    if (has_special) {
        strength += SPECIAL;
    }

    return strength;
}