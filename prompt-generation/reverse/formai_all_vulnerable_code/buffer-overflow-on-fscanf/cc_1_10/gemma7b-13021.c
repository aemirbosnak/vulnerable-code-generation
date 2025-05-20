//Gemma-7B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define PASSWORD_FILE "passwords.txt"

int main()
{
    char username[256];
    char password[256];
    char new_password[256];
    char confirm_password[256];
    int i, j, flag = 0, file_flag = 0;

    system("clear");

    // Check if the password file exists
    if (stat(PASSWORD_FILE, NULL) == 0)
    {
        file_flag = 1;
    }

    // Get the username
    printf("Enter your username: ");
    scanf("%s", username);

    // Get the current password
    printf("Enter your current password: ");
    scanf("%s", password);

    // Compare the password to the file
    if (file_flag)
    {
        FILE *fp = fopen(PASSWORD_FILE, "r");
        char file_password[256];

        while (fscanf(fp, "%s", file_password) != EOF)
        {
            if (strcmp(file_password, password) == 0)
            {
                flag = 1;
                break;
            }
        }

        fclose(fp);
    }

    // If the password is not correct, display an error message
    if (flag == 0)
    {
        printf("Error: Invalid password.\n");
        exit(1);
    }

    // Get the new password
    printf("Enter a new password: ");
    scanf("%s", new_password);

    // Confirm the new password
    printf("Confirm your new password: ");
    scanf("%s", confirm_password);

    // If the new password does not match the confirm password, display an error message
    if (strcmp(new_password, confirm_password) != 0)
    {
        printf("Error: The new passwords do not match.\n");
        exit(1);
    }

    // Update the password file
    if (file_flag)
    {
        FILE *fp = fopen(PASSWORD_FILE, "w");
        fprintf(fp, "%s\n", new_password);
        fclose(fp);
    }

    // Display a success message
    printf("Password changed successfully.\n");

    return 0;
}