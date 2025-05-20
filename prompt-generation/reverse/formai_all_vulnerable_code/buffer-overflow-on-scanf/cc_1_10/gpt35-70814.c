//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// function prototypes
int generateRandomNumber(int min, int max);
char generateRandomChar(char* charArray, int size);
int isPasswordValid(char* password);

int main()
{
    // Welcome message
    printf("Oh password, password, wherefore art thou password?\n");
    printf("This program shall generate one for thou!\n");
    printf("Enter thou desired password length: ");

    // get user input
    int passwordLength;
    scanf("%d", &passwordLength);

    // arrays of characters to randomly select from
    char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char specialChars[] = "!@#$%^&*()_-=+{}[]|:;<>,.?/~`";

    // choose random characters for the password based on user input
    char password[passwordLength+1];
    srand(time(NULL)); // seed random number with current time
    for(int i=0; i<passwordLength; i++)
    {
        int charType = generateRandomNumber(1, 4);
        switch(charType)
        {
            case 1: password[i] = generateRandomChar(lowercaseLetters, 26);
                    break;
            case 2: password[i] = generateRandomChar(uppercaseLetters, 26);
                    break;
            case 3: password[i] = generateRandomChar(numbers, 10);
                    break;
            case 4: password[i] = generateRandomChar(specialChars, 29);
                    break;
        }
    }
    password[passwordLength] = '\0'; // add null terminator at the end of the string

    // check if password is valid
    int valid = isPasswordValid(password);
    while(!valid)
    {
        printf("Oh, \'%s\' is not a strong enough password!\n", password);
        printf("Let us try again!\n");

        // choose random characters for the password based on user input
        for(int i=0; i<passwordLength; i++)
        {
            int charType = generateRandomNumber(1, 4);
            switch(charType)
            {
                case 1: password[i] = generateRandomChar(lowercaseLetters, 26);
                        break;
                case 2: password[i] = generateRandomChar(uppercaseLetters, 26);
                        break;
                case 3: password[i] = generateRandomChar(numbers, 10);
                        break;
                case 4: password[i] = generateRandomChar(specialChars, 29);
                        break;
            }
        }
        password[passwordLength] = '\0'; // add null terminator at the end of the string

        valid = isPasswordValid(password);
    }

    // display the generated password
    printf("Behold, thy secure password: %s\n", password);

    // end program
    printf("Parting is such sweet sorrow...\n");
    return 0;
}

// function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max)
{
    return (rand() % (max+1-min)) + min;
}

// function to generate a random character from charArray
char generateRandomChar(char* charArray, int size)
{
    int randomIndex = generateRandomNumber(0, size-1);
    return charArray[randomIndex];
}

// function to check if a password is valid (i.e. at least one lowercase, uppercase, number, and special character)
int isPasswordValid(char* password)
{
    int hasLowercase = 0;
    int hasUppercase = 0;
    int hasNumber = 0;
    int hasSpecial = 0;

    for(int i=0; password[i]!='\0'; i++)
    {
        if(islower(password[i]))
        {
            hasLowercase = 1;
        }
        else if(isupper(password[i]))
        {
            hasUppercase = 1;
        }
        else if(isdigit(password[i]))
        {
            hasNumber = 1;
        }
        else
        {
            hasSpecial = 1;
        }
    }

    if(hasLowercase && hasUppercase && hasNumber && hasSpecial)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}