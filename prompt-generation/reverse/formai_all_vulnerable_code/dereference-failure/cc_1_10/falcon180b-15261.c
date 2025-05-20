//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct entry {
    char date[20];
    char time[20];
    char entryText[1000];
} Entry;

Entry* createEntry(char* entryText) {
    time_t now = time(NULL);
    struct tm* timeInfo = localtime(&now);
    char date[20];
    char time[20];
    strftime(date, 20, "%Y-%m-%d", timeInfo);
    strftime(time, 20, "%H:%M:%S", timeInfo);
    Entry* entry = (Entry*) malloc(sizeof(Entry));
    strcpy(entry->date, date);
    strcpy(entry->time, time);
    strcpy(entry->entryText, entryText);
    return entry;
}

void printEntry(Entry* entry) {
    printf("%s %s: %s\n", entry->date, entry->time, entry->entryText);
}

int main() {
    FILE* diaryFile = fopen("diary.txt", "a+");
    if(diaryFile == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }
    char buffer[1000];
    while(fgets(buffer, 1000, diaryFile)!= NULL) {
        Entry* entry = createEntry(buffer);
        printEntry(entry);
        free(entry);
    }
    fclose(diaryFile);
    diaryFile = fopen("diary.txt", "a");
    if(diaryFile == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }
    printf("Welcome to your digital diary!\n");
    while(1) {
        printf("Enter your thoughts:\n");
        fgets(buffer, 1000, stdin);
        Entry* entry = createEntry(buffer);
        printEntry(entry);
        fprintf(diaryFile, "%s %s: %s\n", entry->date, entry->time, entry->entryText);
        fflush(diaryFile);
        free(entry);
    }
    fclose(diaryFile);
    return 0;
}