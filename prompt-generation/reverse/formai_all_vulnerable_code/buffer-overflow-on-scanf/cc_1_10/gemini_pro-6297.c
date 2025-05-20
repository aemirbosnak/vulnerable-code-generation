//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Get the password length from the user
    int password_length;
    printf("Enter the desired password length (minimum %d, maximum %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    // Validate the password length
    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Invalid password length. Please enter a value between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Generate the password
    char password[MAX_PASSWORD_LENGTH + 1];
    for (int i = 0; i < password_length; i++)
    {
        // Generate a random character
        char character = (rand() % 94) + 33;

        // Ensure that the character is printable
        if (!isprint(character))
        {
            i--;
            continue;
        }

        // Add the character to the password
        password[i] = character;
    }

    // Terminate the password with a null character
    password[password_length] = '\0';

    // Print the password to the console
    printf("Your new password is: %s\n", password);

    return 0;
}