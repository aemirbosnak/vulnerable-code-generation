//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LEN 2048

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LEN];
} Entry;

void generate_date_time(char* str, int len) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(str, len, "%Y-%m-%d %H:%M:%S", tm);
}

int compare_dates(const void* a, const void* b) {
    const Entry* entry_a = (const Entry*)a;
    const Entry* entry_b = (const Entry*)b;

    return strcmp(entry_a->date, entry_b->date);
}

int main() {
    FILE* diary_file = fopen("diary.txt", "a+");
    if (diary_file == NULL) {
        printf("Error opening diary file.\n");
        return 1;
    }

    int num_entries = 0;
    fseek(diary_file, 0, SEEK_END);
    num_entries = ftell(diary_file) / sizeof(Entry);

    Entry* entries = malloc(num_entries * sizeof(Entry));
    fseek(diary_file, 0, SEEK_SET);
    fread(entries, sizeof(Entry), num_entries, diary_file);
    fclose(diary_file);

    qsort(entries, num_entries, sizeof(Entry), compare_dates);

    diary_file = fopen("diary.txt", "w");
    if (diary_file == NULL) {
        printf("Error opening diary file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(diary_file, "%s\n%s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }

    fclose(diary_file);

    return 0;
}