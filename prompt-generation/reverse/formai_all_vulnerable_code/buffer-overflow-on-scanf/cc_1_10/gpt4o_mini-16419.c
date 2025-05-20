//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Oh no! Can't open log file for writing. Is the directory really there?\n");
        return;
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    // Remove the newline character from the timestamp
    timestamp[strcspn(timestamp, "\n")] = 0;

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
    
    printf("Yay! Event logged successfully: %s\n", event);
}

void display_menu() {
    printf("\n🎉 Welcome to the Happy Event Logger! 🎉\n");
    printf("Please choose an option below:\n");
    printf("1. Log an Event\n");
    printf("2. Exit\n");
}

int main() {
    char event[MAX_EVENT_LENGTH];
    int choice;

    while (1) {
        display_menu();
        
        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("🎈 Please enter your event message (max %d characters):\n", MAX_EVENT_LENGTH - 1);
            getchar(); // clear new line character from buffer
            fgets(event, MAX_EVENT_LENGTH, stdin);
            // Remove potential newline character
            event[strcspn(event, "\n")] = 0;

            log_event(event);
        } else if (choice == 2) {
            printf("Thank you for using the Happy Event Logger! Goodbye! 🌈\n");
            break;
        } else {
            printf("Oops! That's not a valid option. Please try again. 😊\n");
        }
    }

    return 0;
}