//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diaryFile;
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    time_t now = time(NULL);

    diaryFile = fopen("diary.txt", "r");
    if (diaryFile!= NULL) {
        fclose(diaryFile);
        remove("diary.txt");
    }
    diaryFile = fopen("diary.txt", "w");
    if (diaryFile == NULL) {
        printf("Error creating diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("-----------------\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter your entry (max %d characters): ", MAX_ENTRY_LENGTH);
            fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
            entries[numEntries].timestamp = now;
            numEntries++;
            break;
        case '2':
            for (int i = 0; i < numEntries; i++) {
                printf("%s\n", entries[i].entry);
            }
            break;
        case '3':
            fclose(diaryFile);
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}