//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000 // maximum number of diary entries
#define MAX_ENTRY_LENGTH 1000 // maximum length of each diary entry

// struct to store diary entries
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// function to write a diary entry
void writeEntry(FILE* diary, DiaryEntry* entry) {
    fprintf(diary, "Date: %s\n", entry->date);
    fprintf(diary, "Entry:\n%s\n", entry->entry);
    fprintf(diary, "\n");
}

// function to read a diary entry
void readEntry(FILE* diary, DiaryEntry* entry) {
    fscanf(diary, "Date: %s\n", entry->date);
    fgets(entry->entry, MAX_ENTRY_LENGTH, diary);
}

// function to sort diary entries by date
int compareEntries(const void* a, const void* b) {
    const DiaryEntry* entryA = (const DiaryEntry*)a;
    const DiaryEntry* entryB = (const DiaryEntry*)b;
    return strcmp(entryA->date, entryB->date);
}

// main function
int main() {
    FILE* diary;
    DiaryEntry diaryEntries[MAX_ENTRIES];
    int numEntries = 0;

    // open the diary file
    diary = fopen("diary.txt", "r+");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        return 1;
    }

    // read in the existing diary entries
    while (fgets(diaryEntries[numEntries].date, 20, diary)!= NULL) {
        readEntry(diary, &diaryEntries[numEntries]);
        numEntries++;
    }

    // sort the diary entries by date
    qsort(diaryEntries, numEntries, sizeof(DiaryEntry), compareEntries);

    // add a new diary entry
    time_t now = time(NULL);
    strftime(diaryEntries[numEntries].date, 20, "%Y-%m-%d", localtime(&now));
    printf("Enter your diary entry:\n");
    fgets(diaryEntries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);

    // write the new diary entry
    fseek(diary, 0, SEEK_END);
    writeEntry(diary, &diaryEntries[numEntries]);
    numEntries++;

    // rewrite the sorted diary entries
    fseek(diary, 0, SEEK_SET);
    for (int i = 0; i < numEntries; i++) {
        writeEntry(diary, &diaryEntries[i]);
    }

    // close the diary file
    fclose(diary);

    return 0;
}