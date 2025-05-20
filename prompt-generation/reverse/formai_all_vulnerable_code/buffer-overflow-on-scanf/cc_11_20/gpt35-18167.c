//FormAI DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char password[30], newPassword[30], confirmPassword[30];
    int passwordLength, upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;
    // initialize variables for password management

    printf("Please enter your password: ");
    scanf("%s", password);
    passwordLength = strlen(password);

    // check for password length and complexity

    if (passwordLength < 8)
    {
        printf("Your password is too short, it must be at least 8 characters long.");
        exit(0); // exits program if password is too short
    }
    else
    {
        for (int i = 0; i < passwordLength; i++)
        {
            if (isupper(password[i]))
            {
                upperCount++;
            }
            else if (islower(password[i]))
            {
                lowerCount++;
            }
            else if (isdigit(password[i]))
            {
                digitCount++;
            }
            else if (ispunct(password[i]))
            {
                specialCount++;
            }
        }

        // checks for password complexity

        if (upperCount == 0 || lowerCount == 0 || digitCount == 0 || specialCount == 0)
        {
            printf("Your password must contain at least one uppercase letter,\none lowercase letter, one digit and one special character.");
            exit(0); // exits program if password is not complex enough
        }

        printf("Your password meets the complexity requirements.\n");

        // prompts user to change password

        printf("Would you like to change your password? Type 'yes' to continue or 'no' to exit: ");
        char response[5];
        scanf("%s", response);

        if (strcmp(response, "yes") == 0)
        {
            printf("Please enter your new password: ");
            scanf("%s", newPassword);

            // checks if new password matches confirmed password

            printf("Please confirm your new password: ");
            scanf("%s", confirmPassword);

            if (strcmp(newPassword, confirmPassword) == 0)
            {
                printf("Your password has been updated.\n");
            }
            else
            {
                printf("Passwords do not match, please try again.\n");
                exit(0); // exits program if passwords do not match
            }
        }
        else if (strcmp(response, "no") == 0)
        {
            printf("Ok, thank you. Goodbye!\n");
            exit(0); // exits program if user does not want to change password
        }
        else
        {
            printf("Invalid response. Please try again.\n");
            exit(0); // exits program if user inputs invalid response
        }
    }

    return 0;
}