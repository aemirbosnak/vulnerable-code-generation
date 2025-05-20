//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 12
#define UPPER 'U'
#define LOWER 'L'
#define DIGIT 'D'
#define SYMBOL 'S'

void printPassword(char password[]);

int main()
{
    srand(time(NULL));
    printf("Welcome to the Cryptic Password Generator!\n");

    int length = MIN_LENGTH;
    printf("Enter the length of the password you would like (minimum %d): ", MIN_LENGTH);
    scanf("%d", &length);
    while (length < MIN_LENGTH)
    {
        printf("Invalid length. Please enter a length of at least %d: ", MIN_LENGTH);
        scanf("%d", &length);
    }
    printf("Generating a %d character password...\n\n", length);

    char password[length + 1];
    password[length] = '\0';
    int i = 0;

    int numUppers = rand() % (length/4) + 2; // at least 2 uppercase letters
    for (int j = 0; j < numUppers; j++)
    {
        password[i++] = rand() % 26 + 'A'; // uppercase letter
    }

    int numLowers = rand() % (length/2) + 2; // at least 2 lowercase letters
    for (int j = 0; j < numLowers; j++)
    {
        password[i++] = rand() % 26 + 'a'; // lowercase letter
    }

    int numDigits = rand() % (length/4) + 2; // at least 2 digits
    for (int j = 0; j < numDigits; j++)
    {
        password[i++] = rand() % 10 + '0'; // digit
    }

    int numSymbols = length - numUppers - numLowers - numDigits;
    char symbols[][7] = {"!@#$%^&*()-_=+[]{}\\|;:'\",.<>/?", "~`"};
    char symbolType;
    for (int j = 0; j < numSymbols; j++)
    {
        symbolType = rand() % 2 == 0 ? SYMBOL : rand() % 2 == 0 ? symbols[0][rand() % 30] : symbols[1][rand() % 2];
        password[i++] = symbolType;
    }

    printPassword(password);
    printf("\nSecurity Level: Cryptic");

    return 0;
}

void printPassword(char password[])
{
    printf("Your password is: ");
    for (int i = 0; password[i]; i++)
    {
        printf("%c", password[i]);
    }
}