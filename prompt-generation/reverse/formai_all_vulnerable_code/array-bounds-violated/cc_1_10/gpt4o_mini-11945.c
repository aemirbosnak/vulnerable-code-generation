//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 128
#define NUM_RULES 5

// Function Prototypes
bool checkLength(const char *password);
bool checkUpperCase(const char *password);
bool checkLowerCase(const char *password);
bool checkDigits(const char *password);
bool checkSpecialChars(const char *password);
void displayStrength(int score);
void cyberpunkGraphic();

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int strengthScore = 0;
    
    cyberpunkGraphic();
    printf("Welcome to the Cyberpunk Password Strength Checker.\n");
    printf("Enter your password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
    
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    
    // Remove newline character if present
    password[strcspn(password, "\n")] = 0;

    // Check password strength rules
    if (checkLength(password)) strengthScore++;
    if (checkUpperCase(password)) strengthScore++;
    if (checkLowerCase(password)) strengthScore++;
    if (checkDigits(password)) strengthScore++;
    if (checkSpecialChars(password)) strengthScore++;

    displayStrength(strengthScore);

    return 0;
}

// Checks if password length is at least 8 characters
bool checkLength(const char *password) {
    return strlen(password) >= 8;
}

// Checks if password contains at least one uppercase letter
bool checkUpperCase(const char *password) {
    while (*password) {
        if (isupper(*password)) return true;
        password++;
    }
    return false;
}

// Checks if password contains at least one lowercase letter
bool checkLowerCase(const char *password) {
    while (*password) {
        if (islower(*password)) return true;
        password++;
    }
    return false;
}

// Checks if password contains at least one digit
bool checkDigits(const char *password) {
    while (*password) {
        if (isdigit(*password)) return true;
        password++;
    }
    return false;
}

// Checks if password contains at least one special character
bool checkSpecialChars(const char *password) {
    const char specialChars[] = "!@#$%^&*()_-+=<>?";
    while (*password) {
        if (strchr(specialChars, *password)) return true;
        password++;
    }
    return false;
}

void displayStrength(int score) {
    const char *strengthLevel[] = {
        "Weak",
        "Moderate",
        "Strong",
        "Very Strong",
        "Unbreakable"
    };
    
    printf("Your password strength is: %s\n", strengthLevel[score]);
}

void cyberpunkGraphic() {
    printf("=====================================\n");
    printf("||  Cyberpunk Password Checker     ||\n");
    printf("||   __    __        __    _       ||\n");
    printf("||  / /   / /       / /   | |      ||\n");
    printf("|| / /   / /__     / /    | |  ___ ||\n");
    printf("||/ /   / ___ \\   / /     | | / _ \\||\n");
    printf("||  \\__/ /   | | / /      | ||  __/||\n");
    printf("||      /_/    |_|/        |_|\\___|/||\n");
    printf("||   Hack the Matrix. Stay Secure! ||\n");
    printf("=====================================\n");
}