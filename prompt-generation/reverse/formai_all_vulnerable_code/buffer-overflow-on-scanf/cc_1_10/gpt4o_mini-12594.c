//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: thoughtful
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

void addEntry();
void viewEntries();
void searchEntry(const char *keyword);
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Diary Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3: {
                char keyword[MAX_TITLE_LENGTH];
                printf("Enter a keyword to search: ");
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = 0; // Remove the newline character
                searchEntry(keyword);
                break;
            }
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addEntry() {
    DiaryEntry entry;
    printf("Enter the title of your diary entry: ");
    fgets(entry.title, sizeof(entry.title), stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // Remove the newline character

    printf("Write your diary entry:\n");
    fgets(entry.content, sizeof(entry.content), stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // Remove the newline character

    entry.timestamp = time(NULL); // Get the current time

    FILE *file = fopen("diary_entries.dat", "ab");
    if (file == NULL) {
        perror("Failed to open diary file");
        return;
    }

    fwrite(&entry, sizeof(DiaryEntry), 1, file);
    fclose(file);
    printf("Diary entry saved successfully!\n");
}

void viewEntries() {
    DiaryEntry entry;
    FILE *file = fopen("diary_entries.dat", "rb");
    if (file == NULL) {
        perror("Failed to open diary file");
        return;
    }

    printf("\n--- Your Diary Entries ---\n");
    while (fread(&entry, sizeof(DiaryEntry), 1, file) == 1) {
        char date[30];
        strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", localtime(&entry.timestamp));
        printf("Title: %s\n", entry.title);
        printf("Date: %s\n", date);
        printf("Content: %s\n", entry.content);
        printf("-------------------------\n");
    }
    fclose(file);
}

void searchEntry(const char *keyword) {
    DiaryEntry entry;
    FILE *file = fopen("diary_entries.dat", "rb");
    if (file == NULL) {
        perror("Failed to open diary file");
        return;
    }

    printf("\n--- Search Results for '%s' ---\n", keyword);
    int found = 0;
    while (fread(&entry, sizeof(DiaryEntry), 1, file) == 1) {
        if (strstr(entry.title, keyword) || strstr(entry.content, keyword)) {
            char date[30];
            strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", localtime(&entry.timestamp));
            printf("Title: %s\n", entry.title);
            printf("Date: %s\n", date);
            printf("Content: %s\n", entry.content);
            printf("-------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entries found matching '%s'.\n", keyword);
    }
    fclose(file);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}