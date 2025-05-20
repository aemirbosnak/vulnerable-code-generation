//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define MINLENGTH 8       // Minimum length of password
#define MAXLENGTH 16      // Maximum length of password
#define NUMSYMBOLS 12     // Total number of symbols

// Arrays to store upper case letters, lower case letters, digits and special characters
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()_+-={}[]:<>,.?/";

// Function declarations
void generatePassword(int length, char password[]);
int checkPassword(char pwd[]);
int containsUppercase(char pwd[]);
int containsLowercase(char pwd[]);
int containsDigits(char pwd[]);
int containsSymbols(char pwd[]);

int main()
{
    int length;
    char password[MAXLENGTH + 1];     // Initializing the password array with extra 1 byte for null character

    // Prompting user for password length until valid input
    while(1)
    {
        printf("Enter password length (8-16): ");
        if(scanf("%d", &length) != 1 || length < MINLENGTH || length > MAXLENGTH)
        {
            printf("Invalid input! Try again.\n\n");
            while(getchar() != '\n');   // Clearing input buffer
            continue;
        }
        break;
    }

    generatePassword(length, password);   // Generating password

    printf("Generated Password: %s\n", password);

    if(checkPassword(password) == 1)
        printf("Password is Secure!\n");
    else
        printf("Password is NOT Secure!\n");

    return 0;
}


// Function to generate password of given length
void generatePassword(int length, char password[])
{
    srand(time(0));   // Seed for random number generation

    int uppercount = 0, lowercount = 0, digitcount = 0, symbolcount = 0;
    int i = 0, j = 0;

    // Choosing at least one character from each category
    password[i++] = uppercase[rand() % 26];
    password[i++] = lowercase[rand() % 26];
    password[i++] = digits[rand() % 10];
    password[i++] = symbols[rand() % NUMSYMBOLS];

    uppercount++;
    lowercount++;
    digitcount++;
    symbolcount++;

    // Choosing remaining characters
    for(j = i; j < length; j++)
    {
        int category = rand() % 4;

        switch(category)
        {
            case 0: password[j] = uppercase[rand() % 26];
                    uppercount++;
                    break;
            case 1: password[j] = lowercase[rand() % 26];
                    lowercount++;
                    break;
            case 2: password[j] = digits[rand() % 10];
                    digitcount++;
                    break;
            case 3: password[j] = symbols[rand() % NUMSYMBOLS];
                    symbolcount++;
                    break;
        }
    }

    password[length] = '\0';   // Adding null character at the end

    // Checking if generated password contains at least two characters from each category
    if(uppercount < 2)
        password[rand() % length] = uppercase[rand() % 26];
    if(lowercount < 2)
        password[rand() % length] = lowercase[rand() % 26];
    if(digitcount < 2)
        password[rand() % length] = digits[rand() % 10];
    if(symbolcount < 2)
        password[rand() % length] = symbols[rand() % NUMSYMBOLS];
}


// Function to check if password is secure
int checkPassword(char pwd[])
{
    if(!containsUppercase(pwd))
        return 0;
    if(!containsLowercase(pwd))
        return 0;
    if(!containsDigits(pwd))
        return 0;
    if(!containsSymbols(pwd))
        return 0;
    return 1;
}


// Function to check if password contains at least one uppercase letter
int containsUppercase(char pwd[])
{
    int i;
    for(i = 0; pwd[i] != '\0'; i++)
    {
        if(isupper(pwd[i]))
            return 1;
    }
    return 0;
}


// Function to check if password contains at least one lowercase letter
int containsLowercase(char pwd[])
{
    int i;
    for(i = 0; pwd[i] != '\0'; i++)
    {
        if(islower(pwd[i]))
            return 1;
    }
    return 0;
}


// Function to check if password contains at least one digit
int containsDigits(char pwd[])
{
    int i;
    for(i = 0; pwd[i] != '\0'; i++)
    {
        if(isdigit(pwd[i]))
            return 1;
    }
    return 0;
}


// Function to check if password contains at least one symbol
int containsSymbols(char pwd[])
{
    int i;
    for(i = 0; pwd[i] != '\0'; i++)
    {
        if(!isalnum(pwd[i]))
            return 1;
    }
    return 0;
}