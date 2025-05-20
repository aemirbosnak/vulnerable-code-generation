//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

// Struct to hold entry data
typedef struct {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
} Entry;

// Function to compare timestamps (for sorting)
int compare_timestamps(const void *a, const void *b) {
    const time_t *timestamp_a = a;
    const time_t *timestamp_b = b;

    if (*timestamp_a > *timestamp_b) {
        return 1;
    } else if (*timestamp_a < *timestamp_b) {
        return -1;
    } else {
        return 0;
    }
}

// Function to write entries to a file
void write_entries_to_file(FILE *file, Entry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%ld: %s\n", entries[i].timestamp, entries[i].text);
    }
}

// Function to read entries from a file
int read_entries_from_file(FILE *file, Entry entries[], int max_entries) {
    int num_entries = 0;

    while (fscanf(file, "%ld: %[^\n]", &entries[num_entries].timestamp, entries[num_entries].text) == 2 && num_entries < max_entries) {
        num_entries++;
    }

    return num_entries;
}

// Main function
int main() {
    FILE *diary_file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Open diary file or create it if it doesn't exist
    diary_file = fopen("diary.txt", "a+");
    if (diary_file == NULL) {
        fprintf(stderr, "Error: could not open diary file.\n");
        return 1;
    }

    // Read existing entries from file
    num_entries = read_entries_from_file(diary_file, entries, MAX_ENTRIES);

    // Sort entries by timestamp
    qsort(entries, num_entries, sizeof(Entry), compare_timestamps);

    // Print sorted entries
    printf("Digital Diary:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", ctime(&entries[i].timestamp));
        printf("%s", entries[i].text);
    }

    // Prompt user to add a new entry
    char input_text[MAX_ENTRY_LENGTH];
    printf("\nEnter your thoughts for today: ");
    fgets(input_text, MAX_ENTRY_LENGTH, stdin);

    // Remove trailing newline character from input
    input_text[strcspn(input_text, "\n")] = '\0';

    // Add current timestamp to entry
    time_t current_timestamp = time(NULL);
    strftime(input_text + strlen(input_text), MAX_ENTRY_LENGTH - strlen(input_text), " (%a %b %d %H:%M:%S %Y)", localtime(&current_timestamp));

    // Write new entry to file
    fprintf(diary_file, "%ld: %s\n", current_timestamp, input_text);

    // Close diary file
    fclose(diary_file);

    return 0;
}