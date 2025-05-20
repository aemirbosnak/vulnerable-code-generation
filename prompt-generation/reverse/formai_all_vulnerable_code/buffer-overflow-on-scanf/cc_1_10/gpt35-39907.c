//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 25

// function to encrypt passwords
void encrypt(char password[])
{
    int i;
    for (i = 0; i < strlen(password); i++)
    {
        password[i] = password[i] + 3; // shift each character by 3 places
    }
}

// function to decrypt passwords
void decrypt(char password[])
{
    int i;
    for (i = 0; i < strlen(password); i++)
    {
        password[i] = password[i] - 3; // shift each character back by 3 places
    }
}

int main()
{
    char passwords[MAX_PASSWORDS][MAX_LENGTH];
    int numPasswords = 0;
    int i, option;
    char password[MAX_LENGTH];
    
    while (1) // loop until user selects option 4 to quit
    {
        printf("\nPassword Management System\n");
        printf("==========================\n");
        printf("1. Add a new password\n");
        printf("2. View existing passwords\n");
        printf("3. Delete a password\n");
        printf("4. Quit\n");
        printf("Enter your option: ");
        
        scanf("%d", &option);
        
        switch (option)
        {
            case 1:
                if (numPasswords == MAX_PASSWORDS) // check if maximum number of passwords have been added
                {
                    printf("Maximum number of passwords reached.\n");
                    break;
                }
                printf("Enter a new password (maximum length %d characters): ", MAX_LENGTH);
                scanf("%s", password);
                encrypt(password); // encrypt the password before storing it
                strcpy(passwords[numPasswords], password);
                numPasswords++;
                printf("Password added successfully.\n");
                break;
            case 2:
                if (numPasswords == 0) // check if there are no passwords added yet
                {
                    printf("No passwords added yet.\n");
                    break;
                }
                printf("Existing Passwords:\n");
                for (i = 0; i < numPasswords; i++)
                {
                    decrypt(passwords[i]); // decrypt the password before displaying it
                    printf("%d. %s\n", i+1, passwords[i]);
                    encrypt(passwords[i]); // encrypt the password again after displaying it
                }
                break;
            case 3:
                if (numPasswords == 0) // check if there are no passwords added yet
                {
                    printf("No passwords added yet.\n");
                    break;
                }
                printf("Enter the number of the password you want to delete: ");
                scanf("%d", &i);
                if (i <= 0 || i > numPasswords) // check if user enters a valid number
                {
                    printf("Invalid option.\n");
                    break;
                }
                for (i--; i < numPasswords-1; i++) // shift all passwords after the deleted password back by one position
                {
                    strcpy(passwords[i], passwords[i+1]);
                }
                numPasswords--;
                printf("Password deleted successfully.\n");
                break;
            case 4:
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}