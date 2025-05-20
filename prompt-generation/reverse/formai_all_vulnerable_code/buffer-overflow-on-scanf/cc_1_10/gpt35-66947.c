//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char date[20];
    char entry[1000];
} DiaryEntry;

void addEntry(DiaryEntry *diary, int *numEntries) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf("\n");
    printf("Date: %02d/%02d/%02d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("Enter your diary entry:\n");

    // Read input from user
    char buf[1000];
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = 0;

    // Add entry to diary
    DiaryEntry entry;
    strcpy(entry.date, asctime(tm));
    strcpy(entry.entry, buf);
    diary[*numEntries] = entry;
    (*numEntries)++;

    printf("Entry added to diary.\n");
}

void displayEntries(DiaryEntry *diary, int numEntries) {
    printf("\n");
    printf("Diary Entries:\n");

    for (int i = 0; i < numEntries; i++) {
        printf("\n");
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
    }
}

void saveEntries(DiaryEntry *diary, int numEntries) {
    FILE *fp;

    if ((fp = fopen("diary.txt", "w")) == NULL) {
        printf("Error opening file.\n");
    }

    for (int i = 0; i < numEntries; i++) {
        fprintf(fp, "%s%s\n", diary[i].date, diary[i].entry);
    }

    fclose(fp);

    printf("Diary entries saved to file.\n");
}

int main() {
    DiaryEntry diary[100];
    int numEntries = 0;

    while (1) {
        printf("\n");
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Save Entries to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                addEntry(diary, &numEntries);
                break;
            case 2:
                displayEntries(diary, numEntries);
                break;
            case 3:
                saveEntries(diary, numEntries);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}