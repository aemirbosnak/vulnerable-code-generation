//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char *filename = "diary.txt";
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char date[20];
    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d", localtime(&now));

    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your entry for %s:\n", date);
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    add_entry(date, entry);

    fprintf(file, "%s: %s\n", date, entry);
    fclose(file);

    printf("Entry saved.\n");

    return 0;
}