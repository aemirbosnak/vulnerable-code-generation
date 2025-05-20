//FormAI DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define structure of diary entry
struct DiaryEntry {
    char date[11];
    char time[6];
    char entry[1000];
};

// function to create a new entry
void newEntry(struct DiaryEntry *entry) {
    // get current date and time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(entry->date, sizeof entry->date, "%Y-%m-%d", tm);
    strftime(entry->time, sizeof entry->time, "%H:%M", tm);
    
    // prompt for entry content
    printf("Enter your diary entry: ");
    fgets(entry->entry, sizeof entry->entry, stdin);
}

// function to display all entries
void displayEntries(struct DiaryEntry *entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. Date: %s | Time: %s\n   Entry: %s\n", i+1, entries[i].date, entries[i].time, entries[i].entry);
    }
}

int main() {
    // initialize counters and entry array
    int entryCount = 0;
    struct DiaryEntry *entries = NULL;
    
    // start menu loop
    int choice;
    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Create new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        fflush(stdin); // clear input buffer
        
        // process user choice
        switch (choice) {
            case 1:
                entryCount++;
                entries = realloc(entries, entryCount * sizeof(struct DiaryEntry)); // allocate memory
                newEntry(&entries[entryCount-1]);
                break;
            case 2:
                if (entryCount == 0) {
                    printf("No entries in diary.\n");
                } else {
                    displayEntries(entries, entryCount);
                }
                break;
            case 3:
                // free memory and exit program
                if (entries != NULL) {
                    free(entries);
                }
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}