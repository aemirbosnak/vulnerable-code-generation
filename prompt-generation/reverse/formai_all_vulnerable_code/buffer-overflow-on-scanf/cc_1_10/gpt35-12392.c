//FormAI DATASET v1.0 Category: Digital Diary ; Style: genious
#include <stdio.h>    // Standard input and output header file
#include <stdlib.h>   // Standard library header file
#include <string.h>   // String handling header file
#include <stdbool.h>  // Boolean header file

// Constants
#define MAX_ENTRY_LENGTH 1000000
#define MAX_ENTRIES 1000
#define PASSWORD "mysecretpassword"

// Structure for entries
struct entry
{
    char title[100];
    char date[15];
    char content[MAX_ENTRY_LENGTH];
};

// Function prototypes
void display_menu();
void add_entry();
void view_entries();
void delete_entry();
void change_password();
bool authenticate();

// Global variable declaration
struct entry diary[MAX_ENTRIES];
int num_entries = 0;

// Main function
int main()
{
    int choice;
    bool authenticated = false;

    printf("Welcome to My Digital Diary!\n");

    authenticated = authenticate();

    if (!authenticated)
    {
        printf("Authentication failed. Exiting...\n");
        return 1;
    }

    while (1)
    {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                change_password();
                break;
            case 5:
                printf("Thank you for using My Digital Diary!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display menu
void display_menu()
{
    printf("\n");
    printf("1. Add an entry\n");
    printf("2. View entries\n");
    printf("3. Delete an entry\n");
    printf("4. Change password\n");
    printf("5. Exit\n");
    printf("\n");
}

// Function to add new entry
void add_entry()
{
    struct entry new_entry;

    printf("\n");
    printf("Enter the title of your entry: ");
    scanf(" %[^\n]s", new_entry.title);

    printf("Enter the date (DD/MM/YYYY) of your entry: ");
    scanf("%s", new_entry.date);

    printf("Enter your content: ");
    scanf(" %[^\n]s", new_entry.content);

    diary[num_entries] = new_entry;
    num_entries++;

    printf("\nEntry added successfully!\n");
}

// Function to view diary entries
void view_entries()
{
    int i;

    if (num_entries == 0)
    {
        printf("\nYou have no entries in your diary.\n");
    }
    else
    {
        printf("\nYour diary entries:\n");

        for (i = 0; i < num_entries; i++)
        {
            printf("\nTitle: %s\n", diary[i].title);
            printf("Date: %s\n", diary[i].date);
            printf("Content: %s\n", diary[i].content);
        }
    }
}

// Function to delete an entry
void delete_entry()
{
    int i, index;
    char confirm;

    if (num_entries == 0)
    {
        printf("\nYou have no entries in your diary.\n");
    }
    else
    {
        printf("\nEnter the index (1-%d) of the entry you want to delete: ", num_entries);
        scanf("%d", &index);

        if (index < 1 || index > num_entries)
        {
            printf("Invalid index. Please try again.\n");
        }
        else
        {
            printf("\nAre you sure you want to delete the entry? (Y/N) ");
            scanf(" %c", &confirm);

            if (confirm == 'Y' || confirm == 'y')
            {
                for (i = index-1; i < num_entries-1; i++)
                {
                    diary[i] = diary[i+1];
                }

                num_entries--;

                printf("\nEntry deleted successfully!\n");
            }
        }
    }
}

// Function to change password
void change_password()
{
    char new_password[50], confirm_password[50];

    printf("\nEnter your new password: ");
    scanf(" %s", new_password);

    printf("Confirm your new password: ");
    scanf(" %s", confirm_password);

    if (strcmp(new_password, confirm_password) == 0)
    {
        strcpy(PASSWORD, new_password);
        printf("\nPassword changed successfully!\n");
    }
    else
    {
        printf("\nPasswords do not match. Try again.\n");
    }
}

// Function to authenticate user
bool authenticate()
{
    char password_attempt[50];

    printf("\nPlease authenticate yourself.\n");

    printf("Enter the password: ");
    scanf(" %s", password_attempt);

    while (strcmp(password_attempt, PASSWORD) != 0)
    {
        printf("Authentication failed. Try again.\n");

        printf("Enter the password: ");
        scanf(" %s", password_attempt);
    }

    printf("\nAuthentication successful!\n");

    return true;
}