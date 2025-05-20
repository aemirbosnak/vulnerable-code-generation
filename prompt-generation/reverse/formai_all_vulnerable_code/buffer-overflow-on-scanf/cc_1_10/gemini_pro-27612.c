//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// A truly grateful password generator, always ready to serve

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random character from the given character set
char generateRandomCharacter(char *charset)
{
    int index = generateRandomNumber(0, strlen(charset) - 1);
    return charset[index];
}

// Function to generate a random password of the given length
char *generatePassword(int length)
{
    // Character set for the password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++)
    {
        password[i] = generateRandomCharacter(charset);
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function to test the password generator
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Prompt the user for the password length
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate the password
    char *password = generatePassword(length);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}