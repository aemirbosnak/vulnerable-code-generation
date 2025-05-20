//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char date[11];
    char entry[1000];
} DiaryEntry;

int main() {
    DiaryEntry *diary = NULL;
    int numOfEntries = 0;
    int i;

    FILE *fp;
    fp = fopen("diary.txt", "r");
    if (fp) {
        fseek(fp, 0L, SEEK_END);
        int size = ftell(fp);
        rewind(fp);

        if (size > 0) {
            diary = (DiaryEntry*)malloc(size);
            numOfEntries = size / sizeof(DiaryEntry);
            fread(diary, sizeof(DiaryEntry), numOfEntries, fp);
        }

        fclose(fp);
    }

    while (1) {
        printf("Welcome to your Digital Diary!\n");
        printf("1. View Entries\n");
        printf("2. Add Entry\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (numOfEntries == 0) {
                printf("No entries yet.\n");
            } else {
                printf("%d total entries:\n", numOfEntries);
                for (i = 0; i < numOfEntries; i++) {
                    printf("Date: %s\nEntry: %s\n", diary[i].date, diary[i].entry);
                }
            }
        } else if (choice == 2) {
            DiaryEntry newEntry;
            printf("Enter your entry (1000 character limit):\n");
            getchar(); // clear input buffer
            fgets(newEntry.entry, 1000, stdin);

            time_t currTime;
            currTime = time(NULL);
            strftime(newEntry.date, 11, "%m/%d/%Y", localtime(&currTime));

            diary = (DiaryEntry*)realloc(diary, (numOfEntries + 1) * sizeof(DiaryEntry));
            diary[numOfEntries++] = newEntry;

            fp = fopen("diary.txt", "w");
            fwrite(diary, sizeof(DiaryEntry), numOfEntries, fp);
            fclose(fp);

            printf("Entry added!\n");
        } else if (choice == 3) {
            printf("Thanks for using Digital Diary.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    free(diary);
    return 0;
}