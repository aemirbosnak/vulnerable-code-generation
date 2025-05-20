//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 20
#define MAX_PASSWORD_LENGTH 20

void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords);
void remove_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords);
void list_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords);

int main()
{
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    int choice;

    printf("Welcome to Password Manager\n");

    do
    {
        printf("\nPlease select an option:\n");
        printf("1. Add a password\n");
        printf("2. Remove a password\n");
        printf("3. List all passwords\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                remove_password(passwords, &num_passwords);
                break;
            case 3:
                list_passwords(passwords, num_passwords);
                break;
            case 4:
                printf("\nThank you for using Password Manager!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords)
{
    char password[MAX_PASSWORD_LENGTH];

    if(*num_passwords >= MAX_PASSWORDS)
    {
        printf("\nPassword storage is full! Cannot add more passwords.\n");
        return;
    }

    printf("\nEnter the password to add (max %d characters):\n", MAX_PASSWORD_LENGTH);
    scanf("%s", password);

    // Add the password to the list
    strncpy(passwords[*num_passwords], password, MAX_PASSWORD_LENGTH);
    (*num_passwords)++;

    printf("\nPassword added!\n");
}

void remove_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords)
{
    int i, j;
    char password[MAX_PASSWORD_LENGTH];

    printf("\nEnter the password to remove:\n");
    scanf("%s", password);

    // Find the password index, if it exists
    for(i = 0; i < *num_passwords; i++)
    {
        if(strcmp(passwords[i], password) == 0)
        {
            // Shift all passwords after the removed password back by one index
            for(j = i; j < *num_passwords - 1; j++)
            {
                strncpy(passwords[j], passwords[j + 1], MAX_PASSWORD_LENGTH);
            }

            (*num_passwords)--;
            printf("\nPassword removed!\n");
            return;
        }
    }

    printf("\nPassword not found!\n");
}

void list_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords)
{
    int i;

    printf("\nAll passwords:\n");

    for(i = 0; i < num_passwords; i++)
    {
        printf("- %s\n", passwords[i]);
    }
}