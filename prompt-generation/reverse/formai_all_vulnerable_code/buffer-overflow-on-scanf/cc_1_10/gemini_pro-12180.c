//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char randomChar()
{
    int r = rand() % 62;
    if (r < 10)
        return (char)(r + '0');
    else if (r < 36)
        return (char)(r - 10 + 'a');
    else
        return (char)(r - 36 + 'A');
}

// Function to generate a random password
char *randomPassword(int length)
{
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++)
    {
        password[i] = randomChar();
    }
    password[length] = '\0';
    return password;
}

// Main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = randomPassword(length);

    // Print the password to the console
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}