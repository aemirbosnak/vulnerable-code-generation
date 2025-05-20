//Falcon-180B DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "event_log.txt"

// Function to log events
void log_event(char *event) {
    FILE *log_file;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    log_file = fopen(LOG_FILE, "a");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    fprintf(log_file, "%04d-%02d-%02d %02d:%02d:%02d - %s\n",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec, event);

    fclose(log_file);
}

// Main function
int main() {
    int choice;

    // Loop until user chooses to exit
    while (1) {
        printf("\nEvent Logger Menu:\n");
        printf("1. Log an event\n");
        printf("2. View log file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Get event from user and log it
            printf("Enter the event to log: ");
            char event[100];
            scanf("%s", event);
            log_event(event);
            printf("Event logged successfully.\n");
            break;

        case 2:
            // View log file
            system("cat " LOG_FILE);
            break;

        case 3:
            // Exit program
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}