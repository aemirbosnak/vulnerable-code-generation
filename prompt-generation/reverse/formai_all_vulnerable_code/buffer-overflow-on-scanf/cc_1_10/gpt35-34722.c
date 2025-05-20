//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 16
#define MIN_PASSWORD_LENGTH 8

int main()
{
    int passwordLength;
    char password[MAX_PASSWORD_LENGTH + 1];
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Print program header
    printf("=======================================\n");
    printf("   C Secure Password Generator 1.0\n");
    printf("=======================================\n\n");

    // Get password length from user
    printf("Please enter the desired password length (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &passwordLength);

    // Make sure password length is within range
    if (passwordLength < MIN_PASSWORD_LENGTH)
    {
        passwordLength = MIN_PASSWORD_LENGTH;
    }
    else if (passwordLength > MAX_PASSWORD_LENGTH)
    {
        passwordLength = MAX_PASSWORD_LENGTH;
    }

    // Generate password
    for (i = 0; i < passwordLength; i++)
    {
        // Generate random character
        int randomChar = rand() % 94 + 33; // ASCII characters between 33 and 126

        // If character is a ' or ", use the next character in the ASCII table
        if (randomChar == 39 || randomChar == 34)
        {
            randomChar++;
        }

        // Add character to password
        password[i] = randomChar;
    }

    // Add null terminator to password
    password[passwordLength] = '\0';

    // Print password
    printf("\nYour new password is: %s\n", password);

    return 0;
}