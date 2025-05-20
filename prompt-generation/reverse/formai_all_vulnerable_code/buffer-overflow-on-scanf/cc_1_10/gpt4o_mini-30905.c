//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} PasswordManager;

void addEntry(PasswordManager *pm, const char *username, const char *password) {
    if (pm->count >= MAX_ENTRIES) {
        printf("Error: Maximum entries reached.\n");
        return;
    }
    strncpy(pm->entries[pm->count].username, username, USERNAME_LENGTH - 1);
    strncpy(pm->entries[pm->count].password, password, PASSWORD_LENGTH - 1);
    pm->count++;
    printf("Entry added successfully!\n");
}

void removeEntry(PasswordManager *pm, const char *username) {
    for (int i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].username, username) == 0) {
            for (int j = i; j < pm->count - 1; j++) {
                pm->entries[j] = pm->entries[j + 1];
            }
            pm->count--;
            printf("Entry removed successfully!\n");
            return;
        }
    }
    printf("Error: Username not found.\n");
}

void viewEntries(const PasswordManager *pm) {
    if (pm->count == 0) {
        printf("No entries to display.\n");
        return;
    }
    printf("\nStored Passwords:\n");
    for (int i = 0; i < pm->count; i++) {
        printf("Username: %s, Password: %s\n", pm->entries[i].username, pm->entries[i].password);
    }
}

void updatePassword(PasswordManager *pm, const char *username, const char *newPassword) {
    for (int i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].username, username) == 0) {
            strncpy(pm->entries[i].password, newPassword, PASSWORD_LENGTH - 1);
            printf("Password updated successfully!\n");
            return;
        }
    }
    printf("Error: Username not found.\n");
}

int main() {
    PasswordManager pm = { .count = 0 };
    int choice;
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. View Entries\n");
        printf("4. Update Password\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter Username: ");
                fgets(username, USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0'; // remove newline
                printf("Enter Password: ");
                fgets(password, PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0'; // remove newline
                addEntry(&pm, username, password);
                break;

            case 2:
                printf("Enter Username to remove: ");
                fgets(username, USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0'; // remove newline
                removeEntry(&pm, username);
                break;

            case 3:
                viewEntries(&pm);
                break;

            case 4:
                printf("Enter Username to update password: ");
                fgets(username, USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0'; // remove newline
                printf("Enter New Password: ");
                fgets(password, PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0'; // remove newline
                updatePassword(&pm, username, password);
                break;

            case 5:
                printf("Exiting the Password Manager. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}