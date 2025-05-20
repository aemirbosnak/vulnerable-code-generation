//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void generatePassword(char password[], int length);
bool isCharacter(char character);
bool isUpperCase(char character);
bool isLowerCase(char character);
bool isDigit(char character);

int main()
{
    char password[13]; // Setting password length to 12 with an additional space for the null terminator
    srand(time(NULL)); // Initializing random function with time as the seed
    int choice;

    printf("Welcome to the C Secure Password Generator\n\n");
    printf("Please choose the length of your password (minimum 8): ");
    scanf("%d", &choice);
    while (choice < 8)
    {
        printf("Please enter a value greater than or equal to 8: ");
        scanf("%d", &choice);
    }

    generatePassword(password, choice);
    printf("\nYour generated password is: %s\n", password);

    return 0;
}

void generatePassword(char password[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        char character;
        int type;
        do
        {
            character = rand() % 127; // Generating random ASCII character
        } while (!isCharacter(character));

        type = rand() % 3; // Generating random integer from 0 to 2; dictates whether character is uppercase, lowercase, or digit

        if (type == 0)
            character = character - 32; // Converting character to uppercase if type = 0
        else if (type == 1)
            character = character + 32; // Converting character to lowercase if type = 1

        password[i] = character; // Adding character to password array
    }
    password[length] = '\0'; // Adding null terminator to end of password array
}

bool isCharacter(char character)
{
    if (isUpperCase(character) || isLowerCase(character) || isDigit(character))
        return true;
    else
        return false;
}

bool isUpperCase(char character)
{
    if (character >= 'A' && character <= 'Z')
        return true;
    else
        return false;
}

bool isLowerCase(char character)
{
    if (character >= 'a' && character <= 'z')
        return true;
    else
        return false;
}

bool isDigit(char character)
{
    if (character >= '0' && character <= '9')
        return true;
    else
        return false;
}