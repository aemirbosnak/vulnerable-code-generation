//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <ctype.h>

// Function to check the strength of a password
int checkPasswordStrength(char password[]) {
    int strength = 0;

    // Check length of password
    if (strlen(password) < 8)
        return 0;

    // Check for spaces
    if (isspace(password[0]))
        return 0;

    // Check for uppercase letters
    if (!isupper(password[0]))
        return 0;

    // Check for lowercase letters
    if (!islower(password[0]))
        return 0;

    // Check for digits
    if (!isdigit(password[0]))
        return 0;

    // Check for alphanumeric characters
    if (!isalnum(password[0]))
        return 0;

    // Check for alphabetic characters
    if (!isalpha(password[0]))
        return 0;

    // Check for ASCII characters
    if (!isascii(password[0]))
        return 0;

    return 10;
}

int main() {
    char password[100];

    printf("Enter a password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    printf("Password strength: %d\n", strength);

    return 0;
}