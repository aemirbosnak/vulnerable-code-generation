//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 10000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diaryFile;
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;
    char filename[50];

    printf("Welcome to your digital diary.\n");

    // Open or create diary file
    printf("Enter diary file name: ");
    scanf("%s", filename);
    diaryFile = fopen(filename, "a+");

    if (diaryFile == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Load existing entries
    rewind(diaryFile);
    while (!feof(diaryFile)) {
        fscanf(diaryFile, "%s %s %s", diary[numEntries].date, diary[numEntries].time, diary[numEntries].entry);
        numEntries++;
        if (numEntries >= MAX_ENTRIES) {
            break;
        }
    }

    // Main loop
    while (true) {
        printf("\n");
        printf("Date (YYYY-MM-DD): ");
        scanf("%s", diary[numEntries].date);
        printf("Time (HH:MM:SS): ");
        scanf("%s", diary[numEntries].time);

        char input[MAX_ENTRY_LENGTH];
        printf("Enter your thoughts:\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        strcpy(diary[numEntries].entry, input);
        fprintf(diaryFile, "%s %s %s\n", diary[numEntries].date, diary[numEntries].time, diary[numEntries].entry);
        numEntries++;

        if (numEntries >= MAX_ENTRIES) {
            printf("Diary is full. Exiting program.\n");
            break;
        }
    }

    fclose(diaryFile);
    return 0;
}