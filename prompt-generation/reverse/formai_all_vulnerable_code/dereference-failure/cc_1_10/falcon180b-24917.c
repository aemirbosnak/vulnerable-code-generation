//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 2048

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s:\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];

    time_t now = time(NULL);
    strftime(date, 11, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Current date: %s\n", date);
        printf("Enter your diary entry (max 2048 characters):\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);

        char* cleaned_entry = malloc(strlen(entry) + 1);
        int j = 0;
        for (int i = 0; i < strlen(entry); i++) {
            if (isalnum(entry[i])) {
                cleaned_entry[j++] = tolower(entry[i]);
            }
        }
        cleaned_entry[j] = '\0';

        add_entry(date, cleaned_entry);
        free(cleaned_entry);

        printf("Entry added.\n");
    }

    return 0;
}