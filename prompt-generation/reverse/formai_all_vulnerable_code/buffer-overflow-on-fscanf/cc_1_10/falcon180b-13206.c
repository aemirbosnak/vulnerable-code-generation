//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";
    time_t now;
    struct tm *date;
    char *entry;

    if ((diary = fopen(filename, "rb")) == NULL) {
        printf("Diary file not found. Creating new one.\n");
        diary = fopen(filename, "wb");
        if (diary == NULL) {
            printf("Could not create diary file.\n");
            exit(1);
        }
    } else {
        fseek(diary, 0, SEEK_END);
        rewind(diary);
        while (num_entries < MAX_ENTRIES && fscanf(diary, "%s\n%s", entries[num_entries].date, entries[num_entries].entry) == 2) {
            num_entries++;
        }
        fclose(diary);
    }

    time(&now);
    date = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", date);
    entry = malloc(MAX_ENTRY_LENGTH);
    if (entry == NULL) {
        printf("Could not allocate memory for entry.\n");
        exit(1);
    }
    printf("Enter your diary entry:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    strcat(entry, "\n");
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH);
    free(entry);
    num_entries++;

    diary = fopen(filename, "ab");
    if (diary == NULL) {
        printf("Could not open diary file for writing.\n");
        exit(1);
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(diary, "%s\n%s", entries[i].date, entries[i].entry);
    }
    fclose(diary);

    printf("Entry saved.\n");

    return 0;
}