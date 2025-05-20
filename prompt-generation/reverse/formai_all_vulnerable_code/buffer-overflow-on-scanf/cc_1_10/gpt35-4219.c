//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ENTRIES 10

struct password_entry {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Function prototypes
void print_menu();
void add_password(struct password_entry passwords[], int *num_entries);
void view_passwords(struct password_entry passwords[], int num_entries);
void delete_password(struct password_entry passwords[], int *num_entries);
void change_master_password(char *master_password);

int main()
{
    struct password_entry passwords[MAX_ENTRIES];
    int num_entries = 0;
    char master_password[MAX_PASSWORD_LENGTH];
    int menu_choice;

    // Set the master password
    printf("Enter the master password: ");
    scanf("%s", master_password);

    // Prompt user for menu selection
    do {
        print_menu();
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                add_password(passwords, &num_entries);
                break;
            case 2:
                view_passwords(passwords, num_entries);
                break;
            case 3:
                delete_password(passwords, &num_entries);
                break;
            case 4:
                change_master_password(master_password);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    } while (menu_choice != 5);

    return 0;
}

// Print the main menu
void print_menu()
{
    printf("\n");
    printf("1. Add new password\n");
    printf("2. View saved passwords\n");
    printf("3. Delete a password\n");
    printf("4. Change the Master Password\n");
    printf("5. Exit program\n");
    printf("Enter your choice: ");
}

// Add a new password entry
void add_password(struct password_entry passwords[], int *num_entries)
{
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    if (*num_entries == MAX_ENTRIES) {
        printf("Error: Maximum number of password entries reached.\n");
        return;
    }

    printf("Enter service name: ");
    scanf("%s", service);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Store the password entry
    strncpy(passwords[*num_entries].service, service, MAX_PASSWORD_LENGTH - 1);
    strncpy(passwords[*num_entries].username, username, MAX_PASSWORD_LENGTH - 1);
    strncpy(passwords[*num_entries].password, password, MAX_PASSWORD_LENGTH - 1);

    (*num_entries)++;
}

// View all saved passwords
void view_passwords(struct password_entry passwords[], int num_entries)
{
    int i;

    if (num_entries == 0) {
        printf("No password entries found.\n");
        return;
    }

    printf("\n");
    printf("Service Name\t\tUsername\t\tPassword\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < num_entries; i++) {
        printf("%-20s\t%-20s\t%-20s\n", passwords[i].service, passwords[i].username, passwords[i].password);
    }
}

// Delete a password entry
void delete_password(struct password_entry passwords[], int *num_entries)
{
    int i, j;
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];

    if (*num_entries == 0) {
        printf("No password entries found.\n");
        return;
    }

    printf("Enter service name of password to delete: ");
    scanf("%s", service);

    printf("Enter username of password to delete: ");
    scanf("%s", username);

    // Search for the password entry to delete
    for (i = 0; i < *num_entries; i++) {
        if (strncmp(passwords[i].service, service, MAX_PASSWORD_LENGTH - 1) == 0
            && strncmp(passwords[i].username, username, MAX_PASSWORD_LENGTH - 1) == 0) {

            // Shift all remaining entries back by one
            for (j = i; j < *num_entries - 1; j++) {
                passwords[j] = passwords[j + 1];
            }

            (*num_entries)--;

            printf("Password entry deleted.\n");
            return;
        }
    }

    printf("Password entry not found.\n");
}

// Change the master password
void change_master_password(char *master_password)
{
    char current_password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    char confirm_password[MAX_PASSWORD_LENGTH];

    // Prompt user to enter current password
    printf("Enter current master password: ");
    scanf("%s", current_password);

    if (strcmp(current_password, master_password) != 0) {
        printf("Incorrect password.\n");
        return;
    }

    // Prompt user enter new password
    printf("Enter new master password: ");
    scanf("%s", new_password);

    printf("Confirm new password: ");
    scanf("%s", confirm_password);

    if (strcmp(new_password, confirm_password) != 0) {
        printf("Passwords do not match.\n");
        return;
    }

    strncpy(master_password, new_password, MAX_PASSWORD_LENGTH - 1);

    printf("Master password changed.\n");
}