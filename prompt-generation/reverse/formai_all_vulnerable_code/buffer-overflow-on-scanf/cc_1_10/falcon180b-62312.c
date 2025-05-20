//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diaryFile;
    diaryFile = fopen("diary.txt", "a");

    if (diaryFile == NULL) {
        printf("Unable to open diary file.\n");
        exit(1);
    }

    Entry entry;
    strcpy(entry.date, "");
    strcpy(entry.time, "");
    entry.entry[0] = '\0';

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", entry.date);

        printf("Enter time (HH:MM:SS): ");
        scanf("%s", entry.time);

        printf("\nEnter your diary entry:\n");
        fgets(entry.entry, MAX_ENTRY_LENGTH, stdin);

        fprintf(diaryFile, "%s %s\n%s\n\n", entry.date, entry.time, entry.entry);

        printf("Diary entry saved.\n\n");

        char choice;
        printf("Do you want to save another entry? (y/n): ");
        scanf(" %c", &choice);

        if (choice!= 'y' && choice!= 'Y') {
            break;
        }
    }

    fclose(diaryFile);
    return 0;
}