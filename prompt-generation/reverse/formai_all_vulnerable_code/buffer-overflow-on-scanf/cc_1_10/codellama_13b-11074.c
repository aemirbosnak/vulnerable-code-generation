//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Password Strength Checker
 *
 * This program checks the strength of a given password using a simple algorithm
 * and provides feedback based on its strength.
 */

#include <stdio.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2
#define VERY_STRONG 3

// Define the password strength checks
#define LENGTH_CHECK(length) length > 8
#define UPPERCASE_CHECK(str) strchr(str, 'A') || strchr(str, 'B') || strchr(str, 'C')
#define LOWERCASE_CHECK(str) strchr(str, 'a') || strchr(str, 'b') || strchr(str, 'c')
#define NUMERIC_CHECK(str) strchr(str, '1') || strchr(str, '2') || strchr(str, '3')
#define SPECIAL_CHECK(str) strchr(str, '!') || strchr(str, '@') || strchr(str, '#')

// Define the password strength feedback
#define WEAK_FEEDBACK "Password is too weak, try adding more characters"
#define MEDIUM_FEEDBACK "Password is weak, try adding more characters and mix it with uppercase, lowercase and special characters"
#define STRONG_FEEDBACK "Password is strong, but try adding more special characters for better security"
#define VERY_STRONG_FEEDBACK "Password is very strong, keep it up!"

int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    int length = strlen(password);
    int uppercase = UPPERCASE_CHECK(password);
    int lowercase = LOWERCASE_CHECK(password);
    int numeric = NUMERIC_CHECK(password);
    int special = SPECIAL_CHECK(password);

    // Calculate the password strength
    int strength = 0;
    if (length > 8) strength++;
    if (uppercase) strength++;
    if (lowercase) strength++;
    if (numeric) strength++;
    if (special) strength++;

    // Provide feedback based on the password strength
    switch (strength) {
        case WEAK:
            printf(WEAK_FEEDBACK);
            break;
        case MEDIUM:
            printf(MEDIUM_FEEDBACK);
            break;
        case STRONG:
            printf(STRONG_FEEDBACK);
            break;
        case VERY_STRONG:
            printf(VERY_STRONG_FEEDBACK);
            break;
        default:
            printf("Password strength unknown");
    }

    return 0;
}