//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

int main() {
    FILE *diary;
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[20];
    time_t now;
    struct tm *tm_now;
    char date_str[11];
    char time_str[9];
    int i;

    time(&now);
    tm_now = localtime(&now);
    strftime(date_str, 11, "%Y-%m-%d", tm_now);
    strftime(time_str, 9, "%H:%M:%S", tm_now);

    sprintf(filename, "diary_%s.txt", date_str);
    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error opening diary file.\n");
        return 1;
    }

    rewind(diary);
    while (fscanf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry)!= EOF) {
        num_entries++;
    }

    if (num_entries == MAX_ENTRIES) {
        printf("Diary is full.\n");
        return 1;
    }

    printf("Enter your diary entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    strcpy(entries[num_entries].date, date_str);
    strcpy(entries[num_entries].time, time_str);

    fprintf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry);
    fclose(diary);

    printf("Entry saved.\n");
    return 0;
}