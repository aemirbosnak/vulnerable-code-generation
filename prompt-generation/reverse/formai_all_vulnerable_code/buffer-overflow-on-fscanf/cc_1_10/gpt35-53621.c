//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include<stdio.h>
#include<string.h>

int main()
{
    char password[50];
    char confirm_password[50];

    printf("Welcome to the Password Management System!\n");

    // New password prompt
    printf("Please enter your new password: ");
    scanf("%s", password);

    // Password confirmation prompt
    printf("Please confirm your new password: ");
    scanf("%s", confirm_password);

    // Check if the passwords match
    if(strcmp(password, confirm_password) == 0)
    {
        printf("Password successfully set!\n");
    }
    else
    {
        printf("Passwords do not match. Please try again.\n");

        // Loop until passwords match
        while(strcmp(password, confirm_password) != 0)
        {
            printf("Please enter your new password: ");
            scanf("%s", password);
            printf("Please confirm your new password: ");
            scanf("%s", confirm_password);
        }

        printf("Password successfully set!\n");
    }

    // Saving the password to a file
    FILE *fptr;

    fptr = fopen("password.txt", "w");

    if(fptr == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        fprintf(fptr, "%s", password);
        fclose(fptr);
    }

    // Password check prompt
    char input_password[50];

    printf("Please enter your password to access the system: ");
    scanf("%s", input_password);

    // Compare with saved password
    fptr = fopen("password.txt", "r");

    if(fptr == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        char saved_password[50];

        fscanf(fptr,"%s", saved_password);

        if(strcmp(input_password, saved_password) == 0)
        {
            printf("Access granted!\n");
        }
        else
        {
            printf("Incorrect password. Access denied.\n");
        }

        fclose(fptr);
    }

    return 0;
}