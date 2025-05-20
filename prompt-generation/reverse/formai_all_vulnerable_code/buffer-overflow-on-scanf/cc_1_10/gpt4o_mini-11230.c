//GPT-4o-mini DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_ENTRIES 10
#define HASH_SIZE 128

// Basic structure to hold a password entry
typedef struct {
    char site[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Entry;

// Hashing function for the passwords - simple and paranoid
unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_SIZE;  // Ensure we stay within hash table limits
}

// A simple structure to simulate a password manager
typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} PasswordManager;

// Initialize the password manager
void init_password_manager(PasswordManager *manager) {
    manager->count = 0;
}

// Function to add a new password entry
void add_entry(PasswordManager *manager, char *site, char *username, char *password) {
    if (manager->count >= MAX_ENTRIES) {
        printf("Warning: Maximum entries reached! Delete an entry before adding a new one!\n");
        return;
    }
    // Check for a paranoid password policy
    if (strlen(password) < 8) {
        printf("Security Alert: Password too weak! Must be at least 8 characters long.\n");
        return;
    }
    // Storing site and username
    strcpy(manager->entries[manager->count].site, site);
    strcpy(manager->entries[manager->count].username, username);
    // Storing the hashed password
    unsigned int hashed_value = hash(password);
    sprintf(manager->entries[manager->count].password, "%u", hashed_value);
    manager->count++;
    printf("New entry added for %s. Remember, sharing is risky!\n", site);
}

// Function to display all entries
void display_entries(PasswordManager *manager) {
    if (manager->count == 0) {
        printf("No entries found. Keep your secrets safe!\n");
        return;
    }
    printf("Your Password Entries (Be cautious!)\n");
    for (int i = 0; i < manager->count; i++) {
        printf("Site: %s, Username: %s, Password Hash: %s\n", 
               manager->entries[i].site, 
               manager->entries[i].username, 
               manager->entries[i].password);
    }
}

// Function to delete an entry by site
void delete_entry(PasswordManager *manager, char *site) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->entries[i].site, site) == 0) {
            for (int j = i; j < manager->count - 1; j++) {
                manager->entries[j] = manager->entries[j + 1];  // Shift left
            }
            manager->count--;
            printf("Entry for %s deleted! Ensure this was intentional.\n", site);
            return;
        }
    }
    printf("Error: No entry found for %s! Keep trying, but be careful.\n", site);
}

// Main function to run the paranoid password manager
int main() {
    PasswordManager manager;
    init_password_manager(&manager);
    int choice;
    char site[50], username[50], password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Paranoid Password Manager:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter site: ");
                scanf("%s", site);
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_entry(&manager, site, username, password);
                break;
            case 2:
                display_entries(&manager);
                break;
            case 3:
                printf("Enter site to delete: ");
                scanf("%s", site);
                delete_entry(&manager, site);
                break;
            case 4:
                printf("Exiting... Make sure your secrets are safe!\n");
                return 0;
            default:
                printf("Invalid option! Stay cautious and try again.\n");
        }
    }
}