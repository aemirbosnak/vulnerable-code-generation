//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[10];
    char time[8];
    char mood[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];

    // Open the diary file
    diary = fopen("diary.txt", "r");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        return 1;
    }

    // Read in the entries
    while (fscanf(diary, "%s %s %s %s", entries[num_entries].date, entries[num_entries].time, entries[num_entries].mood, entries[num_entries].content)!= EOF) {
        num_entries++;
    }

    // Close the diary file
    fclose(diary);

    // Sort the entries by date
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (strcmp(entries[i].date, entries[j].date) > 0) {
                struct entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }

    // Print the entries
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].mood, entries[i].content);
    }

    return 0;
}