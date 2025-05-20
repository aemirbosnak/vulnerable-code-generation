//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_SIZE 1024

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strncpy(entries[num_entries].date, date, 20);
    strncpy(entries[num_entries].entry, entry, ENTRY_SIZE);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void save_entries(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s: %s\n", entries[i].date, entries[i].entry);
    }

    fclose(file);
}

void load_entries(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading file.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char date[20];
        char* entry = strchr(line, ':');
        if (entry!= NULL) {
            *entry = '\0';
            entry++;
            strncpy(date, line, 20);
            add_entry(date, entry);
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    char* entries_filename = "entries.txt";
    load_entries(entries_filename);

    char date[20];
    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        char entry[ENTRY_SIZE];
        printf("Enter entry:\n");
        fgets(entry, sizeof(entry), stdin);

        add_entry(date, entry);
        save_entries(entries_filename);

        printf("Entry saved.\n");
    }

    return 0;
}