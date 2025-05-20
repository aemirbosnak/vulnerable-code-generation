//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8

// A strong password must satisfy the following criteria:
// 1. Contain at least one uppercase letter
// 2. Contain at least one lowercase letter
// 3. Contain at least one digit
// 4. Contain at least one special character (!@#$%^&*)
// 5. Be at least 8 characters long

int check_strength(char *password) {
    int strength = 0;
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        return 0;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            strength++;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            strength++;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            strength++;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            strength++;
            break;
        }
    }

    return strength;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    int strength = check_strength(password);

    switch (strength) {
        case 0:
            printf("Weak password\n");
            break;
        case 1:
            printf("Fairly strong password\n");
            break;
        case 2:
            printf("Strong password\n");
            break;
        case 3:
            printf("Very strong password\n");
            break;
        case 4:
            printf("Unbreakable password\n");
            break;
        default:
            printf("Invalid password\n");
    }

    return 0;
}