//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char content[MAX_LENGTH];
} DiaryEntry;

void addEntry();
void viewEntries();
void searchEntry();
void displayEntry(DiaryEntry entry);

int main() {
    int choice;

    while (1) {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline character

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printf("Exiting the diary. Stay brave!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addEntry() {
    FILE *file;
    DiaryEntry entry;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Format date
    strftime(entry.date, sizeof(entry.date), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("Enter your diary entry: ");
    fgets(entry.content, sizeof(entry.content), stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // remove newline

    file = fopen("diary_entries.txt", "a");
    if (file == NULL) {
        perror("Error opening file!");
        return;
    }
    
    fwrite(&entry, sizeof(DiaryEntry), 1, file);
    fclose(file); 

    printf("Your entry has been saved successfully!\n");
}

void viewEntries() {
    FILE *file;
    DiaryEntry entry;
    
    file = fopen("diary_entries.txt", "rb");
    if (file == NULL) {
        perror("Error opening file!");
        return;
    }

    printf("\n=== Your Diary Entries ===\n");
    while (fread(&entry, sizeof(DiaryEntry), 1, file)) {
        displayEntry(entry);
    }
    fclose(file); 
}

void displayEntry(DiaryEntry entry) {
    printf("Date: %s\n", entry.date);
    printf("Entry: %s\n", entry.content);
    printf("--------------------------\n");
}

void searchEntry() {
    FILE *file;
    DiaryEntry entry;
    char searchTerm[MAX_LENGTH];

    printf("Enter search term: ");
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline

    file = fopen("diary_entries.txt", "rb");
    if (file == NULL) {
        perror("Error opening file!");
        return;
    }

    printf("\n=== Search Results ===\n");
    int found = 0;
    while (fread(&entry, sizeof(DiaryEntry), 1, file)) {
        if (strstr(entry.content, searchTerm) != NULL) {
            displayEntry(entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found with the term '%s'.\n", searchTerm);
    }
    fclose(file); 
}