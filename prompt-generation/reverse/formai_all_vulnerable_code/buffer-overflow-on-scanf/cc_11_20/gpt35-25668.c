//FormAI DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>

// Define struct for mailing list entry
typedef struct {
    char name[50];
    char email[50];
} MailingListEntry;

int main() {
    // Define array to hold mailing list entries
    MailingListEntry mailingList[100];

    // Keep track of number of entries in list
    int numEntries = 0;

    // Display menu
    printf("Welcome to the Mailing List Manager!\n");
    printf("1. Add entry\n");
    printf("2. Remove entry\n");
    printf("3. Display all entries\n");
    printf("4. Quit\n");

    // Loop until user selects Quit
    int choice = 0;
    while (choice != 4) {
        // Get user choice
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            // Add entry
            case 1:
                // Ensure room in list for another entry
                if (numEntries >= 100) {
                    printf("Error: Mailing list is full. Cannot add entry.\n");
                    break;
                }

                // Prompt user for entry information
                printf("\nEnter name: ");
                scanf("%s", mailingList[numEntries].name);
                printf("Enter email: ");
                scanf("%s", mailingList[numEntries].email);

                // Increment number of entries
                numEntries++;

                // Confirm addition to user
                printf("\nEntry added!\n");

                break;

            // Remove entry
            case 2:
                // Ensure there are entries to remove
                if (numEntries == 0) {
                    printf("Error: Mailing list is empty. Cannot remove entry.\n");
                    break;
                }

                // Prompt user for entry to remove
                printf("\nEnter name of entry to remove: ");
                char removeName[50];
                scanf("%s", removeName);

                // Search for matching entry and remove if found
                int removeIndex = -1;
                for (int i = 0; i < numEntries; i++) {
                    if (strcmp(removeName, mailingList[i].name) == 0) {
                        removeIndex = i;
                        break;
                    }
                }
                if (removeIndex == -1) {
                    printf("Error: Entry not found.\n");
                } else {
                    for (int i = removeIndex; i < numEntries - 1; i++) {
                        mailingList[i] = mailingList[i+1];
                    }
                    numEntries--;
                    printf("\nEntry removed!\n");
                }

                break;

            // Display all entries
            case 3:
                // Ensure there are entries to display
                if (numEntries == 0) {
                    printf("Mailing list is empty.\n");
                    break;
                }

                // Display header
                printf("\nMailing List Entries:\n\n");

                // Loop through entries and display information
                for (int i = 0; i < numEntries; i++) {
                    printf("Entry %d:\n", i+1);
                    printf("Name: %s\n", mailingList[i].name);
                    printf("Email: %s\n\n", mailingList[i].email);
                }

                break;

            // Quit
            case 4:
                printf("\nGoodbye!\n");
                break;

            // Invalid choice
            default:
                printf("\nInvalid choice. Please select 1-4.\n");
                break;
        }
    }

    return 0;
}