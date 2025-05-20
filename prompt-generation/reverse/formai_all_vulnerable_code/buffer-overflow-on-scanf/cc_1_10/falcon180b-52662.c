//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

void add_entry(entry_t entries[], int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void display_entries(entry_t entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    char username[50];
    printf("Enter your name: ");
    scanf("%s", username);

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(entries[num_entries].date, 11, "%Y-%m-%d", tm);
    entries[num_entries].entry[0] = '\0';

    char input[MAX_ENTRY_LENGTH];
    while (fgets(input, MAX_ENTRY_LENGTH, stdin)!= NULL) {
        if (input[0] == '\n') {
            continue;
        }

        strcat(entries[num_entries].entry, input);
        strcat(entries[num_entries].entry, "\n");
    }

    add_entry(entries, num_entries, entries[num_entries].date, entries[num_entries].entry);
    printf("Entry saved.\n");

    return 0;
}