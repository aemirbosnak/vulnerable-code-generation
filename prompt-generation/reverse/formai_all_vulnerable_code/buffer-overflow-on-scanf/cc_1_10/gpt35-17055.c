//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomNumber(int min, int max);
char generateRandomSymbol();
char generateRandomLetter();
char generateRandomDigit();
void generatePassword(int length);

int main()
{
    int length;

    printf("Welcome to the C Secure Password Generator!\n");
    printf("Please enter the length of the password you would like to generate (8-16): ");
    scanf("%d", &length);

    // Check for valid length input
    if (length < 8 || length > 16)
    {
        printf("Invalid password length. Please enter a length between 8 and 16.\n");
        return 0;
    }

    // Generate password
    generatePassword(length);

    return 0;
}

// Function to generate random number between min and max
int generateRandomNumber(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// Function to generate random symbol from ASCII table values
char generateRandomSymbol()
{
    int symbol = generateRandomNumber(33, 47);
    return (char)symbol;
}

// Function to generate random letter from ASCII table values
char generateRandomLetter()
{
    int letter = generateRandomNumber(65, 90);
    return (char)letter;
}

// Function to generate random digit from ASCII table values
char generateRandomDigit()
{
    int digit = generateRandomNumber(48, 57);
    return (char)digit;
}

// Function to generate password of given length
void generatePassword(int length)
{
    int i;
    char password[17];

    // Seed random number generator
    srand(time(NULL));

    // Generate password
    for (i = 0; i < length; i++)
    {
        int type = generateRandomNumber(0, 2); // 0 = symbol, 1 = letter, 2 = digit

        if (type == 0)
        {
            password[i] = generateRandomSymbol();
        }
        else if (type == 1)
        {
            password[i] = generateRandomLetter();
        }
        else
        {
            password[i] = generateRandomDigit();
        }
    }

    password[length] = '\0'; // Terminate string with null character

    // Print password
    printf("Your new password is: %s\n", password);
}