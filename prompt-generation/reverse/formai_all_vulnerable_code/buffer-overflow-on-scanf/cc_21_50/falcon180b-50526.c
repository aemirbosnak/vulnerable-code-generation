//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Prompt user for password
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check password strength
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        else if (islower(password[i])) {
            has_lowercase = 1;
        }
        else if (isdigit(password[i])) {
            has_number = 1;
        }
        else if (!isalnum(password[i])) {
            has_special_char = 1;
        }
    }

    // Print password strength
    printf("Password strength: ");
    if (length < 8) {
        printf("Weak\n");
    }
    else if (length >= 8 && length < 12) {
        if (has_uppercase && has_lowercase) {
            printf("Moderate\n");
        }
        else {
            printf("Weak\n");
        }
    }
    else if (length >= 12 && length < 16) {
        if (has_uppercase && has_lowercase && has_number) {
            printf("Strong\n");
        }
        else {
            printf("Moderate\n");
        }
    }
    else if (length >= 16 && length < 20) {
        if (has_uppercase && has_lowercase && has_number && has_special_char) {
            printf("Very strong\n");
        }
        else {
            printf("Strong\n");
        }
    }
    else {
        printf("Very strong\n");
    }

    return 0;
}