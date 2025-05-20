//Gemma-7B DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{

    system("clear");

    // Initialize variables
    char username[20] = "";
    char password[20] = "";
    char confirmation[20] = "";

    // Get username
    printf("Enter your username: ");
    scanf("%s", username);

    // Get password
    printf("Enter your password: ");
    scanf("%s", password);

    // Get confirmation
    printf("Enter your password again: ");
    scanf("%s", confirmation);

    // Compare passwords
    if (strcmp(password, confirmation) == 0)
    {
        // Encrypt password
        char encrypted_password[20] = "";
        int key = rand() % 10;
        for (int i = 0; i < strlen(password); i++)
        {
            encrypted_password[i] = password[i] ^ key;
        }

        // Store encrypted password
        FILE *fp = fopen("passwords.txt", "a");
        fprintf(fp, "%s\n", encrypted_password);
        fclose(fp);

        // Display confirmation message
        printf("Password successfully stored.\n");
    }
    else
    {
        // Display error message
        printf("Passwords do not match.\n");
    }

    return 0;
}