//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_NOTE_LENGTH 255
#define MAX_ENTRIES 50
#define FILE_NAME "passwords.txt"

typedef struct
{
    char site[MAX_NOTE_LENGTH];
    char username[MAX_NOTE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry entries[MAX_ENTRIES];
int count = 0;

void loadPasswords();
void savePasswords();
void addPassword();
void displayPasswords();
void findPassword();
void clearBuffer();

int main()
{
    int choice;

    loadPasswords();

    do
    {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Find Password\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Flush the input buffer

        switch (choice)
        {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                findPassword();
                break;
            case 4:
                savePasswords();
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}

void loadPasswords()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        printf("No password file found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%s %s %s\n", entries[count].site, entries[count].username, entries[count].password) != EOF)
    {
        count++;
        if (count >= MAX_ENTRIES)
            break;
    }

    fclose(file);
}

void savePasswords()
{
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL)
    {
        printf("Error saving passwords!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s %s %s\n", entries[i].site, entries[i].username, entries[i].password);
    }

    fclose(file);
}

void addPassword()
{
    if (count >= MAX_ENTRIES)
    {
        printf("Password storage is full!\n");
        return;
    }

    printf("Enter site: ");
    fgets(entries[count].site, MAX_NOTE_LENGTH, stdin);
    entries[count].site[strcspn(entries[count].site, "\n")] = '\0'; // Remove newline

    printf("Enter username: ");
    fgets(entries[count].username, MAX_NOTE_LENGTH, stdin);
    entries[count].username[strcspn(entries[count].username, "\n")] = '\0'; // Remove newline

    printf("Enter password: ");
    fgets(entries[count].password, MAX_PASSWORD_LENGTH, stdin);
    entries[count].password[strcspn(entries[count].password, "\n")] = '\0'; // Remove newline

    count++;
    printf("Password added successfully!\n");
}

void displayPasswords()
{
    if (count == 0)
    {
        printf("No stored passwords!\n");
        return;
    }

    printf("\nStored Passwords:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("Site: %s\nUsername: %s\nPassword: %s\n\n", entries[i].site, entries[i].username, entries[i].password);
    }
}

void findPassword()
{
    char site[MAX_NOTE_LENGTH];
    printf("Enter the site you wish to find: ");
    fgets(site, MAX_NOTE_LENGTH, stdin);
    site[strcspn(site, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < count; i++)
    {
        if (strcmp(entries[i].site, site) == 0)
        {
            printf("Site: %s\nUsername: %s\nPassword: %s\n", entries[i].site, entries[i].username, entries[i].password);
            return;
        }
    }
    printf("No entry found for the site: %s\n", site);
}

void clearBuffer()
{
    while (getchar() != '\n'); // Flush the input buffer
}