//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000 // 1MB
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
} file_entry_t;

void init_file_entry(file_entry_t* entry) {
    memset(entry->filename, 0, MAX_FILE_NAME_LENGTH);
    entry->timestamp = 0;
}

void print_file_entry(file_entry_t* entry) {
    printf("Filename: %s\n", entry->filename);
    printf("Timestamp: %ld\n", entry->timestamp);
}

int compare_file_entries(const void* a, const void* b) {
    const file_entry_t* entry_a = a;
    const file_entry_t* entry_b = b;

    int result = strcmp(entry_a->filename, entry_b->filename);
    if (result!= 0) {
        return result;
    }

    return (int)difftime(entry_a->timestamp, entry_b->timestamp);
}

int read_file_entries_from_disk(file_entry_t* entries, int max_entries) {
    FILE* fp = fopen("file_entries.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    int num_entries = 0;
    while (fscanf(fp, "%s %ld\n", entries[num_entries].filename, &entries[num_entries].timestamp) == 2) {
        num_entries++;
        if (num_entries >= max_entries) {
            break;
        }
    }

    fclose(fp);
    return num_entries;
}

void write_file_entries_to_disk(const file_entry_t* entries, int num_entries) {
    FILE* fp = fopen("file_entries.txt", "w");
    if (fp == NULL) {
        printf("Error: Failed to open file_entries.txt for writing.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s %ld\n", entries[i].filename, entries[i].timestamp);
    }

    fclose(fp);
}

int main() {
    file_entry_t entries[MAX_FILE_SIZE];
    int num_entries = read_file_entries_from_disk(entries, MAX_FILE_SIZE);

    if (num_entries <= 0) {
        printf("No file entries found.\n");
        return 1;
    }

    qsort(entries, num_entries, sizeof(file_entry_t), compare_file_entries);

    printf("File entries:\n");
    for (int i = 0; i < num_entries; i++) {
        print_file_entry(&entries[i]);
    }

    return 0;
}