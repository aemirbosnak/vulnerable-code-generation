//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char text[ENTRY_SIZE];
    time_t timestamp;
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int count;
} Diary;

void initializeDiary(Diary *diary) {
    diary->count = 0;
}

void addEntry(Diary *diary, const char *text) {
    if (diary->count < MAX_ENTRIES) {
        strncpy(diary->entries[diary->count].text, text, ENTRY_SIZE - 1);
        diary->entries[diary->count].text[ENTRY_SIZE - 1] = '\0'; // Ensure null-termination
        diary->entries[diary->count].timestamp = time(NULL);
        diary->count++;
        printf("Entry added!\n");
    } else {
        printf("Diary is full! Cannot add more entries.\n");
    }
}

void viewEntries(const Diary *diary) {
    if (diary->count == 0) {
        printf("No entries in the diary.\n");
        return;
    }
    for (int i = 0; i < diary->count; i++) {
        char buffer[30];
        struct tm *tm_info = localtime(&diary->entries[i].timestamp);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Entry %d (added on %s): %s\n", i + 1, buffer, diary->entries[i].text);
    }
}

void deleteEntry(Diary *diary, int index) {
    if (index < 0 || index >= diary->count) {
        printf("Invalid entry number.\n");
        return;
    }
    
    for (int i = index; i < diary->count - 1; i++) {
        diary->entries[i] = diary->entries[i + 1];
    }
    diary->count--;
    printf("Entry deleted!\n");
}

void displayMenu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

int main() {
    Diary myDiary;
    initializeDiary(&myDiary);
    
    int choice;
    char entryText[ENTRY_SIZE];

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter your diary entry: ");
                fgets(entryText, ENTRY_SIZE, stdin);
                entryText[strcspn(entryText, "\n")] = 0; // Remove newline
                addEntry(&myDiary, entryText);
                break;

            case 2:
                viewEntries(&myDiary);
                break;

            case 3:
                printf("Enter entry number to delete: ");
                int entryNumber;
                scanf("%d", &entryNumber);
                deleteEntry(&myDiary, entryNumber - 1); // Adjust for zero-based index
                break;

            case 4:
                printf("Exiting the diary. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}