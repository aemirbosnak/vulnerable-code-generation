//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 512
#define DATE_FORMAT 30

typedef struct {
    char date[DATE_FORMAT];
    char entry[MAX_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry diary[], int *entryCount) {
    if (*entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry: ");
    getchar(); // Clear newline character from input buffer
    fgets(diary[*entryCount].entry, MAX_LENGTH, stdin);
    diary[*entryCount].entry[strcspn(diary[*entryCount].entry, "\n")] = 0; // Remove newline

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(diary[*entryCount].date, DATE_FORMAT, "%Y-%m-%d %H:%M:%S", tm_info);

    (*entryCount)++;
    printf("Entry added successfully!\n");
}

void viewEntries(DiaryEntry diary[], int entryCount) {
    if (entryCount == 0) {
        printf("No diary entries available.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

void deleteEntry(DiaryEntry diary[], int *entryCount) {
    if (*entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }

    viewEntries(diary, *entryCount);
    int index;
    printf("Enter the index of the entry you want to delete (0-%d): ", *entryCount - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= *entryCount) {
        printf("Invalid index! Entry not deleted.\n");
        return;
    }

    for (int i = index; i < (*entryCount) - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries left
    }
    (*entryCount)--;

    printf("Entry deleted successfully!\n");
}

void saveToFile(DiaryEntry diary[], int entryCount) {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "Entry: %s\n\n", diary[i].entry);
    }

    fclose(file);
    printf("Diary entries saved to diary.txt successfully!\n");
}

void readFromFile(DiaryEntry diary[], int *entryCount) {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No previous diary entries found.\n");
        return;
    }

    while (!feof(file) && *entryCount < MAX_ENTRIES) {
        fgets(diary[*entryCount].date, DATE_FORMAT, file);
        fgets(diary[*entryCount].entry, MAX_LENGTH, file);
        diary[*entryCount].entry[strcspn(diary[*entryCount].entry, "\n")] = 0; // Remove newline
        (*entryCount)++;
    }

    fclose(file);
    printf("Previous diary entries loaded successfully!\n");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    readFromFile(diary, &entryCount);

    while (1) {
        printf("\n--- Digital Diary Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Entries to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &entryCount);
                break;
            case 2:
                viewEntries(diary, entryCount);
                break;
            case 3:
                deleteEntry(diary, &entryCount);
                break;
            case 4:
                saveToFile(diary, entryCount);
                break;
            case 5:
                saveToFile(diary, entryCount);
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}