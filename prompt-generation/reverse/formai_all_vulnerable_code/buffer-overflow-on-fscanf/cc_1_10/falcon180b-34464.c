//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[10];
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[20];
    time_t now;
    struct tm *tm_now;
    int i;

    printf("Enter the name of the diary file: ");
    scanf("%s", filename);

    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("Diary file not found.\n");
        exit(1);
    }

    while (fscanf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].text)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full.\n");
            exit(1);
        }
    }

    fclose(diary);

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Cannot open diary file.\n");
        exit(1);
    }

    time(&now);
    tm_now = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", tm_now);
    strftime(entries[num_entries].time, 10, "%H:%M:%S", tm_now);

    printf("Enter your diary entry:\n");
    fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);

    fprintf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].text);
    fclose(diary);

    printf("Diary entry saved.\n");

    return 0;
}