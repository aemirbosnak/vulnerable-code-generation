//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

// Struct to hold each diary entry
typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function to compare two entries by timestamp
int compareDiaryEntries(const void* a, const void* b) {
    const DiaryEntry* entryA = (const DiaryEntry*)a;
    const DiaryEntry* entryB = (const DiaryEntry*)b;

    return difftime(entryA->timestamp, entryB->timestamp);
}

// Function to print all entries in the diary
void printDiary(DiaryEntry* diary, int numEntries) {
    qsort(diary, numEntries, sizeof(DiaryEntry), compareDiaryEntries);

    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].entry);
    }
}

// Function to add a new entry to the diary
void addEntry(DiaryEntry* diary, int* numEntries) {
    if (*numEntries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    printf("Enter your diary entry: ");
    fgets(diary[*numEntries].entry, MAX_ENTRY_LENGTH, stdin);
    diary[*numEntries].timestamp = time(NULL);

    (*numEntries)++;
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;

    srand(time(NULL));

    // Initialize with some random entries
    for (int i = 0; i < rand() % 10 + 1; i++) {
        addEntry(diary, &numEntries);
    }

    while (1) {
        printf("\nDiary Menu:\n");
        printf("1. Add new entry\n");
        printf("2. Print diary\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry(diary, &numEntries);
            break;

        case 2:
            printDiary(diary, numEntries);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}