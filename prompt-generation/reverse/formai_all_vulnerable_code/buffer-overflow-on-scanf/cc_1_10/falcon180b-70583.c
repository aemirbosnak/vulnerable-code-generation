//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

int main() {
    FILE *diary;
    char filename[30];
    int numEntries = 0;
    DiaryEntry entries[MAX_ENTRIES];

    printf("Welcome to your digital diary!\n");
    printf("Please enter a filename (without extension): ");
    scanf("%s", filename);

    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    while (numEntries < MAX_ENTRIES) {
        printf("\nEnter a new diary entry:\n");
        printf("Date (YYYY-MM-DD): ");
        scanf("%s", entries[numEntries].date);
        entries[numEntries].date[19] = '\0';

        printf("Entry:\n");
        fgets(entries[numEntries].entry, MAX_LENGTH, stdin);
        entries[numEntries].entry[strcspn(entries[numEntries].entry, "\n")] = '\0';

        fprintf(diary, "%s - %s\n", entries[numEntries].date, entries[numEntries].entry);
        numEntries++;
    }

    fclose(diary);
    printf("\nYour diary has been saved.\n");

    return 0;
}