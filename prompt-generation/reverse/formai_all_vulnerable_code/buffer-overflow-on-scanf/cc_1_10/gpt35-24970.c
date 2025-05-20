//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function prototypes
char generateRandomChar();
int generateRandomNumber(int min, int max);
void generatePassword(int length);

int main()
{
    int passwordLength;

    // Prompt user for password length
    printf("Enter password length (must be at least 8 characters): ");
    scanf("%d", &passwordLength);

    // Check if password length is valid
    if (passwordLength >= 8)
    {
        // Generate random password
        generatePassword(passwordLength);

        return 0;
    }
    else
    {
        printf("Invalid password length. Must be at least 8 characters.\n");
        return 1;
    }
}

/* Generates a random uppercase character, lowercase character,
 * or number
 */
char generateRandomChar()
{
    // Define character set: uppercase letters, lowercase letters, and numbers
    char characterSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Generate a random index within the character set array
    int index = generateRandomNumber(0, sizeof(characterSet) - 1);

    // Return the randomly selected character
    return characterSet[index];
}

/* Generates a random number between min and max */
int generateRandomNumber(int min, int max)
{
    // Seed the random number generator
    srand(time(NULL));

    // Calculate the range and add the minimum
    int range = max - min + 1;
    int randomNumber = rand() % range + min;

    // Return the randomly generated number
    return randomNumber;
}

/* Generates a password of specified length */
void generatePassword(int length)
{
    char password[length];

    // Generate random characters and add to the password string
    for (int i = 0; i < length; i++)
    {
        password[i] = generateRandomChar();
    }

    // Add a null terminator to the end of the string
    password[length] = '\0';

    // Print the generated password
    printf("Generated password: %s\n", password);
}