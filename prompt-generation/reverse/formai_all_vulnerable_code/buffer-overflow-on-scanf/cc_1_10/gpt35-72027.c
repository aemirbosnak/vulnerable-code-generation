//FormAI DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// constants
#define MAX_ENTRIES 10
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20
#define MASTER_PASSWORD "My$ecureP@ssword"

// data structures
typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} PasswordEntry;

// function prototypes
int validate_master_password(char[]);
bool validate_password_strength(char[]);
bool is_entry_already_exists(char[], PasswordEntry[], int);
int add_password_entry(char[], char[], PasswordEntry[], int);
int remove_password_entry(char[], PasswordEntry[], int);
int display_password_entries(PasswordEntry[], int);

// main function
int main() {
    PasswordEntry entries[MAX_ENTRIES];
    int num_entries = 0;

    // validate master password
    char input_master_password[MAX_PASSWORD_LEN];
    printf("Enter master password: ");
    scanf("%s", input_master_password);
    if (!validate_master_password(input_master_password)) {
        printf("Invalid master password\n");
        return 0;
    }

    // display main menu
    int choice;
    do {
        printf("\nPASSWORD MANAGER\n");
        printf("1. Add new entry\n");
        printf("2. Remove entry\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char input_username[MAX_USERNAME_LEN], input_password[MAX_PASSWORD_LEN];
                printf("Enter username: ");
                scanf("%s", input_username);
                printf("Enter password: ");
                scanf("%s", input_password);

                if (!validate_password_strength(input_password)) {
                    printf("Password is not strong enough. Try a stronger password.\n");
                    break;
                }

                if (is_entry_already_exists(input_username, entries, num_entries)) {
                    printf("Entry already exists with the same username.\n");
                    break;
                }

                num_entries = add_password_entry(input_username, input_password, entries, num_entries);
                printf("Entry added successfully.\n");

                break;
            }

            case 2: {
                char input_username[MAX_USERNAME_LEN];
                printf("Enter username to remove: ");
                scanf("%s", input_username);

                num_entries = remove_password_entry(input_username, entries, num_entries);
                if (num_entries < 0) {
                    printf("No entry found with the given username.\n");
                } else {
                    printf("Entry removed successfully.\n");
                }
                
                break;
            }

            case 3: {
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("Entries:\n");
                    display_password_entries(entries, num_entries);
                }

                break;
            }

            case 4: {
                printf("Exiting...\n");
                break;
            }

            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

// function definitions

// validates master password and returns true if valid, else false
int validate_master_password(char password[]) {
    return strcmp(password, MASTER_PASSWORD) == 0;
}

// validates password strength and returns true if strong enough, else false
bool validate_password_strength(char password[]) {
    int length = strlen(password);
    if (length < 8) {
        return false;
    }
    bool has_upper = false, has_lower = false, has_digit = false, has_special = false;
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (c >= 'A' && c <= 'Z') {
            has_upper = true;
        } else if (c >= 'a' && c <= 'z') {
            has_lower = true;
        } else if (c >= '0' && c <= '9') {
            has_digit = true;
        } else {
            has_special = true;
        }
    }
    return has_upper && has_lower && has_digit && has_special;
}

// checks if an entry with the same username already exists
bool is_entry_already_exists(char username[], PasswordEntry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].username, username) == 0) {
            return true;
        }
    }
    return false;
}

// adds a new password entry and returns the updated number of entries
int add_password_entry(char username[], char password[], PasswordEntry entries[], int num_entries) {
    PasswordEntry new_entry;
    strcpy(new_entry.username, username);
    strcpy(new_entry.password, password);
    entries[num_entries] = new_entry;
    return num_entries + 1;
}

// removes a password entry and returns the updated number of entries
int remove_password_entry(char username[], PasswordEntry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].username, username) == 0) {
            for (int j = i; j < num_entries-1; j++) {
                entries[j] = entries[j+1];
            }
            return num_entries - 1;
        }
    }
    return -1;
}

// displays all password entries
int display_password_entries(PasswordEntry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("Username: %s, Password: %s\n", entries[i].username, entries[i].password);
    }
    return num_entries;
}