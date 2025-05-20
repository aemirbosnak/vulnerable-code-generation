//FormAI DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // maximum length of a name or email
#define MAX_ENTRIES 1000 // maximum number of entries in the list

// define the structure of an entry in the mailing list
typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
} Entry;

// declare global variables
Entry mailing_list[MAX_ENTRIES]; // array to store the entries in the mailing list
int num_entries = 0; // number of entries currently in the mailing list

// function to add a new entry to the mailing list
void add_entry() {
    Entry new_entry;

    printf("Enter name: ");
    scanf("%s", new_entry.name);
    printf("Enter email: ");
    scanf("%s", new_entry.email);

    mailing_list[num_entries++] = new_entry;

    printf("Entry added successfully!\n");
}

// function to display all entries in the mailing list
void display_entries() {
    printf("Mailing List:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", mailing_list[i].name, mailing_list[i].email);
    }
}

// function to search for an entry by name
void search_entry() {
    char search_name[MAX_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    int found = 0;

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(mailing_list[i].name, search_name) == 0) {
            printf("%s\t%s\n", mailing_list[i].name, mailing_list[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found!\n");
    }
}

// function to remove an entry from the mailing list
void remove_entry() {
    char remove_email[MAX_LENGTH];

    printf("Enter email to remove: ");
    scanf("%s", remove_email);

    int found = 0;

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(mailing_list[i].email, remove_email) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                mailing_list[j] = mailing_list[j + 1];
            }
            num_entries--;
            found = 1;
            printf("Entry removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Entry not found!\n");
    }
}

// main function
int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search entry\n");
        printf("4. Remove entry\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;

            case 2:
                display_entries();
                break;

            case 3:
                search_entry();
                break;

            case 4:
                remove_entry();
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}