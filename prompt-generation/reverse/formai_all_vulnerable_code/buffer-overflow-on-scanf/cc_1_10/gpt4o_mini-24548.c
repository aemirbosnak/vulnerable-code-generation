//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 30

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void displayMenu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add a Password\n");
    printf("2. View Passwords\n");
    printf("3. Search Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n");
    printf("========================\n");
    printf("Choose an option: ");
}

void addPassword(PasswordEntry *entries, int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Error: Maximum password limit reached!\n");
        return;
    }

    PasswordEntry entry;
    printf("\nEnter the Website: ");
    scanf("%s", entry.website);
    printf("Enter the Username: ");
    scanf("%s", entry.username);
    printf("Enter the Password: ");
    scanf("%s", entry.password);

    entries[*count] = entry;
    (*count)++;
    printf("Password added successfully!\n");
}

void viewPasswords(PasswordEntry *entries, int count) {
    if (count == 0) {
        printf("No passwords stored yet!\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s | Username: %s | Password: %s\n",
            entries[i].website,
            entries[i].username,
            entries[i].password);
    }
}

void searchPassword(PasswordEntry *entries, int count) {
    char website[MAX_LENGTH];
    printf("\nEnter the Website to search: ");
    scanf("%s", website);

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            printf("Found Password for Website: %s\n", website);
            printf("Username: %s | Password: %s\n", entries[i].username, entries[i].password);
            return;
        }
    }
    printf("No password found for Website: %s\n", website);
}

void deletePassword(PasswordEntry *entries, int *count) {
    char website[MAX_LENGTH];
    printf("\nEnter the Website to delete: ");
    scanf("%s", website);

    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            printf("Password for Website: %s deleted successfully!\n", website);
            return;
        }
    }
    printf("No password found for Website: %s\n", website);
}

int main() {
    PasswordEntry entries[MAX_PASSWORDS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(entries, &count);
                break;
            case 2:
                viewPasswords(entries, count);
                break;
            case 3:
                searchPassword(entries, count);
                break;
            case 4:
                deletePassword(entries, &count);
                break;
            case 5:
                printf("Exiting Password Manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}