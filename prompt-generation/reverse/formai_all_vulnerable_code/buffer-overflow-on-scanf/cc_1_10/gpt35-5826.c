//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining struct for mailing list entry
typedef struct {
    char name[30];
    char email[50];
    char company[50];
} MailingListEntry;

// Global variables
MailingListEntry* list;
int size = 0;

// Function to add an entry to the mailing list
void addEntry() {
    // Allocating memory for new entry
    MailingListEntry* newEntry = (MailingListEntry*)malloc(sizeof(MailingListEntry));

    // Getting details from user
    printf("Enter name: ");
    scanf("%s", newEntry->name);
    printf("Enter email: ");
    scanf("%s", newEntry->email);
    printf("Enter company: ");
    scanf("%s", newEntry->company);

    // Increasing size of list and reallocating memory
    size++;
    list = (MailingListEntry*)realloc(list, size * sizeof(MailingListEntry));

    // Adding new entry to list
    list[size - 1] = *newEntry;
    free(newEntry);

    // Printing success message
    printf("Entry added successfully!\n");
}

// Function to remove an entry from the mailing list
void removeEntry() {
    // Getting email from user
    char email[50];
    printf("Enter email: ");
    scanf("%s", email);

    // Checking if email exists in list
    int indexToRemove = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            indexToRemove = i;
            break;
        }
    }

    // Removing entry if found
    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
        list = (MailingListEntry*)realloc(list, size * sizeof(MailingListEntry));
        printf("Entry removed successfully!\n");
    }
    else {
        printf("Email not found in the list.\n");
    }
}

// Function to print all entries in the mailing list
void printList() {
    printf("Name\tEmail\t\tCompany\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%s\t%s\n", list[i].name, list[i].email, list[i].company);
    }
}

// Main function
int main() {
    int choice;

    // Looping until user chooses to exit
    while (1) {
        printf("\n1. Add entry\n2. Remove entry\n3. Print list\n4. Exit\nEnter choice: ");
        
        // Reading user choice
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEntry();
                    break;
            case 2: removeEntry();
                    break;
            case 3: printList();
                    break;
            case 4: printf("Exiting...\n");
                    exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}