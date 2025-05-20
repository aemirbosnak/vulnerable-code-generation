//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256

// Function to get the current timestamp
char* get_current_time() {
    time_t now = time(NULL);
    return ctime(&now);
}

// Function to log an event
void log_event(const char* event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }
    fprintf(file, "[%s] %s\n", get_current_time(), event);
    fclose(file);
    printf("Event logged: %s\n", event);
}

// Function to display the log contents
void display_log() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("\n--- Event Log ---\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

// Function to clear the log file
void clear_log() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }
    fclose(file);
    printf("Log cleared.\n");
}

// Menu for user interaction
void display_menu() {
    printf("\n--- Event Logger Menu ---\n");
    printf("1. Log an event\n");
    printf("2. Display log\n");
    printf("3. Clear log\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice;
    char event[BUFFER_SIZE];

    // Display welcome message
    printf("Welcome to the Event Logger!\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the event to log: ");
                fgets(event, sizeof(event), stdin);
                event[strcspn(event, "\n")] = 0; // Remove the newline character
                log_event(event);
                break;
            case 2:
                display_log();
                break;
            case 3:
                clear_log();
                break;
            case 4:
                printf("Exiting the Event Logger. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}