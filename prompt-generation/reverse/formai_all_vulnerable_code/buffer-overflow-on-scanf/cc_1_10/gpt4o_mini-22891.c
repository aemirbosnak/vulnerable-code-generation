//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char *entry;
    int isDeleted;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    diary[entryCount].entry = (char *)malloc(MAX_ENTRY_LENGTH * sizeof(char));
    if (diary[entryCount].entry == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter your diary entry:\n");
    getchar(); // To consume the newline left in the buffer
    fgets(diary[entryCount].entry, MAX_ENTRY_LENGTH, stdin);
    diary[entryCount].isDeleted = 0;
    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries available.\n");
        return;
    }

    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        if (!diary[i].isDeleted) {
            printf("Entry %d: %s", i + 1, diary[i].entry);
        }
    }
    printf("---------------------------\n");
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No diary entries available to delete.\n");
        return;
    }

    viewEntries(); // Display entries to choose from
    int entryNumber;
    printf("Enter the number of the entry you want to delete:\n");
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > entryCount || diary[entryNumber - 1].isDeleted) {
        printf("Invalid entry number.\n");
        return;
    }

    diary[entryNumber - 1].isDeleted = 1;
    printf("Entry %d deleted successfully!\n", entryNumber);
}

void cleanUp() {
    for (int i = 0; i < entryCount; i++) {
        if (diary[i].entry != NULL) {
            free(diary[i].entry);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Simple Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    cleanUp();
    return 0;
}