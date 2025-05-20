//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    char entry_text[MAX_ENTRY_LENGTH];
    struct entry diary_entries[MAX_ENTRIES];
    int num_entries = 0;

    // Open diary file for reading and writing
    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error opening diary file.\n");
        exit(1);
    }

    // Read existing entries from diary file
    rewind(diary);
    while (fgets(entry_text, MAX_ENTRY_LENGTH, diary)!= NULL) {
        struct entry entry;
        sscanf(entry_text, "%s %ld", entry.text, &entry.timestamp);
        strcpy(diary_entries[num_entries].text, entry.text);
        diary_entries[num_entries].timestamp = entry.timestamp;
        num_entries++;
    }

    // Main loop for writing new entries and displaying existing entries
    while (1) {
        printf("Enter a new diary entry:\n");
        fgets(entry_text, MAX_ENTRY_LENGTH, stdin);
        strtok(entry_text, "\n");
        strcpy(diary_entries[num_entries].text, entry_text);
        diary_entries[num_entries].timestamp = time(NULL);
        num_entries++;

        // Save diary entries to file
        fseek(diary, 0, SEEK_SET);
        for (int i = 0; i < num_entries; i++) {
            fprintf(diary, "%s %ld\n", diary_entries[i].text, diary_entries[i].timestamp);
        }

        // Display existing diary entries
        printf("Diary entries:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s - %s\n", ctime(&diary_entries[i].timestamp), diary_entries[i].text);
        }
    }

    return 0;
}