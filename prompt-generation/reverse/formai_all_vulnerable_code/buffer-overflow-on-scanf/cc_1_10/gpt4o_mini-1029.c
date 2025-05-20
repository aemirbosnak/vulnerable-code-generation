//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry *diary, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    strftime(diary[*count].date, sizeof(diary[*count].date), "%Y-%m-%d %H:%M:%S", t);
    
    printf("Enter your diary entry:\n");
    getchar(); // To consume the newline character left by previous input
    fgets(diary[*count].entry, MAX_LENGTH, stdin);
    
    // Remove newline character from the end of the entry
    diary[*count].entry[strcspn(diary[*count].entry, "\n")] = 0;
    
    (*count)++;
    printf("Entry added on %s\n", diary[*count - 1].date);
}

void viewEntries(DiaryEntry *diary, int count) {
    if (count == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Entry %d (on %s): %s\n", i + 1, diary[i].date, diary[i].entry);
    }
}

void saveDiary(DiaryEntry *diary, int count) {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Could not open diary.txt for writing.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%s\n", diary[i].date, diary[i].entry);
    }
    
    fclose(file);
    printf("Diary saved to diary.txt\n");
}

void loadDiary(DiaryEntry *diary, int *count) {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No previous diary found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%[^|]|%[^\n]\n", diary[*count].date, diary[*count].entry) != EOF) {
        (*count)++;
    }
    
    fclose(file);
}

void displayMenu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Diary\n");
    printf("4. Load Diary\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int count = 0;
    int choice;

    loadDiary(diary, &count);
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(diary, &count);
                break;
            case 2:
                viewEntries(diary, count);
                break;
            case 3:
                saveDiary(diary, count);
                break;
            case 4:
                loadDiary(diary, &count);
                break;
            case 5:
                printf("Exiting the Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}