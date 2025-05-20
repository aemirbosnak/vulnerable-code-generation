//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

/* Define a struct to hold mailing list entries */
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} MailingListEntry;

/* Define a function to print a menu and get the user's choice */
int getMenuChoice() {
    int choice;
    printf("\nMailing List Manager\n");
    printf("---------------------\n");
    printf("1. Add new entry\n");
    printf("2. Remove entry\n");
    printf("3. Display mailing list\n");
    printf("4. Quit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

/* Define a function to add a new entry to the mailing list */
void addEntry(MailingListEntry *list, int *numEntries) {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    /* Get user input for the new entry */
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);

    /* Add the new entry to the list */
    strncpy(list[*numEntries].name, name, MAX_NAME_LEN);
    strncpy(list[*numEntries].email, email, MAX_EMAIL_LEN);

    /* Increment the number of entries */
    (*numEntries)++;
    printf("Entry added successfully!\n");
}

/* Define a function to remove an entry from the mailing list */
void removeEntry(MailingListEntry *list, int *numEntries) {
    int i, entryToRemove;
    char name[MAX_NAME_LEN];

    printf("Enter name of entry to remove: ");
    scanf("%s", name);

    /* Find the index of the entry to remove */
    for (i = 0; i < *numEntries; i++) {
        if (strcmp(list[i].name, name) == 0) {
            entryToRemove = i;
            break;
        }
    }

    /* Shift the remaining entries to fill the gap */
    for (i = entryToRemove; i < *numEntries - 1; i++) {
        memcpy(&list[i], &list[i+1], sizeof(MailingListEntry));
    }

    /* Decrement the number of entries */
    (*numEntries)--;
    printf("Entry removed successfully!\n");
}

/* Define a function to display the mailing list */
void displayList(MailingListEntry *list, int numEntries) {
    int i;
    printf("\nMailing List:\n");
    printf("---------------------\n");
    for (i = 0; i < numEntries; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }
}

int main() {
    int numEntries = 0;
    int choice;
    MailingListEntry lst[1000];

    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                addEntry(lst, &numEntries);
                break;
            case 2:
                removeEntry(lst, &numEntries);
                break;
            case 3:
                displayList(lst, numEntries);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}