//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

void createDiary() {
    FILE *diary;
    diary = fopen("diary.txt", "w");
    if (diary == NULL) {
        printf("Error: Could not create diary file.\n");
        exit(1);
    }
    fclose(diary);
}

void writeEntry(char *date, char *entry) {
    FILE *diary;
    diary = fopen("diary.txt", "a");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }
    fprintf(diary, "%s - %s\n", date, entry);
    fclose(diary);
}

void readEntries(int numEntries) {
    FILE *diary;
    char line[MAX_ENTRY_LENGTH];
    int i;
    diary = fopen("diary.txt", "r");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }
    for (i = 0; i < numEntries; i++) {
        fgets(line, MAX_ENTRY_LENGTH, diary);
        printf("%s", line);
    }
    fclose(diary);
}

void main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    int choice, numEntries;

    createDiary();

    while (1) {
        printf("Digital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter your entry: ");
                scanf("%s", entry);
                writeEntry(date, entry);
                printf("Entry saved!\n");
                break;
            case 2:
                printf("How many entries do you want to read? ");
                scanf("%d", &numEntries);
                readEntries(numEntries);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}