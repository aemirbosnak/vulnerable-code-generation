//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void read_entries(Entry entries[], int num_entries) {
    FILE *fp;
    int i;
    char filename[50];

    sprintf(filename, "diary.txt");
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    for (i = 0; i < num_entries; i++) {
        fscanf(fp, "%s %s\n", entries[i].date, entries[i].entry);
    }

    fclose(fp);
}

void write_entry(Entry entries[], int num_entries) {
    FILE *fp;
    int i;
    char filename[50];
    time_t now;
    struct tm *tm;
    char date[20];

    sprintf(filename, "diary.txt");
    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    time(&now);
    tm = localtime(&now);
    strftime(date, 20, "%Y-%m-%d", tm);

    printf("Enter your entry:\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    strcpy(entries[num_entries].date, date);

    fprintf(fp, "%s %s\n", entries[num_entries].date, entries[num_entries].entry);

    fclose(fp);
}

void display_entries(Entry entries[], int num_entries) {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries;

    read_entries(entries, MAX_ENTRIES);
    num_entries = MAX_ENTRIES;

    while (1) {
        printf("1. Write a new entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_entries);

        switch (num_entries) {
        case 1:
            write_entry(entries, MAX_ENTRIES);
            break;
        case 2:
            display_entries(entries, MAX_ENTRIES);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}