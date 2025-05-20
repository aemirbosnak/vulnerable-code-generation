//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define TITLE_LENGTH 50
#define CONTENT_LENGTH 500

typedef struct {
    char title[TITLE_LENGTH];
    char content[CONTENT_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter the title of your entry: ");
    getchar(); // Consume the newline character
    fgets(diary[entryCount].title, TITLE_LENGTH, stdin);
    diary[entryCount].title[strcspn(diary[entryCount].title, "\n")] = 0; // Remove newline

    printf("Write your entry: ");
    fgets(diary[entryCount].content, CONTENT_LENGTH, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline

    diary[entryCount].timestamp = time(NULL);
    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No diary entries found.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        char buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&diary[i].timestamp);
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        printf("\nEntry %d\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Timestamp: %s\n", buffer);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    viewEntries();
    int entryNumber;
    printf("Enter the number of the entry you want to delete: ");
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }

    // Shift entries to remove the specified entry
    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entryCount--;

    printf("Entry deleted successfully!\n");
}

void searchEntry() {
    if (entryCount == 0) {
        printf("No entries to search through.\n");
        return;
    }

    char searchTerm[TITLE_LENGTH];
    printf("Enter a keyword to search in titles: ");
    getchar(); // Consume the newline character
    fgets(searchTerm, TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove newline

    printf("Search Results:\n");
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].title, searchTerm) != NULL) {
            found = 1;
            printf("Entry %d: %s\n", i + 1, diary[i].title);
        }
    }
    
    if (!found) {
        printf("No entries match your search.\n");
    }
}

void displayMenu() {
    printf("\nWelcome to your Digital Diary\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete an Entry\n");
    printf("4. Search for Entry\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                searchEntry();
                break;
            case 5:
                printf("Exiting the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}