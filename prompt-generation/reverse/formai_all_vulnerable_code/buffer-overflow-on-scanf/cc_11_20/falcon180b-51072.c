//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

void print_password_strength(char* password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    // Check if password has uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check if password has lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check if password has numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check if password has special characters
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
        printf("Moderate\n");
    } else if (length >= 12) {
        if (has_uppercase && has_lowercase && has_number && has_special_char) {
            printf("Strong\n");
        } else if (has_uppercase && has_lowercase && has_number) {
            printf("Good\n");
        } else if (has_uppercase && has_lowercase) {
            printf("Fair\n");
        } else {
            printf("Weak\n");
        }
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    print_password_strength(password);
    return 0;
}