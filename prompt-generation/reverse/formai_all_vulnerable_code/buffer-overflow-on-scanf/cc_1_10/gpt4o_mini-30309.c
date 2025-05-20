//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 512

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry();
void viewEntries();
void searchEntry();
void deleteEntry();
void displayMenu();
void saveDiary();
void loadDiary();

int main() {
    loadDiary();
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: deleteEntry(); break;
            case 5: saveDiary(); break;
            case 6: printf("Thank you for using the Digital Diary. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\n=== DIGITAL DIARY ===\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Save Diary\n");
    printf("6. Exit\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries!\n");
        return;
    }
    
    DiaryEntry newEntry;

    printf("Enter title: ");
    fgets(newEntry.title, MAX_TITLE_LENGTH, stdin);
    newEntry.title[strcspn(newEntry.title, "\n")] = '\0'; // Remove newline

    printf("Enter content: ");
    fgets(newEntry.content, MAX_CONTENT_LENGTH, stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = '\0'; // Remove newline

    newEntry.timestamp = time(NULL);
    entries[entryCount++] = newEntry;

    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("\nEntry #%d\n", i + 1);
        printf("Title: %s\n", entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("Timestamp: %s", ctime(&entries[i].timestamp));
    }
}

void searchEntry() {
    char searchTerm[MAX_TITLE_LENGTH];
    printf("Enter title to search: ");
    fgets(searchTerm, MAX_TITLE_LENGTH, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(entries[i].title, searchTerm) != NULL) {
            printf("\nFound Entry #%d\n", i + 1);
            printf("Title: %s\n", entries[i].title);
            printf("Content: %s\n", entries[i].content);
            printf("Timestamp: %s", ctime(&entries[i].timestamp));
            found = 1;
        }
    }
    if (!found) {
        printf("No entries matched your search.\n");
    }
}

void deleteEntry() {
    viewEntries();
    int index;
    printf("Enter the entry number to delete: ");
    scanf("%d", &index);
    getchar(); // To consume the newline character left by scanf

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        entries[i] = entries[i + 1]; // Shift entries left
    }
    entryCount--;
    printf("Entry deleted successfully!\n");
}

void saveDiary() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Could not open file for saving!\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Title: %s\n", entries[i].title);
        fprintf(file, "Content: %s\n", entries[i].content);
        fprintf(file, "Timestamp: %s", ctime(&entries[i].timestamp));
        fprintf(file, "-------------------------\n");
    }

    fclose(file);
    printf("Diary saved successfully!\n");
}

void loadDiary() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No previous diary found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "Title: %[^\n]\n", entries[entryCount].title) != EOF) {
        fscanf(file, "Content: %[^\n]\n", entries[entryCount].content);
        char timestamp[100];
        fscanf(file, "Timestamp: %[^\n]\n", timestamp);
        entries[entryCount].timestamp = time(NULL);
        entryCount++;
    }

    fclose(file);
    printf("Diary loaded successfully with %d entries!\n", entryCount);
}