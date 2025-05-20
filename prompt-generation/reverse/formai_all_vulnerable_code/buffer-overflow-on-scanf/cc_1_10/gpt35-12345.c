//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function declarations
int generateRandomInt(int min, int max);
char generateRandomChar();
char *generateRandomPassword(int length);

// Main function
int main()
{
    int passwordLength = 8; // default password length

    // Get password length from user input
    printf("Enter the preferred password length (minimum length is 8): ");
    scanf("%d", &passwordLength);

    // Validate password length
    if (passwordLength < 8)
    {
        printf("\n\nInvalid password length. Password must be at least 8 characters long.\n\n");
        return 1;
    }

    // Generate password
    char *password = generateRandomPassword(passwordLength);

    // Display password
    printf("\n\nGenerated password: %s\n\n", password);

    // Free memory allocated for password
    free(password);

    return 0;
}

// Function to generate random integer between min and max
int generateRandomInt(int min, int max)
{
    static int seeded = 0; // for seeding random number generator only once
    if (!seeded)
    {
        srand(time(NULL));
        seeded = 1;
    }
    return rand() % (max - min + 1) + min;
}

// Function to generate random uppercase, lowercase, or digit character
char generateRandomChar()
{
    int type = generateRandomInt(0, 2); // 0 = uppercase, 1 = lowercase, 2 = digit

    switch (type)
    {
        case 0:
            return (char) generateRandomInt(65, 90); // uppercase letters in ASCII range
        case 1:
            return (char) generateRandomInt(97, 122); // lowercase letters in ASCII range
        default:
            return (char) generateRandomInt(48, 57); // digits in ASCII range
    }
}

// Function to generate random password of specified length
char *generateRandomPassword(int length)
{
    char *password = (char*) malloc((length + 1) * sizeof(char)); // allocate memory for password

    // Generate random characters and add to password
    for (int i = 0; i < length; i++)
    {
        password[i] = generateRandomChar();
    }

    // Null-terminate password string
    password[length] = '\0';

    return password;
}