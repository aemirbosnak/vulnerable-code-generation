//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "system_events.log"
#define BUFFER_SIZE 256

// Struct to represent a log event
typedef struct {
    time_t timestamp;
    char message[BUFFER_SIZE];
} LogEvent;

// Function to get the current timestamp as a string
char *get_current_time_string() {
    time_t now = time(NULL);
    return ctime(&now);
}

// Function to log an event
void log_event(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Could not open log file for writing!\n");
        return;
    }

    LogEvent event;
    event.timestamp = time(NULL);
    strncpy(event.message, message, BUFFER_SIZE - 1);
    event.message[BUFFER_SIZE - 1] = '\0'; // Ensure null termination

    fprintf(log_file, "[%s] %s\n", get_current_time_string(), event.message);
    fclose(log_file);
}

// Function to display the log
void display_logs() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        printf("No logs found! Let's make some!\n");
        return;
    }

    char line[BUFFER_SIZE];
    printf("----- System Event Log -----\n");
    while (fgets(line, sizeof(line), log_file)) {
        printf("%s", line);
    }
    printf("---------------------------\n");
    fclose(log_file);
}

// Function to demonstrate logging various events
void simulate_event_logging() {
    log_event("System startup successful!");
    log_event("User logged in: Alice");
    log_event("File 'config.txt' opened for reading.");
    log_event("User logged out: Alice");
    log_event("System shutdown initiated.");
}

// Function to show menu to the user
void show_menu() {
    printf("Welcome to the Happy Event Logger!\n");
    printf("1. Log Example Events\n");
    printf("2. Display Logs\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Please choose an option (1-3): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Logging example events... 🎉\n");
                simulate_event_logging();
                printf("Events logged successfully! Go check the log!\n");
                break;
            case 2:
                printf("Displaying current logs... 📜\n");
                display_logs();
                break;
            case 3:
                printf("Exiting the Happy Event Logger... 🌈\n");
                printf("Goodbye! Have a great day! ☀️\n");
                exit(0);
            default:
                printf("Oops! That's not a valid option. Try again! 🎈\n");
                break;
        }
    }

    return 0;
}