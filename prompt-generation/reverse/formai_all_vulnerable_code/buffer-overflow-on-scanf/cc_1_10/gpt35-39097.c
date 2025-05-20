//FormAI DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

// Function prototypes
void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]);
void view_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]);
void search_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]);
void delete_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]);

int main()
{
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]; // Array to store passwords
    int option;

    // Display menu options to the user
    while (1)
    {
        printf("Password Management System\n");
        printf("-------------------------------------------\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Delete a password\n");
        printf("5. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter option number: ");
        scanf("%d", &option);
        printf("\n");

        // Get user input based on their menu option choice
        switch (option)
        {
            case 1: add_password(passwords); break;
            case 2: view_passwords(passwords); break;
            case 3: search_password(passwords); break;
            case 4: delete_password(passwords); break;
            case 5: exit(0);
            default: printf("Invalid option\n"); break;
        }

        printf("\n");
    }

    return 0;
}

// Function to add a password to the array
void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH])
{
    char password[MAX_PASSWORD_LENGTH]; // Temporary variable to hold password

    printf("Enter password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
    scanf("%s", password);

    // Check if password already exists in the array
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (strcmp(password, passwords[i]) == 0)
        {
            printf("Password already exists\n");
            return;
        }
    }

    // Check if array is full
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (strcmp(passwords[i], "") == 0)
        {
            strncpy(passwords[i], password, MAX_PASSWORD_LENGTH);
            printf("Password added successfully\n");
            return;
        }
    }

    printf("Password storage capacity has been reached\n");
}

// Function to view all passwords in the array
void view_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH])
{
    // Check if array is empty
    int empty = 1;
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (strcmp(passwords[i], "") != 0)
        {
            empty = 0;
            break;
        }
    }

    if (empty)
    {
        printf("No passwords to display\n");
        return;
    }

    printf("All Passwords:\n");
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (strcmp(passwords[i], "") != 0)
        {
            printf("%d. %s\n", i+1, passwords[i]);
        }
    }
}

// Function to search for a password in the array
void search_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH])
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password to search: ");
    scanf("%s", password);

    // Convert password to lowercase
    for (int i = 0; i < strlen(password); i++)
    {
        password[i] = tolower(password[i]);
    }

    // Check if password exists in the array
    int found = 0;
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        char temp[MAX_PASSWORD_LENGTH];
        strcpy(temp, passwords[i]);

        // Convert temporary password to lowercase
        for (int j = 0; j < strlen(temp); j++)
        {
            temp[j] = tolower(temp[j]);
        }

        if (strcmp(password, temp) == 0)
        {
            printf("Password found at index %d\n", i+1);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Password not found\n");
    }
}

// Function to delete a password from the array
void delete_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH])
{
    int index;

    printf("Enter password index to delete: ");
    scanf("%d", &index);

    // Check if index is valid
    if (index < 1 || index > MAX_PASSWORDS || strcmp(passwords[index-1], "") == 0)
    {
        printf("Invalid index\n");
        return;
    }

    // Delete password at index
    memset(passwords[index-1], '\0', MAX_PASSWORD_LENGTH);
    printf("Password deleted successfully\n");
}