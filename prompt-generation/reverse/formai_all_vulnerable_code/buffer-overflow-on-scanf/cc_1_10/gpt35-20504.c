//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATE_LEN 11 // mm/dd/yyyy
#define MAX_ENTRY_LEN 100

struct DiaryEntry {
    char date[MAX_DATE_LEN];
    char entry[MAX_ENTRY_LEN];
};

int main() {
    struct DiaryEntry *entries = NULL;
    int num_entries = 0;
    char user_input;

    printf("Welcome to your Digital Diary!\n");

    // Loop until user chooses to quit
    while (1) {
        printf("\nEnter 'a' to add an entry, 'v' to view all entries, or 'q' to quit: ");
        scanf(" %c", &user_input);

        if (user_input == 'a') {
            // Add new entry
            getchar(); // Remove trailing newline character
            printf("\nEnter the date (mm/dd/yyyy): ");
            fgets(entries[num_entries].date, MAX_DATE_LEN, stdin);

            printf("\nEnter your entry (max %d characters): ", MAX_ENTRY_LEN);
            fgets(entries[num_entries].entry, MAX_ENTRY_LEN, stdin);

            num_entries++;
            entries = realloc(entries, (num_entries + 1) * sizeof(struct DiaryEntry));
        } else if (user_input == 'v') {
            // View all entries
            printf("\nYour Diary Entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("\nDate: %s", entries[i].date);
                printf("\nEntry: %s\n", entries[i].entry);
            }
        } else if (user_input == 'q') {
            // Quit
            printf("\nGoodbye!\n");
            return 0;
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }
}