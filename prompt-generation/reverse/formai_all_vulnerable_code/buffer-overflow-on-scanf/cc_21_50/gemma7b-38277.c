//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{
    char password[20];
    int strength = 0;
    printf("Enter a password: ");
    scanf("%s", password);

    // Check for minimum length
    if (strlen(password) < 8)
    {
        strength = strength - 1;
        printf("Error: Password must be at least 8 characters long.\n");
    }

    // Check for uppercase letter
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C')
        || strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F')
        || strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I')
        || strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L')
        || strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O')
        || strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R')
        || strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U')
        || strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X')
        || strchr(password, 'Y') || strchr(password, 'Z'))
    {
        strength = strength - 1;
        printf("Error: Password must contain an uppercase letter.\n");
    }

    // Check for number
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2')
        || strchr(password, '3') || strchr(password, '4') || strchr(password, '5')
        || strchr(password, '6') || strchr(password, '7') || strchr(password, '8')
        || strchr(password, '9'))
    {
        strength = strength - 1;
        printf("Error: Password must contain a number.\n");
    }

    // Check for special character
    if (strchr(password, '$') || strchr(password, '%') || strchr(password, '&')
        || strchr(password, '*') || strchr(password, '+') || strchr(password, '-')
        || strchr(password, ')') || strchr(password, '}') || strchr(password, '['))
    {
        strength = strength - 1;
        printf("Error: Password must contain a special character.\n");
    }

    // Calculate strength
    strength = strength * 5;

    // Print strength
    printf("Password strength: %d/%d\n", strength, 100);

    return 0;
}