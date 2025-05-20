//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PW_LENGTH 10
#define MAX_PWS 20

/* Struct to store the username/password pair */
typedef struct {
    char username[MAX_PW_LENGTH];
    char password[MAX_PW_LENGTH];
} Entry;

/* Function prototypes */
void displayMenu();
void addEntry(Entry entries[], int *numEntries);
void displayEntries(Entry entries[], int numEntries);
void searchEntries(Entry entries[], int numEntries);
void deleteEntry(Entry entries[], int *numEntries);

int main() {
    Entry entries[MAX_PWS]; /* Array to store password entries */
    int numEntries = 0; /* Number of current password entries */

    int choice; /* User's menu choice */

    /* Display the main menu until the user chooses to exit */
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &numEntries);
                break;
            case 2:
                displayEntries(entries, numEntries);
                break;
            case 3:
                searchEntries(entries, numEntries);
                break;
            case 4:
                deleteEntry(entries, &numEntries);
                break;
            case 0:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/* Displays the main menu */
void displayMenu() {
    printf("Password Manager\n");
    printf("1. Add new entry\n");
    printf("2. Display entries\n");
    printf("3. Search entries\n");
    printf("4. Delete entry\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

/* Adds a new entry to the password manager */
void addEntry(Entry entries[], int *numEntries) {
    /* Check if there is space for a new entry */
    if (*numEntries == MAX_PWS) {
        printf("Password manager is full. Cannot add new entry.\n");
        return;
    }

    char username[MAX_PW_LENGTH];
    char password[MAX_PW_LENGTH];

    /* Prompt the user to enter the new username and password */
    printf("Enter username (max %d characters): ", MAX_PW_LENGTH-1);
    scanf("%s", username);

    printf("Enter password (max %d characters): ", MAX_PW_LENGTH-1);
    scanf("%s", password);

    /* Copy the new username and password into the next available entry */
    strcpy(entries[*numEntries].username, username);
    strcpy(entries[*numEntries].password, password);

    /* Increment the number of password entries */
    (*numEntries)++;

    printf("Entry added successfully.\n");
}

/* Displays all the entries in the password manager */
void displayEntries(Entry entries[], int numEntries) {
    printf("Displaying %d entries.\n", numEntries);

    /* Loop through each entry and print the username and password */
    for (int i = 0; i < numEntries; i++) {
        printf("Entry %d:\n", i+1);
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n", entries[i].password);
    }
}

/* Searches for an entry in the password manager */
void searchEntries(Entry entries[], int numEntries) {
    char search[MAX_PW_LENGTH];
    int found = 0;

    /* Prompt the user to enter the username to search for */
    printf("Enter username to search for (max %d characters): ", MAX_PW_LENGTH-1);
    scanf("%s", search);

    /* Loop through each entry and check if the search term matches the username */
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].username, search) == 0) {
            /* The username was found */
            found = 1;
            printf("Entry found:\n");
            printf("Username: %s\n", entries[i].username);
            printf("Password: %s\n", entries[i].password);
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

/* Deletes an entry from the password manager */
void deleteEntry(Entry entries[], int *numEntries) {
    char search[MAX_PW_LENGTH];
    int found = 0;

    /* Prompt the user to enter the username to delete */
    printf("Enter username to delete (max %d characters): ", MAX_PW_LENGTH-1);
    scanf("%s", search);

    /* Loop through each entry and check if the search term matches the username */
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(entries[i].username, search) == 0) {
            /* The username was found */
            found = 1;

            /* Delete the entry by shifting all the entries after it back one index */
            for (int j = i; j < *numEntries-1; j++) {
                strcpy(entries[j].username, entries[j+1].username);
                strcpy(entries[j].password, entries[j+1].password);
            }

            /* Decrement the number of password entries */
            (*numEntries)--;

            printf("Entry deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}