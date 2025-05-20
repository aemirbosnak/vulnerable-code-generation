//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for a diary entry
typedef struct {
    time_t dateTime;
    char content[1024];
} DiaryEntry;

// Function declarations
void addEntry(DiaryEntry *entries, int *count);
void viewEntries(DiaryEntry *entries, int count);
void saveEntries(DiaryEntry *entries, int count);
void loadEntries(DiaryEntry *entries, int *count);
void showMenu();

int main() {
    DiaryEntry entries[100];
    int count = 0;
    int choice;
    
    loadEntries(entries, &count);

    do {
        showMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                saveEntries(entries, count);
                break;
            case 4:
                printf("Exiting the diary application...\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void showMenu() {
    printf("\n********** Digital Diary **********\n");
    printf("1. Add a Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Save Entries to File\n");
    printf("4. Exit\n");
    printf("***********************************\n");
}

void addEntry(DiaryEntry *entries, int *count) {
    if (*count >= 100) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    DiaryEntry newEntry;
    newEntry.dateTime = time(NULL);
    
    printf("Enter your diary entry (max 1024 characters): ");
    fgets(newEntry.content, sizeof(newEntry.content), stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = 0; // remove newline
    
    entries[*count] = newEntry;
    (*count)++;
    
    printf("Entry added successfully!\n");
}

void viewEntries(DiaryEntry *entries, int count) {
    if (count == 0) {
        printf("No entries to display.\n");
        return;
    }
    
    printf("\n===== Diary Entries =====\n");
    for (int i = 0; i < count; i++) {
        char buffer[26];
        struct tm* tm_info;
        
        tm_info = localtime(&entries[i].dateTime);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("Entry %d (Date: %s):\n", i + 1, buffer);
        printf("%s\n", entries[i].content);
        printf("-------------------------\n");
    }
}

void saveEntries(DiaryEntry *entries, int count) {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        printf("Could not open file to save entries.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%ld\n%s\n", entries[i].dateTime, entries[i].content);
    }
    
    fclose(file);
    printf("Diary entries saved to diary_entries.txt\n");
}

void loadEntries(DiaryEntry *entries, int *count) {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No previous diary entries found. Starting a new diary.\n");
        return;
    }
    
    while (fscanf(file, "%ld\n", &entries[*count].dateTime) != EOF) {
        fgets(entries[*count].content, sizeof(entries[*count].content), file);
        entries[*count].content[strcspn(entries[*count].content, "\n")] = 0; // remove newline
        (*count)++;
    }
    
    fclose(file);
    printf("Previous diary entries loaded: %d entries found.\n", *count);
}