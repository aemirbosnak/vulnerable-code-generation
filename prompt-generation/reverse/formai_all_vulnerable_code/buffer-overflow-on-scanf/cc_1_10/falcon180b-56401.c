//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void addEntry(Entry entries[], int numEntries, char* date, char* time, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[numEntries].date, date, 20);
    strncpy(entries[numEntries].time, time, 10);
    strncpy(entries[numEntries].entry, entry, MAX_ENTRY_LENGTH);

    numEntries++;
}

void displayEntries(Entry entries[], int numEntries) {
    printf("Entries:\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void saveEntries(Entry entries[], int numEntries, FILE* file) {
    fprintf(file, "Entries:\n");

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void loadEntries(Entry entries[], int numEntries, FILE* file) {
    char line[MAX_ENTRY_LENGTH];
    while (fgets(line, MAX_ENTRY_LENGTH, file)!= NULL) {
        if (numEntries >= MAX_ENTRIES) {
            printf("Error: Maximum number of entries reached.\n");
            return;
        }

        char* date = strtok(line, " ");
        char* time = strtok(NULL, " ");
        char* entry = strtok(NULL, "\n");

        strncpy(entries[numEntries].date, date, 20);
        strncpy(entries[numEntries].time, time, 10);
        strncpy(entries[numEntries].entry, entry, MAX_ENTRY_LENGTH);

        numEntries++;
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;

    char* date = (char*)malloc(20 * sizeof(char));
    char* time = (char*)malloc(10 * sizeof(char));
    char* entry = (char*)malloc(MAX_ENTRY_LENGTH * sizeof(char));

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter time (HH:MM:SS): ");
        scanf("%s", time);

        printf("Enter entry:\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0';

        addEntry(entries, numEntries, date, time, entry);

        printf("Do you want to add another entry? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    printf("Entries added:\n");
    displayEntries(entries, numEntries);

    FILE* file = fopen("diary.txt", "w");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    saveEntries(entries, numEntries, file);
    fclose(file);

    printf("Entries saved to file.\n");

    return 0;
}