//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[20], sanitized_password[20], temp_password[20];
    int i = 0, j = 0;

    printf("Please enter your password: ");
    scanf("%s", password);

    printf("\nSanitizing user input...\n");

    // Remove whitespace characters at the beginning and end of the password
    while (password[i] == ' ')
    {
        i++;
    }

    j = strlen(password) - 1;
    while (password[j] == ' ')
    {
        j--;
    }

    if (i > j)
    {
        printf("\nAll characters are whitespace!\n");
        return 0;
    }

    for(int k = i; k <= j; k++)
    {
        temp_password[k-i] = password[k];
    }

    temp_password[j-i+1] = '\0'; // Add null terminator to end of string

    // Remove any characters that are not letters or numbers
    for(int k = 0; temp_password[k] != '\0'; k++)
    {
        if(isalnum(temp_password[k]))
        {
            sanitized_password[k] = temp_password[k];
        }
    }

    sanitized_password[strlen(sanitized_password)] = '\0'; // Add null terminator to end of string

    printf("\nYour sanitized password is: %s\n", sanitized_password);

    return 0;
}