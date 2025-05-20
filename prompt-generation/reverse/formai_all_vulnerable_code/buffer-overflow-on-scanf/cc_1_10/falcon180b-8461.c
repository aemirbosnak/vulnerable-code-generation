//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if the given password is strong
int is_strong_password(char *password) {
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;
    int length = strlen(password);

    // Check for uppercase characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_number = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Check if the password meets the minimum requirements
    if (length < 8 ||!has_uppercase ||!has_lowercase ||!has_number ||!has_special_char) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Prompt the user for a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is strong
    if (is_strong_password(password)) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }

    return 0;
}