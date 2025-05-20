//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_PASSWORD_LENGTH 20
#define MAX_NAME_LENGTH 50
#define MAX_TOTAL_PASSWORDS 10

// Define structs
typedef struct {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry passwords[MAX_TOTAL_PASSWORDS];
    int totalPasswords;
} PasswordList;

// Declare functions
void printMenu();
void addPassword(PasswordList *list);
void listPasswords(PasswordList *list);
void searchPasswords(PasswordList *list);
void deletePassword(PasswordList *list);
void updatePassword(PasswordList *list);

int main() {

    // Initialize variables
    PasswordList list;
    list.totalPasswords = 0;

    // Display menu
    int choice = -1;
    while (choice != 0) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(&list);
                break;
            case 2:
                listPasswords(&list);
                break;
            case 3:
                searchPasswords(&list);
                break;
            case 4:
                deletePassword(&list);
                break;
            case 5:
                updatePassword(&list);
                break;
            case 0:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}

void printMenu() {
    printf("\n*******************\n");
    printf("*   PASSWORD APP   *\n");
    printf("*******************\n\n");
    printf("1. Add Password\n");
    printf("2. List Passwords\n");
    printf("3. Search Passwords\n");
    printf("4. Delete Password\n");
    printf("5. Update Password\n");
    printf("0. Exit\n");
    printf("\nEnter your choice: ");
}

void addPassword(PasswordList *list) {
    printf("\nAdding a new password...\n");

    if (list->totalPasswords == MAX_TOTAL_PASSWORDS) {
        printf("\nMaximum number of passwords reached. Please delete an existing one first.\n");
        return;
    }

    // Get user input
    PasswordEntry entry;
    printf("\nEnter name for this password: ");
    fflush(stdin);
    fgets(entry.name, MAX_NAME_LENGTH, stdin);
    entry.name[strcspn(entry.name, "\n")] = 0;
    printf("Enter password for %s: ", entry.name);
    scanf("%s", &entry.password);

    // Add to list
    list->passwords[list->totalPasswords++] = entry;

    printf("\nPassword added successfully!\n\n");
}

void listPasswords(PasswordList *list) {
    printf("\nListing all passwords...\n");

    if (list->totalPasswords == 0) {
        printf("\nNo passwords available. Please add one first.\n");
        return;
    }

    for (int i = 0; i < list->totalPasswords; i++) {
        printf("\n%d. %s: %s\n", i+1, list->passwords[i].name, list->passwords[i].password);
    }

    printf("\n");
}

void searchPasswords(PasswordList *list) {
    printf("\nSearching for a password...\n");

    if (list->totalPasswords == 0) {
        printf("\nNo passwords available. Please add one first.\n");
        return;
    }

    // Get user input
    char searchTerm[MAX_NAME_LENGTH];
    printf("\nEnter search term: ");
    fflush(stdin);
    fgets(searchTerm, MAX_NAME_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;

    // Search list
    int count = 0;
    for (int i = 0; i < list->totalPasswords; i++) {
        if (strstr(list->passwords[i].name, searchTerm) != NULL) {
            printf("\n%d. %s: %s\n", i+1, list->passwords[i].name, list->passwords[i].password);
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo passwords found for \"%s\".\n", searchTerm);
    }

    printf("\n");
}

void deletePassword(PasswordList *list) {
    printf("\nDeleting a password...\n");

    if (list->totalPasswords == 0) {
        printf("\nNo passwords available. Please add one first.\n");
        return;
    }

    // Get user input
    int numToDelete;
    printf("\nEnter number of password to delete: ");
    scanf("%d", &numToDelete);
    numToDelete--;

    if (numToDelete < 0 || numToDelete >= list->totalPasswords) {
        printf("\nInvalid selection. Please try again.\n\n");
        return;
    }

    // Shift elements left
    for (int i = numToDelete; i < list->totalPasswords-1; i++) {
        list->passwords[i] = list->passwords[i+1];
    }

    // Decrement totalPasswords
    list->totalPasswords--;

    printf("\nPassword deleted successfully!\n\n");
}

void updatePassword(PasswordList *list) {
    printf("\nUpdating a password...\n");

    if (list->totalPasswords == 0) {
        printf("\nNo passwords available. Please add one first.\n");
        return;
    }

    // Get user input
    int numToUpdate;
    printf("\nEnter number of password to update: ");
    scanf("%d", &numToUpdate);
    numToUpdate--;

    if (numToUpdate < 0 || numToUpdate >= list->totalPasswords) {
        printf("\nInvalid selection. Please try again.\n\n");
        return;
    }

    // Get new password
    PasswordEntry entry;
    printf("\nEnter new password for %s: ", list->passwords[numToUpdate].name);
    scanf("%s", &entry.password);
    strcpy(list->passwords[numToUpdate].password, entry.password);

    printf("\nPassword updated successfully!\n\n");
}