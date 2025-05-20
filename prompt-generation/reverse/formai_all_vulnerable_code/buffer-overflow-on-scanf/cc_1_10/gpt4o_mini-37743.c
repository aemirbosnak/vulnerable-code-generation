//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256
#define TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"

// Function declarations
void log_event(const char *event);
void get_timestamp(char *buffer, size_t size);
void display_menu();
void perform_action(int choice);

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option (1-3, or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            log_event("Program terminated.");
            break;
        } else {
            perform_action(choice);
        }
    }

    return 0;
}

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    char timestamp[BUFFER_SIZE];

    if (file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    get_timestamp(timestamp, sizeof(timestamp));
    fprintf(file, "%s: %s\n", timestamp, event);
    fclose(file);
}

void get_timestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    strftime(buffer, size, TIMESTAMP_FORMAT, tm_info);
}

void display_menu() {
    printf("\n============================\n");
    printf("         Event Logger       \n");
    printf("============================\n");
    printf("1. Log a system event\n");
    printf("2. Log a user login event\n");
    printf("3. Log a system error event\n");
    printf("============================\n");
}

void perform_action(int choice) {
    char event_description[BUFFER_SIZE];

    switch (choice) {
        case 1:
            printf("Enter event description: ");
            getchar(); // Clear newline
            fgets(event_description, sizeof(event_description), stdin);
            strcspn(event_description, "\n"); // Remove newline
            log_event(event_description);
            printf("Event logged: %s\n", event_description);
            break;
        case 2:
            log_event("User logged in.");
            printf("User login event logged.\n");
            break;
        case 3:
            log_event("System error occurred.");
            printf("System error event logged.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}