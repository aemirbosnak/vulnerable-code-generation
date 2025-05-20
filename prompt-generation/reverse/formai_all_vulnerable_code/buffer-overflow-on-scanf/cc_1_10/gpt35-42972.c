//FormAI DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 20                        // Maximum number of passwords
#define MAX_PASSWORD_LENGTH 50                 // Maximum length of password

void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords);    // Function to add a password
void show_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords);   // Function to display all passwords
void search_password(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords);  // Function to search for a password
void delete_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords); // Function to delete a password
void save_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords);   // Function to save passwords to a file

int main()
{
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int num_passwords = 0;

    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Password\n");
        printf("2. Show Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Quit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                show_passwords(passwords, num_passwords);
                break;
            case 3:
                search_password(passwords, num_passwords);
                break;
            case 4:
                delete_password(passwords, &num_passwords);
                break;
            case 5:
                save_passwords(passwords, num_passwords);
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords)
{
    if (*num_passwords == MAX_PASSWORDS) {
        printf("\nMaximum number of passwords reached!\n");
        return;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("\nEnter the password to add: ");
    scanf("%s", password);

    strcpy(passwords[*num_passwords], password);
    (*num_passwords)++;

    printf("\nPassword added successfully!\n");
}

void show_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords)
{
    if (num_passwords == 0) {
        printf("\nNo passwords found!\n");
        return;
    }

    printf("\nAll Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

void search_password(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords)
{
    if (num_passwords == 0) {
        printf("\nNo passwords found!\n");
        return;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("\nEnter the password to search for: ");
    scanf("%s", password);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            printf("\nPassword found at position %d.\n", i+1);
            return;
        }
    }

    printf("\nPassword not found!\n");
}

void delete_password(char passwords[][MAX_PASSWORD_LENGTH], int *num_passwords)
{
    if (*num_passwords == 0) {
        printf("\nNo passwords found!\n");
        return;
    }

    int position;
    printf("\nEnter the position of the password to delete: ");
    scanf("%d", &position);

    if (position <= 0 || position > *num_passwords) {
        printf("\nInvalid position!\n");
        return;
    }

    for (int i = position-1; i < *num_passwords-1; i++) {
        strcpy(passwords[i], passwords[i+1]);
    }
    (*num_passwords)--;

    printf("\nPassword deleted successfully!\n");
}

void save_passwords(char passwords[][MAX_PASSWORD_LENGTH], int num_passwords)
{
    FILE *fptr;
    fptr = fopen("passwords.txt", "w");

    if (fptr == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    for (int i = 0; i < num_passwords; i++) {
        fprintf(fptr, "%s\n", passwords[i]);
    }

    fclose(fptr);

    printf("\nPasswords saved to file!\n");
}