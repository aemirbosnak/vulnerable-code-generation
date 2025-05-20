//FormAI DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[500];
} DiaryEntry;

void addEntry(DiaryEntry* entries, int* numEntries, char* date, char* entry) {
    if (*numEntries < MAX_ENTRIES) {
        DiaryEntry newEntry;
        strcpy(newEntry.date, date);
        strcpy(newEntry.entry, entry);
        entries[*numEntries] = newEntry;
        printf("Entry added successfully!\n");
        (*numEntries)++;
    } else {
        printf("Diary is full!\n");
    }
}

void viewEntries(DiaryEntry* entries, int numEntries) {
    if (numEntries == 0) {
        printf("No entries found.\n");
    } else {
        for (int i = 0; i < numEntries; i++) {
            printf("Date: %s\nEntry: %s\n", entries[i].date, entries[i].entry);
            printf("----------------------\n");
        }
    }
}

void saveEntriesToFile(DiaryEntry* entries, int numEntries) {
    FILE* file = fopen("diary.txt", "w");
    if (file == NULL) { // error opening file
        printf("Error saving file.\n");
        return;
    }
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "Date: %s\nEntry: %s\n----------------------\n", entries[i].date, entries[i].entry);
    }
    fclose(file);
    printf("Entries saved to file successfully!\n");
}

void loadEntriesFromFile(DiaryEntry* entries, int* numEntries) {
    FILE* file = fopen("diary.txt", "r");
    if (file == NULL) { // error opening file
        printf("Error loading file.\n");
        return;
    }
    char buffer[600];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char date[20];
        char entry[500];
        sscanf(buffer, "Date: %[^ ]%*c %[^\n]", date, entry);
        addEntry(entries, numEntries, date, entry);
    }
    fclose(file);
    printf("Entries loaded from file successfully!\n");
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    printf("Welcome to your digital diary!\n");
    while (1) {
        printf("Select an option:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Save entries to file\n");
        printf("4. Load entries from file\n");
        printf("5. Quit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': {
                printf("Enter today's date (YYYY-MM-DD): ");
                char date[20];
                scanf("%s", date);
                printf("Enter your entry: ");
                char entry[500];
                scanf(" %[^\n]", entry);
                addEntry(entries, &numEntries, date, entry);
                break;
            }
            case '2': {
                viewEntries(entries, numEntries);
                break;
            }
            case '3': {
                saveEntriesToFile(entries, numEntries);
                break;
            }
            case '4': {
                loadEntriesFromFile(entries, &numEntries);
                break;
            }
            case '5': {
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    return 0;
}