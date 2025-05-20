//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 1000

// Struct to hold diary entry
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} DiaryEntry;

// Function to initialize the diary
void initDiary(DiaryEntry* diary) {
    memset(diary, 0, sizeof(DiaryEntry) * MAX_ENTRIES);
}

// Function to add an entry to the diary
void addEntry(DiaryEntry* diary, char* date, char* entry) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].date[0] == '\0' || strcmp(date, diary[i].date) > 0) {
            strcpy(diary[i].date, date);
            strcpy(diary[i].entry, entry);
            return;
        }
    }
}

// Function to print the diary
void printDiary(DiaryEntry* diary) {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].date[0]!= '\0') {
            printf("%s:\n%s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    initDiary(diary);

    char date[20];
    char entry[MAX_ENTRY_SIZE];

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter entry:\n");
        fgets(entry, MAX_ENTRY_SIZE, stdin);
        entry[strcspn(entry, "\n")] = '\0';

        addEntry(diary, date, entry);

        printf("Diary updated.\n");
    }

    return 0;
}