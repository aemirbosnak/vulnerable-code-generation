//FormAI DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20
#define MAX_ENTRIES 10

typedef struct {
    char systemName[MAX_PASSWORD_LEN];
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} Entry;

void addEntry(Entry *entryList, int *entryCount);
void searchEntry(Entry *entryList, int entryCount);
void deleteEntry(Entry *entryList, int *entryCount);
void printEntries(Entry *entryList, int entryCount);
void printMenu();

int main() {
    Entry entryList[MAX_ENTRIES];
    int entryCount = 0;

    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline after scanf

        switch (choice) {
            case 1:
                addEntry(entryList, &entryCount);
                break;
            case 2:
                searchEntry(entryList, entryCount);
                break;
            case 3:
                deleteEntry(entryList, &entryCount);
                break;
            case 4:
                printEntries(entryList, entryCount);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addEntry(Entry *entryList, int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Password manager full!\n");
        return;
    }

    printf("System Name: ");
    fgets(entryList[*entryCount].systemName, MAX_PASSWORD_LEN, stdin);
    entryList[*entryCount].systemName[strcspn(entryList[*entryCount].systemName, "\n")] = '\0';

    printf("Username: ");
    fgets(entryList[*entryCount].username, MAX_PASSWORD_LEN, stdin);
    entryList[*entryCount].username[strcspn(entryList[*entryCount].username, "\n")] = '\0';

    printf("Password: ");
    fgets(entryList[*entryCount].password, MAX_PASSWORD_LEN, stdin);
    entryList[*entryCount].password[strcspn(entryList[*entryCount].password, "\n")] = '\0';

    (*entryCount)++;
    printf("Entry added successfully!\n");
}

void searchEntry(Entry *entryList, int entryCount) {
    if (entryCount == 0) {
        printf("No Entries Found!\n");
        return;
    }

    char searchName[MAX_PASSWORD_LEN];
    printf("Enter the system name to search: ");
    fgets(searchName, MAX_PASSWORD_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entryList[i].systemName, searchName) == 0) {
            printf("System Name: %s\n", entryList[i].systemName);
            printf("Username: %s\n", entryList[i].username);
            printf("Password: %s\n", entryList[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No Entries Found!\n");
    }
}

void deleteEntry(Entry *entryList, int *entryCount) {
    if (*entryCount == 0) {
        printf("No Entries Found!\n");
        return;
    }

    char deleteName[MAX_PASSWORD_LEN];
    printf("Enter the system name to delete: ");
    fgets(deleteName, MAX_PASSWORD_LEN, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    int deleteIndex = -1;
    for (int i = 0; i < *entryCount; i++) {
        if (strcmp(entryList[i].systemName, deleteName) == 0) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex == -1) {
        printf("System Name not found!\n");
        return;
    }

    for (int i = deleteIndex; i < (*entryCount)-1; i++) {
        entryList[i] = entryList[i+1];
    }

    (*entryCount)--;
    printf("Entry deleted successfully!\n");
}

void printEntries(Entry *entryList, int entryCount) {
    if (entryCount == 0) {
        printf("No Entries Found!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("System Name: %s\n", entryList[i].systemName);
        printf("Username: %s\n", entryList[i].username);
        printf("Password: %s\n", entryList[i].password);
        printf("\n");
    }
}

void printMenu() {
    printf("\n");
    printf("1. Add Password Entry\n");
    printf("2. Search Password Entry\n");
    printf("3. Delete Password Entry\n");
    printf("4. List All Password Entries\n");
    printf("5. Exit\n");
}