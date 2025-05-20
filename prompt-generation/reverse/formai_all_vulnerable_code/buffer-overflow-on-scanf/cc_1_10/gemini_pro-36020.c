//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>

// Password strength levels
enum PasswordStrength {
    WEAK,
    MEDIUM,
    STRONG
};

// Check if the password contains at least one lowercase letter
int hasLowercase(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one uppercase letter
int hasUppercase(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one digit
int hasDigit(char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

// Check if the password contains at least one special character
int hasSpecialChar(char *password) {
    char specialChars[] = "!@#$%^&*()-_=+";
    for (int i = 0; password[i] != '\0'; i++) {
        for (int j = 0; specialChars[j] != '\0'; j++) {
            if (password[i] == specialChars[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Check the strength of the password
enum PasswordStrength checkStrength(char *password) {
    int score = 0;
    if (strlen(password) < 8) {
        score += 1;
    }
    if (!hasLowercase(password)) {
        score += 1;
    }
    if (!hasUppercase(password)) {
        score += 1;
    }
    if (!hasDigit(password)) {
        score += 1;
    }
    if (!hasSpecialChar(password)) {
        score += 1;
    }

    switch (score) {
        case 0:
            return STRONG;
        case 1:
        case 2:
            return MEDIUM;
        default:
            return WEAK;
    }
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    enum PasswordStrength strength = checkStrength(password);

    switch (strength) {
        case WEAK:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
        case MEDIUM:
            printf("Your password is medium strength. Consider adding more complexity.\n");
            break;
        case STRONG:
            printf("Your password is strong. Good job!\n");
            break;
    }

    return 0;
}