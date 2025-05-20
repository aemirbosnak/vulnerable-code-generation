//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password strength levels
typedef enum {
    WEAK,
    OK,
    STRONG,
    VERY_STRONG
} PasswordStrength;

// Check if the password contains at least one uppercase letter
int has_uppercase(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one lowercase letter
int has_lowercase(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one digit
int has_digit(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one special character
int has_special_character(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~')) {
            return 1;
        }
    }
    return 0;
}

// Check the password strength
PasswordStrength check_password_strength(const char *password) {
    int score = 0;

    if (strlen(password) >= 8) {
        score++;
    }
    if (has_uppercase(password)) {
        score++;
    }
    if (has_lowercase(password)) {
        score++;
    }
    if (has_digit(password)) {
        score++;
    }
    if (has_special_character(password)) {
        score++;
    }

    switch (score) {
        case 0:
        case 1:
            return WEAK;
        case 2:
        case 3:
            return OK;
        case 4:
            return STRONG;
        case 5:
            return VERY_STRONG;
        default:
            return WEAK;
    }
}

// Get the password strength level as a string
const char *get_password_strength_level(PasswordStrength strength) {
    switch (strength) {
        case WEAK:
            return "Weak";
        case OK:
            return "OK";
        case STRONG:
            return "Strong";
        case VERY_STRONG:
            return "Very Strong";
        default:
            return "Unknown";
    }
}

// Print a message based on the password strength
void print_password_strength_message(PasswordStrength strength) {
    switch (strength) {
        case WEAK:
            printf("Your password is too weak. Please try a stronger password.\n");
            break;
        case OK:
            printf("Your password is OK, but you could make it stronger.\n");
            break;
        case STRONG:
            printf("Your password is strong. Good job!\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong. Congratulations!\n");
            break;
        default:
            printf("Unknown password strength.\n");
            break;
    }
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength strength = check_password_strength(password);
    const char *strength_level = get_password_strength_level(strength);

    printf("Your password strength is: %s\n", strength_level);
    print_password_strength_message(strength);

    return 0;
}