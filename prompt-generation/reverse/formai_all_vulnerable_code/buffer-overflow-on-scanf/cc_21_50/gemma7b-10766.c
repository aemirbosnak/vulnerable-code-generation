//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check password length
    if (password_length < 8)
    {
        strength -= 10;
    }

    // Check for uppercase letter
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') ||
        strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') ||
        strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') ||
        strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') ||
        strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') ||
        strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') ||
        strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') ||
        strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') ||
        strchr(password, 'Y') || strchr(password, 'Z'))
    {
        strength -= 5;
    }

    // Check for number
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') ||
        strchr(password, '3') || strchr(password, '4') || strchr(password, '5') ||
        strchr(password, '6') || strchr(password, '7') || strchr(password, '8') ||
        strchr(password, '9'))
    {
        strength -= 3;
    }

    // Check for special characters
    if (strchr(password, '$') || strchr(password, '%') || strchr(password, '^') ||
        strchr(password, '&') || strchr(password, '*'))
    {
        strength -= 2;
    }

    // Calculate password strength
    strength = 100 - strength;

    // Print password strength
    printf("Your password strength is: %d%%", strength);

    return 0;
}