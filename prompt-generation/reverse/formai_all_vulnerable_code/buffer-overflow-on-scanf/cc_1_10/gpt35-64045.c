//FormAI DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Maximum number of passwords to be stored
#define MAX_PASSWORDS 100

// Maximum length of each password
#define MAX_PASSWORD_LENGTH 20

// Struct to store the password and its related information
typedef struct {
    char password[MAX_PASSWORD_LENGTH+1];
    char username[MAX_PASSWORD_LENGTH+1];
    char website[MAX_PASSWORD_LENGTH+1];
} password_info;

// Global array for storing all passwords
password_info passwords[MAX_PASSWORDS];
int num_passwords = 0;

// Function prototypes
void print_menu(void);
void add_password(void);
void view_passwords(void);
void search_passwords(void);

int main(void)
{
    int choice;

    while (true) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume the \n character

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_passwords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}

void print_menu(void)
{
    printf("\n");
    printf("1. Add a password\n");
    printf("2. View saved passwords\n");
    printf("3. Search for a password\n");
    printf("4. Exit\n");
}

void add_password(void)
{
    // Check if the maximum number of passwords has been reached
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    // Prompt user for password information
    printf("Enter website: ");
    fgets(passwords[num_passwords].website, MAX_PASSWORD_LENGTH+1, stdin);
    passwords[num_passwords].website[strcspn(passwords[num_passwords].website, "\n")] = '\0'; // remove trailing newline character

    printf("Enter username: ");
    fgets(passwords[num_passwords].username, MAX_PASSWORD_LENGTH+1, stdin);
    passwords[num_passwords].username[strcspn(passwords[num_passwords].username, "\n")] = '\0'; // remove trailing newline character

    printf("Enter password: ");
    fgets(passwords[num_passwords].password, MAX_PASSWORD_LENGTH+1, stdin);
    passwords[num_passwords].password[strcspn(passwords[num_passwords].password, "\n")] = '\0'; // remove trailing newline character

    printf("Password added successfully!\n");
    num_passwords++;
}

void view_passwords(void)
{
    // Check if there are any passwords saved
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    // Print out all saved passwords
    printf("Saved passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("Website: %s\n", passwords[i].website);
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

void search_passwords(void)
{
    // Check if there are any passwords saved
    if (num_passwords == 0) {
        printf("No passwords saved.\n");
        return;
    }

    // Prompt user for search query
    char search_query[MAX_PASSWORD_LENGTH+1];
    printf("Enter search query: ");
    fgets(search_query, MAX_PASSWORD_LENGTH+1, stdin);
    search_query[strcspn(search_query, "\n")] = '\0'; // remove trailing newline character

    // Search for matching passwords and print results
    bool found_match = false;
    printf("Search results:\n");
    for (int i = 0; i < num_passwords; i++) {
        if (strstr(passwords[i].website, search_query) != NULL ||
            strstr(passwords[i].username, search_query) != NULL ||
            strstr(passwords[i].password, search_query) != NULL) {
            printf("Website: %s\n", passwords[i].website);
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            printf("\n");
            found_match = true;
        }
    }

    if (!found_match) {
        printf("No matching passwords found.\n");
    }
}