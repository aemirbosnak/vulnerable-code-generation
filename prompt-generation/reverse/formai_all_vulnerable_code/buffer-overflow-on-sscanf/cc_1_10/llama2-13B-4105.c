//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define struct for diary entry
struct diary_entry {
    char date[20];
    char entry[100];
};

// Define global variables
int num_entries = 0;
struct diary_entry entries[10];

// Function to read and write diary entries
void read_diary() {
    FILE *fp;
    char line[100];

    // Open diary file in read mode
    fp = fopen("diary.txt", "r");

    // Read each line of the diary file
    while (fgets(line, 100, fp)) {
        // Extract date and entry from line
        sscanf(line, "%s %s", entries[num_entries].date, entries[num_entries].entry);

        // Increment number of entries
        num_entries++;
    }

    // Close diary file
    fclose(fp);
}

// Function to write diary entries
void write_diary() {
    FILE *fp;
    char line[100];

    // Open diary file in write mode
    fp = fopen("diary.txt", "w");

    // Write each diary entry to the file
    for (int i = 0; i < num_entries; i++) {
        sprintf(line, "%s %s", entries[i].date, entries[i].entry);
        fputs(line, fp);
        fputc('\n', fp);
    }

    // Close diary file
    fclose(fp);
}

// Main function
int main() {
    // Read diary entries
    read_diary();

    // Display diary entries
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }

    // Write new diary entry
    char date[20];
    char entry[100];
    printf("Enter date (mm/dd/yyyy): ");
    fgets(date, 20, stdin);
    printf("Enter entry: ");
    fgets(entry, 100, stdin);

    // Add new diary entry to array
    struct diary_entry new_entry = {date, entry};
    num_entries++;
    if (num_entries == sizeof(entries) / sizeof(entries[0])) {
        printf("Diary is full, cannot add more entries\n");
    } else {
        memmove(&entries[num_entries], &entries[num_entries - 1],
            sizeof(entries[0]) * (num_entries - 1));
        entries[0] = new_entry;
    }

    // Write diary entries to file
    write_diary();

    return 0;
}