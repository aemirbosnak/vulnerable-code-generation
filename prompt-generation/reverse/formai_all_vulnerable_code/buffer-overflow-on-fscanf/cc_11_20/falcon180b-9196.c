//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500
#define FILENAME "diary.txt"

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *fp;
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char date[20];
    strftime(date, 20, "%Y-%m-%d", tm);

    fp = fopen(FILENAME, "r");
    if (fp!= NULL) {
        while (fscanf(fp, "%s %s\n", date, diary[numEntries].entry)!= EOF) {
            strcpy(diary[numEntries].date, date);
            numEntries++;
        }
        fclose(fp);
    }

    while (1) {
        system("clear");
        printf("Digital Diary\n");
        printf("-----------------\n");
        printf("1. Write an entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("-----------------\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter your entry:\n");
                fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
                strcpy(diary[numEntries].date, date);
                numEntries++;
                break;
            case '2':
                if (numEntries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("-----------------\n");
                    printf("Date        Entry\n");
                    printf("-----------------\n");
                    for (int i = 0; i < numEntries; i++) {
                        printf("%s %s\n", diary[i].date, diary[i].entry);
                    }
                }
                break;
            case '3':
                printf("Enter keyword to search:\n");
                char keyword[MAX_ENTRY_LENGTH];
                fgets(keyword, MAX_ENTRY_LENGTH, stdin);
                for (int i = 0; i < numEntries; i++) {
                    if (strstr(diary[i].entry, keyword)!= NULL) {
                        printf("%s %s\n", diary[i].date, diary[i].entry);
                    }
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}