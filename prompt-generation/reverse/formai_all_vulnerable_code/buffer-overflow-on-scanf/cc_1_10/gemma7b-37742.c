//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **passwords = NULL;
    int num_passwords = 0;

    // Paranoia: Always expect the worst.
    passwords = malloc(1000 * sizeof(char *));
    if (passwords == NULL)
    {
        printf("Error allocating memory!");
        exit(1);
    }

    // Gather passwords from the user.
    printf("Enter your passwords: ");
    scanf("%s", passwords[num_passwords]);
    num_passwords++;

    // Repeat the process for multiple passwords.
    while (1)
    {
        printf("Enter another password (optional): ");
        char *password = malloc(100 * sizeof(char));
        if (password == NULL)
        {
            printf("Error allocating memory!");
            exit(1);
        }
        scanf("%s", password);

        if (strcmp(password, passwords[0]) == 0)
        {
            printf("You entered the same password as the first one.\n");
        }
        else
        {
            passwords = realloc(passwords, (num_passwords + 1) * sizeof(char *));
            passwords[num_passwords] = password;
            num_passwords++;
        }

        // Check if the user wants to continue.
        char continue_char;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_char);

        if (continue_char == 'N')
        {
            break;
        }
    }

    // Free the memory allocated for passwords.
    for (int i = 0; i < num_passwords; i++)
    {
        free(passwords[i]);
    }
    free(passwords);

    return 0;
}