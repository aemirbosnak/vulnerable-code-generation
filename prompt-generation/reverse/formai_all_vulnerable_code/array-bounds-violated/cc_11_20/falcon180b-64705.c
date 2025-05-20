//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, i;

    // Get password from user
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    length = strlen(password);

    // Remove newline character from password
    password[--length] = '\0';

    // Check password strength
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (isalnum(password[i]) == 0) {
            has_special_char = 1;
        }
    }

    int strength = 0;

    if (length >= 8) {
        strength++;
    }

    if (has_uppercase) {
        strength++;
    }

    if (has_lowercase) {
        strength++;
    }

    if (has_number) {
        strength++;
    }

    if (has_special_char) {
        strength++;
    }

    printf("Password strength: %d\n", strength);

    return 0;
}