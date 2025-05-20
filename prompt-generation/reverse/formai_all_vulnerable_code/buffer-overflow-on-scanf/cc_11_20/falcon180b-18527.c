//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password strength
void check_password_strength(char* password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    // Check for uppercase letter
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for number
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Print password strength
    printf("Password Strength: ");
    if (length < 8) {
        printf("Weak\n");
    } else if (length >= 8 && length < 12) {
        if (has_uppercase && has_lowercase && has_number && has_special_char) {
            printf("Strong\n");
        } else {
            printf("Moderate\n");
        }
    } else if (length >= 12) {
        if (has_uppercase && has_lowercase && has_number && has_special_char) {
            printf("Very Strong\n");
        } else {
            printf("Strong\n");
        }
    }
}

int main() {
    char password[100];

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password strength
    check_password_strength(password);

    return 0;
}