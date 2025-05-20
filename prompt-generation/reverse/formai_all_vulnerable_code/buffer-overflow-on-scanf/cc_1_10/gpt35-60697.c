//FormAI DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for the password
#define MAX_PASSWORD_LENGTH 20

// Define the maximum number of attempts
#define MAX_ATTEMPTS 3

// Define the secret password
const char secret_password[MAX_PASSWORD_LENGTH] = "topsecret";

int main()
{
    // Declare variables
    char entered_password[MAX_PASSWORD_LENGTH];
    int attempts = 0;
    int password_is_correct = 0; // 0 = false, 1 = true

    // Greet the user
    printf("Welcome to the Secure Password Program.\n");

    // Loop until the correct password is entered or the maximum attempts are reached
    while (attempts < MAX_ATTEMPTS && password_is_correct == 0)
    {
        // Prompt the user to enter a password
        printf("Please enter the password: ");
        scanf("%s", entered_password);

        // Check if the entered password matches the secret password
        if (strcmp(entered_password, secret_password) == 0)
        {
            // Password is correct!
            printf("Congratulations! You have entered the correct password.\n");
            password_is_correct = 1;
        }
        else
        {
            // Password is incorrect
            printf("Incorrect password. Please try again.\n");
            attempts++;
        }
    }

    if (attempts >= MAX_ATTEMPTS && password_is_correct == 0)
    {
        // Maximum attempts reached
        printf("You have exceeded the maximum number of password attempts.\n");
    }

    return 0;
}