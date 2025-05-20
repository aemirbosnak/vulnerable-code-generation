//Falcon-180B DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct log_entry {
    char event_type[32];
    char event_message[256];
    time_t event_time;
};

void log_event(char *event_type, char *event_message) {
    struct log_entry entry;
    strcpy(entry.event_type, event_type);
    strcpy(entry.event_message, event_message);
    time(&entry.event_time);

    FILE *log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: Could not open event log file.\n");
        return;
    }

    fprintf(log_file, "%s - %s\n", entry.event_type, entry.event_message);
    fclose(log_file);
}

void view_log() {
    FILE *log_file = fopen("event_log.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open event log file.\n");
        return;
    }

    struct log_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (fscanf(log_file, "%s - %s\n", entries[num_entries].event_type, entries[num_entries].event_message)!= EOF) {
        num_entries++;
    }

    fclose(log_file);

    printf("\nEvent Log:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].event_type, entries[i].event_message);
    }
}

int main() {
    log_event("Program Start", "Program started successfully.");

    // Example events
    log_event("Button Clicked", "User clicked the 'Save' button.");
    log_event("Error", "An error occurred while saving the file.");
    log_event("Warning", "The file size exceeds the maximum limit.");

    view_log();

    return 0;
}