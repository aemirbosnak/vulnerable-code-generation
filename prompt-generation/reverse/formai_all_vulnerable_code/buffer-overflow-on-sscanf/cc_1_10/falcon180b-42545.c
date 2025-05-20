//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char time[10];
    char entry[500];
} DiaryEntry;

FILE *diaryFile;
DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void initDiary() {
    diaryFile = fopen("diary.txt", "r+");
    if (diaryFile == NULL) {
        printf("Diary file not found.\n");
        exit(1);
    }
    rewind(diaryFile);
    fseek(diaryFile, 0, SEEK_END);
}

int readEntries() {
    char line[1000];
    while (fgets(line, sizeof(line), diaryFile)!= NULL) {
        DiaryEntry entry;
        sscanf(line, "%s %s %s", entry.date, entry.time, entry.entry);
        entries[numEntries++] = entry;
        if (numEntries >= MAX_ENTRIES) {
            break;
        }
    }
    rewind(diaryFile);
    return numEntries;
}

int writeEntry(char *date, char *time, char *entry) {
    fprintf(diaryFile, "%s %s %s\n", date, time, entry);
    return 0;
}

int main() {
    time_t now;
    time(&now);
    struct tm *tm = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", tm);

    initDiary();
    int numRead = readEntries();

    while (1) {
        printf("Enter a new entry:\n");
        scanf("%s", entries[numEntries].entry);
        entries[numEntries].date[0] = '\0';
        strncat(entries[numEntries].date, date, sizeof(entries[numEntries].date) - 1);
        strncat(entries[numEntries].date, " ", sizeof(entries[numEntries].date) - strlen(entries[numEntries].date) - 1);
        strftime(entries[numEntries].time, sizeof(entries[numEntries].time), "%H:%M:%S", tm);
        writeEntry(entries[numEntries].date, entries[numEntries].time, entries[numEntries].entry);
        numEntries++;

        if (numEntries >= MAX_ENTRIES) {
            printf("Diary is full.\n");
            break;
        }
    }

    fclose(diaryFile);
    return 0;
}