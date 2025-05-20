//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char entry[500];
} Entry;

void read_entries(Entry *entries) {
    FILE *fp = fopen("entries.txt", "r");
    if (fp == NULL) {
        printf("No entries found.\n");
        exit(1);
    }

    int num_entries = 0;
    while (fscanf(fp, "%s %s", entries[num_entries].date, entries[num_entries].entry)!= EOF) {
        num_entries++;
    }

    fclose(fp);
}

void write_entry(Entry *entries, char *date, char *entry) {
    FILE *fp = fopen("entries.txt", "a");
    if (fp == NULL) {
        printf("Error writing to file.\n");
        exit(1);
    }

    fprintf(fp, "%s %s\n", date, entry);

    fclose(fp);
}

int main() {
    Entry entries[MAX_ENTRIES];

    read_entries(entries);

    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

    char entry[500] = "";
    printf("Enter your diary entry for %s:\n", date);
    fgets(entry, sizeof(entry), stdin);
    entry[strcspn(entry, "\n")] = '\0';

    write_entry(entries, date, entry);

    return 0;
}