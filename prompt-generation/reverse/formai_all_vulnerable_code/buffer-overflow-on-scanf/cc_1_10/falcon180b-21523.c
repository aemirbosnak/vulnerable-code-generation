//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* entryText) {
    time_t now = time(NULL);
    struct tm* timeInfo = localtime(&now);
    strftime(diary[numEntries].date, 11, "%m/%d/%Y", timeInfo);
    strncpy(diary[numEntries].entry, entryText, MAX_ENTRY_LENGTH-1);
    diary[numEntries].entry[MAX_ENTRY_LENGTH-1] = '\0';
    numEntries++;
}

void viewEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("\nWelcome to Digital Diary!\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry: ");
                char entryText[MAX_ENTRY_LENGTH];
                scanf("%[^\n]s", entryText);
                addEntry(entryText);
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}