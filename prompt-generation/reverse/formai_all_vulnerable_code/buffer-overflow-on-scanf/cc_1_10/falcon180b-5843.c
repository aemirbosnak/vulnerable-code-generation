//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check password strength
void check_password_strength(char *password) {
    int length = strlen(password);

    // Check for minimum length
    if (length < 8) {
        printf("Weak: Password is too short.\n");
        return;
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
        printf("Weak: Password does not contain any uppercase letters.\n");
        return;
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
        printf("Weak: Password does not contain any lowercase letters.\n");
        return;
    }

    // Check for numbers
    int has_numbers = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_numbers = 1;
            break;
        }
    }
    if (!has_numbers) {
        printf("Weak: Password does not contain any numbers.\n");
        return;
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
        printf("Weak: Password does not contain any special characters.\n");
        return;
    }

    // If all checks pass, password is strong
    printf("Strong: Password meets all requirements.\n");
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}