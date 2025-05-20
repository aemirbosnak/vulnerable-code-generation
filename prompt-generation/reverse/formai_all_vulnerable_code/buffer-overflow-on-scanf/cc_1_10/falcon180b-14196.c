//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    int numEntries = 0;
    Entry entries[MAX_ENTRIES];
    FILE *diaryFile;
    char filename[30];

    printf("Welcome to the Digital Diary!\n");

    if ((diaryFile = fopen("diary.txt", "r")) == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        sprintf(filename, "diary_%d.txt", time(NULL));
        if ((diaryFile = fopen(filename, "w")) == NULL) {
            printf("Error creating diary file.\n");
            exit(1);
        }
    } else {
        fclose(diaryFile);
        sprintf(filename, "diary_%d.txt", time(NULL));
        if ((diaryFile = fopen(filename, "a")) == NULL) {
            printf("Error creating diary file.\n");
            exit(1);
        }
    }

    while (1) {
        printf("\n");
        printf("Date (YYYY-MM-DD): ");
        scanf("%s", entries[numEntries].date);

        printf("Entry:\n");
        fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
        entries[numEntries].entry[strcspn(entries[numEntries].entry, "\n")] = '\0';

        fprintf(diaryFile, "%s\n%s\n", entries[numEntries].date, entries[numEntries].entry);
        fclose(diaryFile);

        numEntries++;

        if (numEntries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached. Exiting program.\n");
            break;
        }

        printf("\nDo you want to add another entry? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    printf("\nThank you for using the Digital Diary!\n");

    return 0;
}