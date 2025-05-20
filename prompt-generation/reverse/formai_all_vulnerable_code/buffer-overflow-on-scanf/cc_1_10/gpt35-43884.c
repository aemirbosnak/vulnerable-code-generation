//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20 // define the maximum length of the password
#define MIN_LENGTH 8  // define the minimum length of the password

// function declarations
int generateRand(int min, int max);
int selectRandIndex(int length);
void shuffleArray(char *arr, int length);
char *generatePassword(int length);

int main()
{
    // Seed the RNG
    srand(time(0));

    printf("Welcome to the Secure Password Generator!\n\n");

    // ask the user for the desired password length
    int length;
    do
    {
        printf("Please enter the desired length of your password (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);
    } while (length < MIN_LENGTH || length > MAX_LENGTH);

    // generate the password
    char *password = generatePassword(length);

    // print the password to the console
    printf("\nYour password is:\n%s\n\n", password);

    // free the memory allocated to the password
    free(password);

    return 0;
}

/**
 * Generate a random integer between min (inclusive) and max (inclusive).
 * @param min The minimum value that can be generated.
 * @param max The maximum value that can be generated.
 * @return An integer between min and max.
 */
int generateRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/**
 * Generate a random index in the array.
 * @param length The length of the array.
 * @return A random integer between 0 and length - 1.
 */
int selectRandIndex(int length)
{
    return generateRand(0, length - 1);
}

/**
 * Shuffle the characters in the array in place.
 * @param arr The array to shuffle.
 * @param length The length of the array.
 */
void shuffleArray(char *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int j = selectRandIndex(length - i) + i;
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/**
 * Generate a password of the specified length.
 * @param length The length of the password to generate.
 * @return A string containing the generated password.
 */
char *generatePassword(int length)
{
    // allocate memory for the password
    char *password = (char *)malloc((length + 1) * sizeof(char));

    // define the character sets to use for each type of character
    char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char specialCharacters[] = "!@#$%^&*()_+-=[]{}\\|;':\",./<>?";

    // determine the number of characters to use for each type
    int numLowercase = generateRand(1, length - 3);
    int numUppercase = generateRand(1, length - numLowercase - 2);
    int numDigits = generateRand(1, length - numLowercase - numUppercase - 1);

    // pick the remaining characters from the special character set
    int numSpecial = length - numLowercase - numUppercase - numDigits;

    // fill the password with the chosen characters
    int index = 0;
    for (int i = 0; i < numLowercase; i++)
    {
        password[index++] = lowercaseLetters[selectRandIndex(26)];
    }
    for (int i = 0; i < numUppercase; i++)
    {
        password[index++] = uppercaseLetters[selectRandIndex(26)];
    }
    for (int i = 0; i < numDigits; i++)
    {
        password[index++] = digits[selectRandIndex(10)];
    }
    for (int i = 0; i < numSpecial; i++)
    {
        password[index++] = specialCharacters[selectRandIndex(32)];
    }

    // shuffle the characters in the password
    shuffleArray(password, length);

    // terminate the string with a null character
    password[length] = '\0';

    return password;
}