//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file;
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char input[MAX_ENTRY_LENGTH];
    time_t current_time;

    // Open the diary file for reading and writing
    diary_file = fopen("diary.txt", "a+");
    if (diary_file == NULL) {
        printf("Error opening diary file.\n");
        return 1;
    }

    // Read in the existing entries
    rewind(diary_file);
    while (fscanf(diary_file, "%s %ld\n", input, &current_time)!= EOF) {
        strncpy(diary[num_entries].text, input, MAX_ENTRY_LENGTH);
        diary[num_entries].timestamp = current_time;
        num_entries++;
    }

    // Main loop
    while (1) {
        printf("Enter a diary entry (up to %d characters):\n", MAX_ENTRY_LENGTH - 1);
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strlen(input) == 0) {
            printf("Blank entry.\n");
            continue;
        }

        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full.\n");
            continue;
        }

        diary[num_entries].timestamp = time(NULL);
        strncpy(diary[num_entries].text, input, MAX_ENTRY_LENGTH);
        num_entries++;

        // Write the new entry to the diary file
        fprintf(diary_file, "%s %ld\n", input, diary[num_entries - 1].timestamp);
    }

    fclose(diary_file);
    return 0;
}