//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 1000

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

int main() {
    // Initialize variables
    FILE* file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char input[MAX_ENTRY_LENGTH];
    char filename[MAX_ENTRY_LENGTH];

    // Prompt user for file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Read entries from file
    while (fgets(input, MAX_ENTRY_LENGTH, file)!= NULL) {
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Check if input is empty
        if (strlen(input) == 0) {
            continue;
        }

        // Add entry to array
        strcpy(entries[num_entries].entry, input);
        entries[num_entries].timestamp = time(NULL);
        num_entries++;
    }

    // Sort entries by timestamp
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (entries[i].timestamp > entries[j].timestamp) {
                Entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }

    // Print entries to console
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", entries[i].entry);
    }

    // Close file
    fclose(file);

    return 0;
}