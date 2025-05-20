//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diary;
    DiaryEntry entry;
    int numEntries = 0;
    char filename[50];
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(filename, 50, "diary_%Y%m%d.txt", tm);

    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    rewind(diary);
    while (fscanf(diary, "%s %s %s\n", entry.date, entry.time, entry.entry)!= EOF) {
        numEntries++;
    }
    fclose(diary);

    if (numEntries == 0) {
        printf("Welcome to your new digital diary!\n\n");
    }

    while (1) {
        printf("Enter your entry:\n");
        fgets(entry.entry, MAX_ENTRY_LENGTH, stdin);
        entry.entry[strcspn(entry.entry, "\n")] = '\0'; // remove newline character
        strcpy(entry.date, asctime(tm));
        strcpy(entry.time, ctime(&now));

        diary = fopen(filename, "a");
        if (diary == NULL) {
            printf("Error: could not open diary file.\n");
            exit(1);
        }

        fprintf(diary, "%s %s %s\n", entry.date, entry.time, entry.entry);
        fclose(diary);

        printf("\nYour entry has been saved.\n\n");
    }

    return 0;
}