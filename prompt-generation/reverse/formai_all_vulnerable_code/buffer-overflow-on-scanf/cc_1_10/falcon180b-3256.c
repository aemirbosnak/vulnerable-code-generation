//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void read_entries(FILE *file, Entry entries[]) {
    int count = 0;
    while (fscanf(file, "%s %s", entries[count].date, entries[count].entry)!= EOF) {
        count++;
    }
}

void write_entry(FILE *file, Entry entry) {
    fprintf(file, "%s %s\n", entry.date, entry.entry);
}

void add_entry(Entry entries[], int count, char *date, char *entry) {
    strncpy(entries[count].date, date, 20);
    strncpy(entries[count].entry, entry, MAX_ENTRY_LENGTH);
}

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int count = 0;
    char input[MAX_ENTRY_LENGTH];

    file = fopen("diary.txt", "a+");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (count < MAX_ENTRIES) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", entries[count].date);

        printf("Enter your entry:\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        strncpy(entries[count].entry, input, MAX_ENTRY_LENGTH);

        count++;
    }

    fclose(file);

    file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    read_entries(file, entries);

    fclose(file);

    printf("Your diary:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s\n", entries[i].date, entries[i].entry);
    }

    return 0;
}