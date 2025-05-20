//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, i;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for minimum length
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for uppercase letters
    int has_uppercase = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letters
    int has_lowercase = 0;
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for digits
    int has_digits = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digits = 1;
            break;
        }
    }
    if (!has_digits) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    // Check for special characters
    int has_special = 0;
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (i = 0; i < length; i++) {
        int found = 0;
        for (int j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            has_special = 1;
            break;
        }
    }
    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // Password is strong
    printf("Password is strong.\n");
    return 0;
}