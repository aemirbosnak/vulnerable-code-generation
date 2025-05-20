//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 100

// Structure to hold each entry
typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

// Function to print the entries
void print_entries(DiaryEntry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("\n%s\n%s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    // Welcome message
    printf("Welcome to your digital diary!\n\n");

    // Read in any existing entries from file
    FILE* file = fopen("entries.txt", "r");
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    if (file) {
        char entry[MAX_ENTRY_LENGTH];
        while (fgets(entry, MAX_ENTRY_LENGTH, file)) {
            char* date = strtok(entry, "\n");
            char* text = strtok(NULL, "\n");
            DiaryEntry entry = {date, text};
            entries[num_entries] = entry;
            num_entries++;
        }
        fclose(file);
    }

    // Print existing entries, if any
    if (num_entries > 0) {
        printf("Here are your existing entries:\n");
        print_entries(entries, num_entries);
    }

    // Main loop for adding new entries
    while (1) {
        // Get the current date
        time_t rawtime;
        struct tm* timeinfo;
        char date[20];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(date, 20, "%Y-%m-%d %H:%M:%S", timeinfo);

        // Get the new entry from the user
        char entry[MAX_ENTRY_LENGTH];
        printf("\nEnter your new entry (maximum %d characters):\n", MAX_ENTRY_LENGTH - 1);
        scanf(" %[^\n]s", entry);

        // Add the new entry to the array
        DiaryEntry new_entry = {date, entry};
        entries[num_entries] = new_entry;
        num_entries++;

        // Check if the user wants to keep adding entries
        char response[5];
        printf("\nDo you want to add another entry? (Yes/No)\n");
        scanf(" %[^\n]s", response);
        if (strcmp(response, "No") == 0 || strcmp(response, "no") == 0) {
            break;
        }
        else if (strcmp(response, "Yes") == 0 || strcmp(response, "yes") == 0) {
            continue;
        }
        else {
            printf("\nSorry, I didn't understand your response. Please try again.\n");
            continue;
        }
    }

    // Save the entries to file
    file = fopen("entries.txt", "w");
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s\n%s\n", entries[i].date, entries[i].entry);
    }
    fclose(file);

    // Print the final entries
    printf("\nHere are all your entries:\n");
    print_entries(entries, num_entries);

    return 0;
}