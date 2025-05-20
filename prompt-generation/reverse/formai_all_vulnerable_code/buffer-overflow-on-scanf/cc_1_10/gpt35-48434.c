//FormAI DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int MAX_ENTRIES = 10;

typedef struct diaryEntry {
    char* title;
    char* content;
    time_t timestamp;
} DiaryEntry;

void printEntry(DiaryEntry entry) {
    char timeStr[26];
    strftime(timeStr, 26, "%Y-%m-%d %H:%M:%S", localtime(&(entry.timestamp)));
    printf("\n%s\n%s\n%s\n", entry.title, timeStr, entry.content);
}

void printEntries(DiaryEntry* entries, int numOfEntries) {
    for (int i = 0; i < numOfEntries; i++) {
        printf("\n********** Entry #%d **********\n", i + 1);
        printEntry(entries[i]);
    }
}

void addEntry(DiaryEntry* entries, int* numOfEntries, char* title, char* content) {
    time_t timestamp = time(NULL);
    DiaryEntry newEntry = { .title = title, .content = content, .timestamp = timestamp };
    if (*numOfEntries >= MAX_ENTRIES) {
        *numOfEntries = 0;
    }
    entries[*numOfEntries] = newEntry;
    *numOfEntries = *numOfEntries + 1;
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numOfEntries = 0;
    char choice;
    char* title = (char*)malloc(100 * sizeof(char));
    char* content = (char*)malloc(500 * sizeof(char));
    do {
        printf("\nWhat do you want to do? (A - Add entry, P - Print entries, Q - Quit): ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                printf("\nTitle: ");
                scanf(" %[^\n]s", title);
                printf("\nContent: ");
                scanf(" %[^\n]s", content);
                addEntry(entries, &numOfEntries, title, content);
                break;
            case 'P':
                printEntries(entries, numOfEntries);
                break;
            case 'Q':
                printf("\nThank you for using our digital diary!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    } while (choice != 'Q');
    free(title);
    free(content);
    return 0;
}