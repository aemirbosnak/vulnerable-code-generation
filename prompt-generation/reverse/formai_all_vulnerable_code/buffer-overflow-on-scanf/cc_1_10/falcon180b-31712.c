//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        exit(1);
    }

    strcpy(diary[numEntries].date, date);
    strcpy(diary[numEntries].entry, entry);

    numEntries++;
}

void displayEntries() {
    printf("Digital Diary\n");
    printf("================\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", input);

        char* date = strtok(input, "-");
        if (date == NULL) {
            printf("Invalid date format.\n");
            continue;
        }

        int year = atoi(date);
        if (year < 1900 || year > 2100) {
            printf("Invalid year.\n");
            continue;
        }

        date = strtok(NULL, "-");
        if (date == NULL) {
            printf("Invalid date format.\n");
            continue;
        }

        int month = atoi(date);
        if (month < 1 || month > 12) {
            printf("Invalid month.\n");
            continue;
        }

        date = strtok(NULL, "-");
        if (date == NULL) {
            printf("Invalid date format.\n");
            continue;
        }

        int day = atoi(date);
        if (day < 1 || day > 31) {
            printf("Invalid day.\n");
            continue;
        }

        char* entry = (char*) malloc(MAX_ENTRY_LENGTH);
        printf("Enter your entry: ");
        scanf("%s", entry);

        addEntry(input, entry);
        printf("Entry added.\n");
    }

    return 0;
}