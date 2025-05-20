//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20

void generateRandomPassword(char *password, int length);
char getRandomSymbol();
char getRandomLowercaseLetter();
char getRandomUppercaseLetter();
char getRandomNumber();

int main()
{
    char password[MAX_LENGTH + 1]; // Add 1 for null terminator
    int length;

    srand(time(NULL)); // Seed random number generator with current time

    printf("Enter desired length for password (max %d): ", MAX_LENGTH);
    scanf("%d", &length);

    if (length <= 0 || length > MAX_LENGTH)
    {
        printf("Invalid length specified.\n");
        return 0;
    }

    generateRandomPassword(password, length);

    printf("Your new password is: %s\n", password);

    return 0;
}

/* Generate a random password of specified length */
void generateRandomPassword(char *password, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        switch(rand() % 4)
        {
            case 0:
                password[i] = getRandomSymbol();
                break;
            case 1:
                password[i] = getRandomLowercaseLetter();
                break;
            case 2:
                password[i] = getRandomUppercaseLetter();
                break;
            case 3:
                password[i] = getRandomNumber();
                break;
        }
    }

    password[length] = '\0'; // Null terminate the password string
}

/* Generate a random symbol character */
char getRandomSymbol()
{
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '='};
    return symbols[rand() % (sizeof(symbols) / sizeof(char))];
}

/* Generate a random lowercase letter */
char getRandomLowercaseLetter()
{
    return 'a' + rand() % 26;
}

/* Generate a random uppercase letter */
char getRandomUppercaseLetter()
{
    return 'A' + rand() % 26;
}

/* Generate a random number */
char getRandomNumber()
{
    return '0' + rand() % 10;
}