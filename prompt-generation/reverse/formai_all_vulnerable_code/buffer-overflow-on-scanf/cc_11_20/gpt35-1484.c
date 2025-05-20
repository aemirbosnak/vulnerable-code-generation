//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12 // Define password length

int main()
{
    char password[PASSWORD_LENGTH + 1]; // Create char array for password generation
    int characterSet = 0; // integer to contain the selected character set

    srand(time(NULL)); // srand to generate random numbers using time as the seed

    // Password generation menu
    printf("Select a password character set:\n");
    printf("1. Lowercase letters (a-z)\n");
    printf("2. Uppercase letters (A-Z)\n");
    printf("3. Numbers (0-9)\n");
    printf("4. Special Characters (!@$&*_)\n");
    printf("5. All Character Sets\n");

    // Read selected option
    scanf("%d", &characterSet);

    // Define character sets as strings for easier implementation
    char* lowerCaseLetters = "abcdefghijklmnopqrstuvwxyz";
    char* upperCaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* numbers = "0123456789";
    char* specialCharacters = "!@$&*_";

    int i = 0;
    // Loop through the password array and randomly generate characters based on the selected character set
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        int randomNumber = rand(); // Generate random number

        // Determine character set based on selected option
        if (characterSet == 1) // lowercase letters
        {
            password[i] = lowerCaseLetters[randomNumber % 26];
        }
        else if (characterSet == 2) // uppercase letters
        {
            password[i] = upperCaseLetters[randomNumber % 26];
        }
        else if (characterSet == 3) // numbers
        {
            password[i] = numbers[randomNumber % 10];
        }
        else if (characterSet == 4) // special characters
        {
            password[i] = specialCharacters[randomNumber % 7];

        }
        else if (characterSet == 5) // all character sets
        {
            int option = randomNumber % 4; // randomly select which character set to use
            if (option == 0)
            {
                password[i] = lowerCaseLetters[randomNumber % 26];
            }
            else if (option == 1)
            {
                password[i] = upperCaseLetters[randomNumber % 26];
            }
            else if (option == 2)
            {
                password[i] = numbers[randomNumber % 10];
            }
            else if (option == 3)
            {
                password[i] = specialCharacters[randomNumber % 7];
            }
        }
    }

    password[PASSWORD_LENGTH] = '\0'; // Add null terminator to end of password array

    printf("Your new secure password is: %s\n", password); // Print the generated password

    return 0; // End the program
}