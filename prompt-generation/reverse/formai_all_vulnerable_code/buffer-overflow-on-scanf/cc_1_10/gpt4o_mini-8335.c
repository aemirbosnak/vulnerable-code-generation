//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 100

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

void displayMenu() {
    printf("\n============================\n");
    printf("      Password Manager\n");
    printf("============================\n");
    printf("1. Add Password\n");
    printf("2. Display Passwords\n");
    printf("3. Search Password\n");
    printf("4. Remove Password\n");
    printf("5. Exit\n");
    printf("============================\n");
    printf("Select an option: ");
}

void addPassword(PasswordEntry *entries, int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Password storage full! Delete some passwords first.\n");
        return;
    }

    PasswordEntry newEntry;
    printf("Enter website: ");
    scanf("%s", newEntry.website);
    printf("Enter username: ");
    scanf("%s", newEntry.username);
    printf("Enter password: ");
    scanf("%s", newEntry.password);

    entries[*count] = newEntry;
    (*count)++;
    printf("Password for %s added successfully!\n", newEntry.website);
}

void displayPasswords(PasswordEntry *entries, int count) {
    if (count == 0) {
        printf("No passwords saved yet.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s\n", entries[i].website);
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n\n", entries[i].password);
    }
}

void searchPassword(PasswordEntry *entries, int count) {
    char website[MAX_LENGTH];
    printf("Enter website to search for: ");
    scanf("%s", website);

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            printf("Found entry!\n");
            printf("Website: %s\n", entries[i].website);
            printf("Username: %s\n", entries[i].username);
            printf("Password: %s\n", entries[i].password);
            return;
        }
    }
    printf("No entry found for %s!\n", website);
}

void removePassword(PasswordEntry *entries, int *count) {
    char website[MAX_LENGTH];
    printf("Enter website to remove: ");
    scanf("%s", website);

    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].website, website) == 0) {
            // Shift entries down to fill the gap
            for (int j = i; j < *count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*count)--;
            printf("Password for %s removed successfully!\n", website);
            return;
        }
    }
    printf("No entry found for %s!\n", website);
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
                displayPasswords(entries, count);
                break;
            case 3:
                searchPassword(entries, count);
                break;
            case 4:
                removePassword(entries, &count);
                break;
            case 5:
                printf("Exiting Password Manager. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid selection! Please try again.\n");
        }
    }

    return 0;
}