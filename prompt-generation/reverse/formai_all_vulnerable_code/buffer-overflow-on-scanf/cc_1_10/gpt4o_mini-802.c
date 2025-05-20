//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

// Function to get the current timestamp
const char* current_timestamp() {
    static char buffer[20];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}

// Function to log an event
void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "[%s] %s\n", current_timestamp(), event);
    fclose(file);
}

// Function to display menu
void display_menu() {
    printf("\nEvent Logger Menu:\n");
    printf("1. Log Info Event\n");
    printf("2. Log Warning Event\n");
    printf("3. Log Error Event\n");
    printf("4. View Log File\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

// Function to view log file
void view_log_file() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    char line[MAX_EVENT_LENGTH];
    printf("\n--- Event Log ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("------------------\n");
}

// Main Function
int main() {
    int option;
    char event[MAX_EVENT_LENGTH];

    // Create log file if it doesn't exist
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to create log file");
        return EXIT_FAILURE;
    }
    fclose(file);

    while (1) {
        display_menu();
        scanf("%d", &option);
        getchar(); // clear newline character from the buffer

        switch(option) {
            case 1:
                printf("Enter Info Event: ");
                fgets(event, MAX_EVENT_LENGTH, stdin);
                event[strcspn(event, "\n")] = 0; // remove newline character
                log_event(event);
                break;

            case 2:
                printf("Enter Warning Event: ");
                fgets(event, MAX_EVENT_LENGTH, stdin);
                event[strcspn(event, "\n")] = 0; // remove newline character
                log_event(event);
                break;

            case 3:
                printf("Enter Error Event: ");
                fgets(event, MAX_EVENT_LENGTH, stdin);
                event[strcspn(event, "\n")] = 0; // remove newline character
                log_event(event);
                break;

            case 4:
                view_log_file();
                break;

            case 5:
                printf("Exiting the Event Logger. Goodbye!\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}