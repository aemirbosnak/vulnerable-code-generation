//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TEXT_LENGTH 512

typedef struct {
    time_t timestamp;
    char entry[MAX_TEXT_LENGTH];
} DiaryEntry;

typedef struct {
    DiaryEntry entries[MAX_ENTRIES];
    int count;
} DigitalDiary;

void initializeDiary(DigitalDiary *diary) {
    diary->count = 0;
}

void addEntry(DigitalDiary *diary, const char *text) {
    if (diary->count < MAX_ENTRIES) {
        diary->entries[diary->count].timestamp = time(NULL);
        snprintf(diary->entries[diary->count].entry, MAX_TEXT_LENGTH, "%s", text);
        diary->count++;
        printf("Entry added successfully!\n");
    } else {
        printf("Diary is full! Cannot add more entries.\n");
    }
}

void viewEntries(const DigitalDiary *diary) {
    if (diary->count == 0) {
        printf("No entries found in your digital diary.\n");
        return;
    }

    printf("Your Digital Diary Entries:\n");
    for (int i = 0; i < diary->count; i++) {
        char buffer[30];
        struct tm *tm_info;

        tm_info = localtime(&diary->entries[i].timestamp);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("Entry %d - Date: %s\n", i + 1, buffer);
        printf("Text: %s\n\n", diary->entries[i].entry);
    }
}

void saveDiaryToFile(const DigitalDiary *diary, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fwrite(diary, sizeof(DigitalDiary), 1, file);
    fclose(file);
    printf("Diary saved to %s successfully!\n", filename);
}

void loadDiaryFromFile(DigitalDiary *diary, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("No saved diary found with the name: %s\n", filename);
        return;
    }
    fread(diary, sizeof(DigitalDiary), 1, file);
    fclose(file);
    printf("Diary loaded from %s successfully!\n", filename);
}

void deleteDiary(DigitalDiary *diary) {
    diary->count = 0;
    printf("All entries have been deleted from the diary.\n");
}

void displayMenu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Diary\n");
    printf("4. Load Diary\n");
    printf("5. Delete Diary\n");
    printf("6. Exit\n");
}

int main() {
    DigitalDiary diary;
    initializeDiary(&diary);
    char filename[100];
    int choice;
    char entryText[MAX_TEXT_LENGTH];

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter your diary entry: ");
                fgets(entryText, sizeof(entryText), stdin);
                entryText[strcspn(entryText, "\n")] = 0; // Remove newline character
                addEntry(&diary, entryText);
                break;
            case 2:
                viewEntries(&diary);
                break;
            case 3:
                printf("Enter filename to save diary: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                saveDiaryToFile(&diary, filename);
                break;
            case 4:
                printf("Enter filename to load diary: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                loadDiaryFromFile(&diary, filename);
                break;
            case 5:
                deleteDiary(&diary);
                break;
            case 6:
                printf("Exiting the Digital Diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}