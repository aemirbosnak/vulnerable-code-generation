//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_LIST_SIZE 100

struct MailingList {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct MailingList list[MAX_LIST_SIZE];
int numEntries = 0;

/**
 * Add a new entry to the mailing list
 */
void addEntry() {
    struct MailingList newEntry;

    printf("Enter name: ");
    scanf("%s", newEntry.name);

    printf("Enter email: ");
    scanf("%s", newEntry.email);

    if (numEntries < MAX_LIST_SIZE) {
        list[numEntries++] = newEntry;
        printf("Entry added successfully.\n");
    } else {
        printf("Mailing list is full.\n");
    }
}

/**
 * Display all entries in the mailing list
 */
void displayAllEntries() {
    if (numEntries == 0) {
        printf("Mailing list is empty.\n");
    } else {
        printf("Mailing List Entries:\n");
        printf("---------------------\n");
        for (int i = 0; i < numEntries; i++) {
            printf("%s - %s\n", list[i].name, list[i].email);
        }
    }
}

/**
 * Search the mailing list for a specific entry by email
 */
void searchByEmail() {
    char email[MAX_EMAIL_LENGTH];
    int found = 0;

    printf("Enter email to search for: ");
    scanf("%s", email);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(list[i].email, email) == 0) {
            printf("%s - %s\n", list[i].name, list[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found with that email address.\n");
    }
}

int main() {
    int option;

    // Main program loop
    while (1) {
        printf("\nMailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Search by Email\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addEntry();
                break;
            case 2:
                displayAllEntries();
                break;
            case 3:
                searchByEmail();
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}