//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIARY_LINES 100
#define LINE_LENGTH 256

typedef struct {
    char date[11];
    char description[LINE_LENGTH];
} DiaryEntry;

void saveEntry(DiaryEntry* diary, int index) {
    FILE* file = fopen("digital_diary.dat", "ab");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fwrite(diary, sizeof(DiaryEntry), 1, file);
    fclose(file);
}

void loadEntries(DiaryEntry* diary) {
    FILE* file = fopen("digital_diary.dat", "rb");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    int count = 0;
    while (fread(diary, sizeof(DiaryEntry), 1, file) == 1) {
        printf("[%s] %s\n", diary->date, diary->description);
        count++;
    }

    fclose(file);
    printf("Loaded %d entries.\n", count);
}

int main() {
    DiaryEntry diary[MAX_DIARY_LINES];
    int index = 0;

    while (1) {
        printf("\nDigital Diary\n");
        printf("------------------------\n");
        printf("1. New Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("------------------------\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", diary[index].date);
                printf("Enter description: ");
                scanf("%[^\n]", diary[index].description);
                saveEntry(diary, index);
                index++;
                break;
            case 2:
                printf("\nYour Entries:\n");
                loadEntries(diary);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}