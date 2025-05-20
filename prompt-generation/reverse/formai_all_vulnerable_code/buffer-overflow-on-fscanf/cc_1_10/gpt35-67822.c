//FormAI DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 50
#define MAX_ENTRIES 100

struct Login {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct LoginEntry {
    int id;
    struct Login login;
};

void saveEntries(struct LoginEntry entries[], int numEntries);
void loadEntries(struct LoginEntry entries[], int *numEntries);
void addEntry(struct LoginEntry entries[], int *numEntries);
void removeEntry(struct LoginEntry entries[], int *numEntries);
void printEntries(struct LoginEntry entries[], int numEntries);
void clearEntries(struct LoginEntry entries[], int *numEntries);

int main(void) {
    struct LoginEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    loadEntries(entries, &numEntries);

    int choice = 0;
    do {
        printf("\n");
        printf("Password Management Program\n");
        printf("------------------------------\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. View Entries\n");
        printf("4. Clear All Entries\n");
        printf("5. Exit\n");
        printf("\n");

        printf("Enter a choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addEntry(entries, &numEntries);
                break;
            case 2:
                removeEntry(entries, &numEntries);
                break;
            case 3:
                printEntries(entries, numEntries);
                break;
            case 4:
                clearEntries(entries, &numEntries);
                break;
            case 5:
                printf("Exiting program...\n");
                saveEntries(entries, numEntries);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    } while (choice != 5);

    return EXIT_SUCCESS;
}

void saveEntries(struct LoginEntry entries[], int numEntries) {
    FILE *file = fopen("entries.dat", "w");
    if (file == NULL) {
        printf("Unable to save entries to file!\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%d %s %s\n", entries[i].id, entries[i].login.username, entries[i].login.password);
    }

    fclose(file);
}

void loadEntries(struct LoginEntry entries[], int *numEntries) {
    FILE *file = fopen("entries.dat", "r");
    if (file == NULL) {
        // No saved entries
        return;
    }

    int id;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    while (fscanf(file, "%d %s %s\n", &id, username, password) == 3) {
        struct Login login = {0};
        strncpy(login.username, username, sizeof(login.username) - 1);
        strncpy(login.password, password, sizeof(login.password) - 1);

        struct LoginEntry entry = {0};
        entry.id = id;
        entry.login = login;

        entries[*numEntries] = entry;
        (*numEntries)++;
    }

    fclose(file);
}

void addEntry(struct LoginEntry entries[], int *numEntries) {
    if (*numEntries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached!\n");
        return;
    }

    printf("Enter username: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);

    printf("Enter password: ");
    char password[MAX_PASSWORD_LENGTH];
    scanf("%s", password);

    struct Login login = {0};
    strncpy(login.username, username, sizeof(login.username) - 1);
    strncpy(login.password, password, sizeof(login.password) - 1);

    struct LoginEntry entry = {0};
    entry.login = login;
    entry.id = (*numEntries) + 1;

    entries[*numEntries] = entry;
    (*numEntries)++;

    printf("Entry added successfully!\n");
}

void removeEntry(struct LoginEntry entries[], int *numEntries) {
    if (*numEntries == 0) {
        printf("No entries to remove!\n");
        return;
    }

    printf("Enter entry ID to remove: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < *numEntries; i++) {
        if (entries[i].id == id) {
            // Remove entry
            for (int j = i; j < *numEntries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*numEntries)--;
            printf("Entry removed successfully!\n");
            return;
        }
    }

    printf("Entry with ID %d not found!\n", id);
}

void clearEntries(struct LoginEntry entries[], int *numEntries) {
    *numEntries = 0;
    printf("All entries cleared successfully!\n");
}

void printEntries(struct LoginEntry entries[], int numEntries) {
    if (numEntries == 0) {
        printf("No entries to display!\n");
        return;
    }

    printf("%-5s %-20s %-20s\n", "ID", "Username", "Password");
    printf("====================\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%-5d %-20s %-20s\n", entries[i].id, entries[i].login.username, entries[i].login.password);
    }
}