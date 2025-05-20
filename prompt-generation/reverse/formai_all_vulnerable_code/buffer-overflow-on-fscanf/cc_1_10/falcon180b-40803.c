//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diary;
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    time_t currentTime;

    diary = fopen("diary.txt", "r");

    if (diary == NULL) {
        printf("No existing diary found.\n");
        exit(1);
    }

    while (fscanf(diary, "%c", &choice)!= EOF) {
        if (choice == '#') {
            fscanf(diary, "%s %ld", entries[numEntries].entry, &entries[numEntries].timestamp);
            numEntries++;
        }
    }

    fclose(diary);

    diary = fopen("diary.txt", "a");

    if (diary == NULL) {
        printf("Failed to open diary for writing.\n");
        exit(1);
    }

    time(&currentTime);

    fprintf(diary, "# %s\n", ctime(&currentTime));

    while (1) {
        printf("Enter your thoughts (up to %d characters):\n", MAX_ENTRY_LENGTH - 1);
        fflush(stdout);
        fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);

        if (strlen(entries[numEntries].entry) == 0) {
            printf("Empty entry. Try again.\n");
            continue;
        }

        entries[numEntries].timestamp = currentTime;
        numEntries++;

        fprintf(diary, "# %s\n", ctime(&currentTime));
        fprintf(diary, "%s\n", entries[numEntries - 1].entry);

        if (numEntries >= MAX_ENTRIES) {
            printf("Diary is full.\n");
            break;
        }
    }

    fclose(diary);

    return 0;
}