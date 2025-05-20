//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }

    DiaryEntry entry;
    printf("Enter title: ");
    getchar();  // consume the newline from previous input
    fgets(entry.title, MAX_TITLE_LENGTH, stdin);
    entry.title[strcspn(entry.title, "\n")] = '\0'; // remove newline character

    printf("Enter content: ");
    fgets(entry.content, MAX_CONTENT_LENGTH, stdin);
    entry.content[strcspn(entry.content, "\n")] = '\0'; // remove newline character

    entry.timestamp = time(NULL);
    diary[entryCount++] = entry;

    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("\nEntry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Date: %s", ctime(&diary[i].timestamp));
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entryNumber;
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;

    printf("Entry %d deleted successfully!\n", entryNumber);
}

void editEntry() {
    if (entryCount == 0) {
        printf("No entries to edit.\n");
        return;
    }

    int entryNumber;
    printf("Enter the entry number to edit (1 to %d): ", entryCount);
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    DiaryEntry *entry = &diary[entryNumber - 1];
    printf("Editing Entry %d: %s\n", entryNumber, entry->title);
    
    // Update title
    printf("Enter new title (leave blank to keep unchanged): ");
    getchar();  // consume the newline left by previous input
    char newTitle[MAX_TITLE_LENGTH];
    fgets(newTitle, MAX_TITLE_LENGTH, stdin);
    newTitle[strcspn(newTitle, "\n")] = '\0'; // remove newline character
    
    if (strlen(newTitle) > 0) {
        strcpy(entry->title, newTitle);
    }

    // Update content
    printf("Enter new content (leave blank to keep unchanged): ");
    char newContent[MAX_CONTENT_LENGTH];
    fgets(newContent, MAX_CONTENT_LENGTH, stdin);
    newContent[strcspn(newContent, "\n")] = '\0'; // remove newline character

    if (strlen(newContent) > 0) {
        strcpy(entry->content, newContent);
    }

    printf("Entry %d updated successfully!\n", entryNumber);
}

void displayMenu() {
    printf("\n----- Digital Diary -----\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Edit Entry\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
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
                editEntry();
                break;
            case 5:
                printf("Exiting the diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}