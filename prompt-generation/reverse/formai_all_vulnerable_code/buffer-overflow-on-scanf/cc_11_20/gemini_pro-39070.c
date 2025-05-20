//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Password strength criteria
#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

// Strength levels
#define WEAK 0
#define FAIR 1
#define GOOD 2
#define STRONG 3

// Check if a character is uppercase
int isUppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Check if a character is lowercase
int isLowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Check if a character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Check if a character is a special character
int isSpecial(char c) {
    return !isUppercase(c) && !isLowercase(c) && !isDigit(c);
}

// Check the strength of a password
int checkStrength(char *password) {
    int strength = 0;

    // Check the length of the password
    if (strlen(password) >= MIN_LENGTH) {
        strength++;
    }

    // Check for uppercase characters
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') || strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') || strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') || strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') || strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') || strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') || strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') || strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') || strchr(password, 'Y') || strchr(password, 'Z')) {
        strength++;
    }

    // Check for lowercase characters
    if (strchr(password, 'a') || strchr(password, 'b') || strchr(password, 'c') || strchr(password, 'd') || strchr(password, 'e') || strchr(password, 'f') || strchr(password, 'g') || strchr(password, 'h') || strchr(password, 'i') || strchr(password, 'j') || strchr(password, 'k') || strchr(password, 'l') || strchr(password, 'm') || strchr(password, 'n') || strchr(password, 'o') || strchr(password, 'p') || strchr(password, 'q') || strchr(password, 'r') || strchr(password, 's') || strchr(password, 't') || strchr(password, 'u') || strchr(password, 'v') || strchr(password, 'w') || strchr(password, 'x') || strchr(password, 'y') || strchr(password, 'z')) {
        strength++;
    }

    // Check for digits
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9')) {
        strength++;
    }

    // Check for special characters
    if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') || strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*')) {
        strength++;
    }

    return strength;
}

// Print the strength of a password
void printStrength(char *password) {
    int strength = checkStrength(password);

    switch (strength) {
        case WEAK:
            printf("Password is weak!\n");
            break;
        case FAIR:
            printf("Password is fair!\n");
            break;
        case GOOD:
            printf("Password is good!\n");
            break;
        case STRONG:
            printf("Password is strong!\n");
            break;
    }
}

int main() {
    // Get the password from the user
    char password[MAX_LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    printStrength(password);

    return 0;
}