//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";
    time_t current_time;

    diary = fopen(filename, "a+");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    time(&current_time);

    while (num_entries < MAX_ENTRIES) {
        printf("Enter a diary entry (press enter to finish):\n");
        fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);

        if (feof(stdin)) {
            break;
        }

        entries[num_entries].timestamp = current_time;
        num_entries++;
    }

    fclose(diary);

    diary = fopen(filename, "r");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    rewind(diary);

    while (fscanf(diary, "%s %ld\n", entries[num_entries].text, &(entries[num_entries].timestamp))!= EOF) {
        num_entries++;
    }

    fclose(diary);

    diary = fopen(filename, "w");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(diary, "%s %ld\n", entries[i].text, entries[i].timestamp);
    }

    fclose(diary);

    printf("Diary saved successfully.\n");

    return 0;
}