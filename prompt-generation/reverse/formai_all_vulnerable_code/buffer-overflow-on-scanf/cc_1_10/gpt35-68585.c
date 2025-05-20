//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <string.h>

/*
 * Knight struct to hold diary entries
 */
struct Knight {
    char date[20];
    char entry[500];
    char signature[50];
};

/*
 * Function to add new diary entry
 */
void add_entry(struct Knight diary[], int *entry_count) {
    // Get date of entry
    char date[20];
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", date);

    // Get entry text
    char entry[500];
    printf("Enter entry (up to 500 characters): ");
    scanf(" %[^\n]", entry);

    // Get knight's signature
    char signature[50];
    printf("Enter your signature: ");
    scanf("%s", signature);

    // Add entry to diary
    strcpy(diary[*entry_count].date, date);
    strcpy(diary[*entry_count].entry, entry);
    strcpy(diary[*entry_count].signature, signature);
    *entry_count = *entry_count + 1;

    // Confirmation message
    printf("Entry added!\n");
}

/*
 * Function to display all diary entries
 */
void display_entries(struct Knight diary[], int entry_count) {
    if (entry_count == 0) {
        printf("You have no entries in your diary yet.\n");
    } else {
        printf("Diary entries:\n");
        for (int i = 0; i < entry_count; i++) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].entry);
            printf("Signature: %s\n\n", diary[i].signature);
        }
    }
}

/*
 * Main function to run Digital Diary program
 */
int main() {
    printf("Welcome to your Digital Diary!\n");

    // Create empty diary
    struct Knight diary[100];
    int entry_count = 0;

    // Prompt user for action
    int choice = 0;
    while (choice != 3) {
        printf("\n1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry(diary, &entry_count);
                break;
            case 2:
                display_entries(diary, entry_count);
                break;
            case 3:
                printf("Farewell brave knight, until we meet again!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}