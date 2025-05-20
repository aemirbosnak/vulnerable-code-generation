//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int size, char* date, char* entry) {
    if (size >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    strcpy(diary[size].date, date);
    strcpy(diary[size].entry, entry);

    size++;

    DiaryEntry* newDiary = (DiaryEntry*) realloc(diary, sizeof(DiaryEntry) * size);

    if (newDiary == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    diary = newDiary;
}

void displayEntries(DiaryEntry* diary, int size) {
    if (size == 0) {
        printf("Diary is empty!\n");
        return;
    }

    printf("Diary Entries:\n");

    for (int i = 0; i < size; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void searchEntry(DiaryEntry* diary, int size, char* keyword) {
    if (size == 0) {
        printf("Diary is empty!\n");
        return;
    }

    printf("Search Results:\n");

    for (int i = 0; i < size; i++) {
        if (strstr(diary[i].entry, keyword)!= NULL) {
            printf("%s - %s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    DiaryEntry* diary = (DiaryEntry*) malloc(sizeof(DiaryEntry) * 1);
    int size = 0;

    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

    addEntry(diary, size, date, "First entry!");
    addEntry(diary, size, date, "Second entry!");

    displayEntries(diary, size);

    char keyword[MAX_ENTRY_SIZE];
    printf("Enter a keyword to search: ");
    scanf("%s", keyword);

    searchEntry(diary, size, keyword);

    free(diary);

    return 0;
}