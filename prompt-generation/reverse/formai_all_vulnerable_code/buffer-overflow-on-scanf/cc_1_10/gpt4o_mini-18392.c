//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOGFILE "event_log.txt"
#define MAX_EVENT_SIZE 256

// Function to get the current timestamp
char* get_timestamp() {
    time_t now;
    time(&now);
    char* time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // Remove newline character
    return time_str;
}

// Function to log an event to the log file
void log_event(const char* event) {
    FILE *file = fopen(LOGFILE, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    fprintf(file, "[%s] %s\n", get_timestamp(), event);
    fclose(file);
}

// Function to display the log file contents
void display_log() {
    FILE *file = fopen(LOGFILE, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    
    char buffer[MAX_EVENT_SIZE];
    printf("Event Log:\n");
    while (fgets(buffer, MAX_EVENT_SIZE, file)) {
        printf("%s", buffer);
    }
    
    fclose(file);
}

// Function to clear the log file
void clear_log() {
    FILE *file = fopen(LOGFILE, "w");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }
    fclose(file);  // Truncate file by closing it immediately
}

// Function to simulate an event occurring in the system
void simulate_event(const char* description) {
    printf("Simulating event: %s\n", description);
    log_event(description);
}

// Main function
int main() {
    int choice;
    char event_description[MAX_EVENT_SIZE];

    // Create or clear the logfile at start
    clear_log();

    // Event logging system loop
    do {
        printf("\nEvent Logger System\n");
        printf("1. Log a new event\n");
        printf("2. Display event log\n");
        printf("3. Clear event log\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event_description, MAX_EVENT_SIZE, stdin);
                event_description[strcspn(event_description, "\n")] = 0; // Remove newline
                simulate_event(event_description);
                break;

            case 2:
                display_log();
                break;

            case 3:
                clear_log();
                printf("Event log cleared.\n");
                break;

            case 4:
                printf("Exiting event logger.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}