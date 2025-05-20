//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complete
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
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[100];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open diary file
    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read existing entries from file
    rewind(diary);
    while (fscanf(diary, "%ld %s", &entries[num_entries].timestamp, entries[num_entries].text)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Error: too many entries.\n");
            fclose(diary);
            return 1;
        }
    }

    // Get current timestamp
    time_t now = time(NULL);

    // Prompt user for new entry
    printf("Enter new entry (or press enter to quit): ");
    fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
    if (feof(stdin)) {
        printf("Exiting...\n");
        fclose(diary);
        return 0;
    }

    // Add new entry to file
    fprintf(diary, "%ld %s", now, entries[num_entries].text);
    num_entries++;
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: too many entries.\n");
        fclose(diary);
        return 1;
    }

    // Close diary file
    fclose(diary);

    return 0;
}