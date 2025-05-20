//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_PW_LENGTH 20

//Struct for password entry
typedef struct {
    char domain[MAX_PW_LENGTH];
    char username[MAX_PW_LENGTH];
    char password[MAX_PW_LENGTH];
} PasswordEntry;

int menu();
void addEntry(PasswordEntry entries[], int *count);
void listEntries(PasswordEntry entries[], int count);
void searchEntries(PasswordEntry entries[], int count);
void updateEntry(PasswordEntry entries[], int count);
void deleteEntry(PasswordEntry entries[], int *count);

int main() {
    PasswordEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        choice = menu();

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                listEntries(entries, count);
                break;
            case 3:
                searchEntries(entries, count);
                break;
            case 4:
                updateEntry(entries, count);
                break;
            case 5:
                deleteEntry(entries, &count);
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

int menu() {
    int choice;

    printf("\nPassword Manager\n");
    printf("================\n");
    printf("1. Add New Entry\n");
    printf("2. List Entries\n");
    printf("3. Search Entries\n");
    printf("4. Update Entry\n");
    printf("5. Delete Entry\n");
    printf("6. Exit\n");

    printf("\nEnter choice: ");
    scanf("%d", &choice);
    getchar();

    return choice;
}

void addEntry(PasswordEntry entries[], int *count) {
    if (*count == MAX_ENTRIES) {
        printf("\nError: Maximum entries reached.\n");
        return;
    }

    PasswordEntry newEntry;

    printf("\nEnter domain: ");
    fgets(newEntry.domain, MAX_PW_LENGTH, stdin);
    newEntry.domain[strcspn(newEntry.domain, "\n")] = '\0';

    printf("Enter username: ");
    fgets(newEntry.username, MAX_PW_LENGTH, stdin);
    newEntry.username[strcspn(newEntry.username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(newEntry.password, MAX_PW_LENGTH, stdin);
    newEntry.password[strcspn(newEntry.password, "\n")] = '\0';

    entries[*count] = newEntry;
    *count += 1;

    printf("\nEntry added successfully.\n");
}

void listEntries(PasswordEntry entries[], int count) {
    if (count == 0) {
        printf("\nNo entries to display.\n");
        return;
    }

    printf("\n%-20s %-20s %-20s\n", "Domain", "Username", "Password");
    printf("==============================================\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-20s\n", entries[i].domain, entries[i].username, entries[i].password);
    }
}

void searchEntries(PasswordEntry entries[], int count) {
    if (count == 0) {
        printf("\nNo entries to search.\n");
        return;
    }

    char searchDomain[MAX_PW_LENGTH];
    int found = 0;

    printf("\nEnter domain to search for: ");
    fgets(searchDomain, MAX_PW_LENGTH, stdin);
    searchDomain[strcspn(searchDomain, "\n")] = '\0';

    printf("\n%-20s %-20s %-20s\n", "Domain", "Username", "Password");
    printf("==============================================\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].domain, searchDomain) == 0) {
            printf("%-20s %-20s %-20s\n", entries[i].domain, entries[i].username, entries[i].password);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo entries found for domain '%s'.\n", searchDomain);
    }
}

void updateEntry(PasswordEntry entries[], int count) {
    if (count == 0) {
        printf("\nNo entries to update.\n");
        return;
    }

    char searchDomain[MAX_PW_LENGTH];
    int found = 0;

    printf("\nEnter domain to update: ");
    fgets(searchDomain, MAX_PW_LENGTH, stdin);
    searchDomain[strcspn(searchDomain, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].domain, searchDomain) == 0) {
            printf("\nOld information:\n");
            printf("Domain: %s\n", entries[i].domain);
            printf("Username: %s\n", entries[i].username);
            printf("Password: %s\n", entries[i].password);

            printf("\nEnter new domain (press Enter to keep old value): ");
            fgets(entries[i].domain, MAX_PW_LENGTH, stdin);
            entries[i].domain[strcspn(entries[i].domain, "\n")] = '\0';

            printf("Enter new username (press Enter to keep old value): ");
            fgets(entries[i].username, MAX_PW_LENGTH, stdin);
            entries[i].username[strcspn(entries[i].username, "\n")] = '\0';

            printf("Enter new password (press Enter to keep old value): ");
            fgets(entries[i].password, MAX_PW_LENGTH, stdin);
            entries[i].password[strcspn(entries[i].password, "\n")] = '\0';

            printf("\nEntry updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo entries found for domain '%s'.\n", searchDomain);
    }
}

void deleteEntry(PasswordEntry entries[], int *count) {
    if (*count == 0) {
        printf("\nNo entries to delete.\n");
        return;
    }

    char searchDomain[MAX_PW_LENGTH];
    int found = 0;

    printf("\nEnter domain to delete: ");
    fgets(searchDomain, MAX_PW_LENGTH, stdin);
    searchDomain[strcspn(searchDomain, "\n")] = '\0';

    for (int i = 0; i < *count; i++) {
        if (strcmp(entries[i].domain, searchDomain) == 0) {
            printf("\nAre you sure you want to delete the following entry?\n");
            printf("Domain: %s\n", entries[i].domain);
            printf("Username: %s\n", entries[i].username);
            printf("Password: %s\n", entries[i].password);

            char confirm;
            printf("\nEnter Y to confirm deletion: ");
            scanf("%c", &confirm);

            if (confirm == 'Y' || confirm == 'y') {
                for (int j = i; j < *count - 1; j++) {
                    entries[j] = entries[j+1];
                }
                *count -= 1;
                printf("\nEntry deleted successfully.\n");
            } else {
                printf("\nDeletion cancelled.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo entries found for domain '%s'.\n", searchDomain);
    }
}