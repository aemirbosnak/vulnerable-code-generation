//FormAI DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char master_password[20], choice;
    int num_passwords = 0;
    char **passwords = NULL;

    printf("Welcome to the Password Manager!\n");

    // Get the master password
    printf("Enter the master password: ");
    scanf("%s", master_password);

    while (1)
    {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == '1')
        {
            char *new_password = malloc(20 * sizeof(char));
            if (new_password == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1;
            }

            // Get the new password
            printf("Enter the new password: ");
            scanf("%s", new_password);

            // Encrypt the password using the master password
            for (int i = 0; i < strlen(new_password); i++)
            {
                new_password[i] ^= master_password[i % strlen(master_password)];
            }

            // Add the new password to the array
            num_passwords++;
            passwords = realloc(passwords, num_passwords * sizeof(char *));
            passwords[num_passwords - 1] = new_password;

            printf("Password added successfully!\n");
        }
        else if (choice == '2')
        {
            // Print out all of the passwords
            printf("Passwords:\n");
            for (int i = 0; i < num_passwords; i++)
            {
                char *encrypted = passwords[i];
                char *decrypted = malloc((strlen(encrypted) + 1) * sizeof(char));
                if (decrypted == NULL)
                {
                    printf("Memory allocation failed.\n");
                    return 1;
                }

                // Decrypt the password
                for (int j = 0; j < strlen(encrypted); j++)
                {
                    decrypted[j] = encrypted[j] ^ master_password[j % strlen(master_password)];
                }
                decrypted[strlen(encrypted)] = '\0';

                printf("%s\n", decrypted);
                free(decrypted);
            }
        }
        else if (choice == '3')
        {
            // Free all of the allocated memory and exit
            for (int i = 0; i < num_passwords; i++)
            {
                free(passwords[i]);
            }
            free(passwords);

            printf("Exiting...\n");
            exit(0);
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}