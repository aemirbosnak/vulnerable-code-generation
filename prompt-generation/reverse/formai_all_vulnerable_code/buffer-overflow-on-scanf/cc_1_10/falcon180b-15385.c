//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 50

struct entry {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
};

int main() {
    FILE *logfile;
    char filename[MAX_ENTRY_LENGTH];
    struct entry log[MAX_ENTRIES];
    int num_entries = 0;
    int i;
    time_t now;
    char input[MAX_ENTRY_LENGTH];

    // Prompt user for log file name
    printf("Enter log file name: ");
    scanf("%s", filename);

    // Open log file for reading and writing
    logfile = fopen(filename, "a+");
    if (logfile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    // Read existing log entries from file
    rewind(logfile);
    while (fscanf(logfile, "%s %ld\n", log[num_entries].text, &log[num_entries].timestamp)!= EOF) {
        num_entries++;
    }

    // Main program loop
    while (1) {
        printf("\n");
        printf("Fitness Tracker\n");
        printf("--------------------\n");

        // Display existing log entries
        printf("Previous entries:\n");
        for (i = 0; i < num_entries; i++) {
            printf("%s %s\n", ctime(&log[i].timestamp), log[i].text);
        }

        // Prompt user for new entry
        printf("\nEnter new entry: ");
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        // Add new entry to log
        strncpy(log[num_entries].text, input, MAX_ENTRY_LENGTH);
        time(&now);
        log[num_entries].timestamp = now;
        num_entries++;

        // Write log to file
        fseek(logfile, 0, SEEK_END);
        for (i = 0; i < num_entries; i++) {
            fprintf(logfile, "%s %ld\n", log[i].text, log[i].timestamp);
        }
        fclose(logfile);

        // Exit program if user chooses
        printf("\nPress ENTER to continue or any other key to exit.\n");
        if (getchar()!= '\n') {
            break;
        }
    }

    return 0;
}