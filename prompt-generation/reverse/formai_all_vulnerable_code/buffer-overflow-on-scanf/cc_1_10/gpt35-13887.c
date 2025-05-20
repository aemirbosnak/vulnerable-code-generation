//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generatePassword(char password[], int length)
{
    srand(time(NULL)); // Seed the random function with the current time

    for (int i = 0; i < length; i++)
    {
        int randNum = rand() % 4; // Generate a random number between 0 and 3

        if (randNum == 0)
        {
            password[i] = rand() % 10 + '0'; // Generate a random number between 0 and 9
        }
        else if (randNum == 1)
        {
            password[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
        }
        else if (randNum == 2)
        {
            password[i] = rand() % 26 + 'A'; // Generate a random uppercase letter
        }
        else
        {
            password[i] = rand() % 6 + '!'; // Generate a random special character
        }
    }

    password[length] = '\0'; // Add the null terminator at the end of the string
}

int main()
{
    char password[16]; // Declare an array to hold the generated password
    int length;

    printf("Enter the length of the password (8-16): ");
    scanf("%d", &length);

    if (length < 8 || length > 16)
    {
        printf("Invalid length. Length should be between 8 and 16.\n");
        exit(1);
    }

    generatePassword(password, length); // Generate the password

    printf("\nYour password is: %s\n", password);

    return 0;
}