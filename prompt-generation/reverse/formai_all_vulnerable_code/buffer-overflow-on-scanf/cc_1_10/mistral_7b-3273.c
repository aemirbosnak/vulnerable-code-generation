//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 50
#define ENTRY_SIZE 200

typedef struct {
    char title[50];
    char content[ENTRY_SIZE];
    time_t timestamp;
} DiaryEntry;

void saveEntry(DiaryEntry *entry) {
    FILE *file = fopen("diary.bin", "ab");
    if (file == NULL) {
        printf("Error: Unable to open diary file.\n");
        return;
    }
    fwrite(entry, sizeof(DiaryEntry), 1, file);
    fclose(file);
}

DiaryEntry loadEntry(int index) {
    FILE *file = fopen("diary.bin", "rb");
    DiaryEntry entry;

    if (fseek(file, index * sizeof(DiaryEntry), SEEK_SET) != 0) {
        printf("Error: Unable to read entry.\n");
        entry.title[0] = '\0';
        return entry;
    }

    fread(&entry, sizeof(DiaryEntry), 1, file);
    fclose(file);
    return entry;
}

void printEntry(DiaryEntry entry) {
    printf("\nTitle: %s\n", entry.title);
    printf("Content:\n%s\n", entry.content);
    printf("Timestamp: %s\n", ctime(&entry.timestamp));
}

void addEntry() {
    DiaryEntry entry;
    char title[50], content[ENTRY_SIZE];

    printf("Enter title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    printf("Enter content: ");
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = '\0';

    strcpy(entry.title, title);
    strcpy(entry.content, content);
    time_t now = time(NULL);
    entry.timestamp = now;

    saveEntry(&entry);
    printf("Entry saved successfully.\n");
}

void viewEntries() {
    int i;
    DiaryEntry entry;

    printf("--------------------------------------------------\n");
    printf("| No. | Title                          | Timestamp |\n");
    printf("--------------------------------------------------\n");

    for (i = 0; i < DIARY_SIZE && fseek(fopen("diary.bin", "rb"), i * sizeof(DiaryEntry), SEEK_SET) == 0; i++) {
        fread(&entry, sizeof(DiaryEntry), 1, fopen("diary.bin", "rb"));
        printEntry(entry);
    }

    if (i == DIARY_SIZE) {
        printf("--------------------------------------------------\n");
        printf("| No more entries to display. |                |\n");
        printf("--------------------------------------------------\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}