//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define ALL_CHARACTERS "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
#define SYMBOLS "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

// function to generate a random integer within a range
int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// function to generate a secure password
char* generatePassword(int minLength, int maxLength, char* characters)
{
    // seed the random number generator
    srand(time(0));

    // length of the character set
    int charSetLength = strlen(characters);

    // length of the password
    int passwordLength = generateRandomNumber(minLength, maxLength);

    // dynamically allocate memory for the password
    char* password = (char*) malloc(sizeof(char) * passwordLength);

    // loop through each character in the password
    for(int i = 0; i < passwordLength; i++)
    {
        // generate a random index within the character set range
        int randomIndex = generateRandomNumber(0, charSetLength - 1);

        // assign the character at that index to the password
        password[i] = characters[randomIndex];
    }

    // null terminate the password string
    password[passwordLength] = '\0';

    // return the generated password
    return password;
}

int main()
{
    // get the user's preference for the password length
    int minLength, maxLength;
    printf("Enter the minimum and maximum length of the password: ");
    scanf("%d %d", &minLength, &maxLength);

    // validate input
    if(maxLength < minLength)
    {
        printf("Invalid input. Maximum length cannot be less than minimum length.\n");
        return 0;
    }
    if(minLength < MIN_PASSWORD_LENGTH || maxLength > MAX_PASSWORD_LENGTH)
    {
        printf("Invalid input. Password length should be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 0;
    }

    // ask user for preferences on the password characters
    int useSymbols;
    printf("Do you want to include symbols in your password? (1 for yes, 0 for no): ");
    scanf("%d", &useSymbols);

    // generate the appropriate character set based on user preferences
    char* characters;
    if(useSymbols)
    {
        characters = SYMBOLS;
    }
    else
    {
        characters = ALL_CHARACTERS;
    }

    // generate the password
    char* password = generatePassword(minLength, maxLength, characters);

    // print the generated password
    printf("Your generated password is: %s\n", password);

    // free dynamically allocated memory
    free(password);

    // exit the program
    return 0;
}