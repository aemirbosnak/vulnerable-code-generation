//FormAI DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50 // maximum number of passwords that can be stored
#define LENGTH 20 // maximum length of password

struct Password
{
    char website[LENGTH];
    char username[LENGTH];
    char password[LENGTH];
};

// function to save password to file
void savePassword(struct Password passwords[], int count)
{
    FILE *fp;
    fp = fopen("passwords.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }

    fclose(fp);
}

// function to add new password
void addPassword(struct Password passwords[], int *count)
{
    if (*count == MAX)
    {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    char website[LENGTH];
    printf("Enter website: ");
    scanf("%s", website);

    char username[LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    char password[LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    struct Password new_password;
    strcpy(new_password.website, website);
    strcpy(new_password.username, username);
    strcpy(new_password.password, password);

    passwords[*count] = new_password;
    (*count)++;

    savePassword(passwords, *count);
}

// function to display all stored passwords
void displayPasswords(struct Password passwords[], int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }
}

// function to prompt user for action
int prompt()
{
    printf("Enter 1 to add password.\n");
    printf("Enter 2 to display passwords.\n");
    printf("Enter 3 to exit.\n");

    int choice;
    printf("Choice: ");
    scanf("%d", &choice);

    return choice;
}

int main()
{
    struct Password passwords[MAX];
    int count = 0;

    FILE *fp;
    fp = fopen("passwords.txt", "r");

    if (fp != NULL)
    {
        while (!feof(fp))
        {
            char website[LENGTH];
            char username[LENGTH];
            char password[LENGTH];

            fscanf(fp, "%s %s %s", website, username, password);

            struct Password new_password;
            strcpy(new_password.website, website);
            strcpy(new_password.username, username);
            strcpy(new_password.password, password);

            passwords[count] = new_password;
            count++;
        }

        fclose(fp);
    }

    int choice;
    do
    {
        choice = prompt();

        switch (choice)
        {
            case 1:
                addPassword(passwords, &count);
                break;

            case 2:
                displayPasswords(passwords, count);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}