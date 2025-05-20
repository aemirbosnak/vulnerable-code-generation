//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_LENGTH 255

// Function to get the current time as a string
void getCurrentTime(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_now);
}

// Function to log an event
void logEvent(const char* event) {
    FILE *file = fopen("event_log.txt", "a");
    if (file != NULL) {
        char timeBuffer[20];
        getCurrentTime(timeBuffer, sizeof(timeBuffer));
        fprintf(file, "[%s] %s\n", timeBuffer, event);
        fclose(file);
    } else {
        printf("Error opening log file.\n");
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nEvent Logger Menu:\n");
    printf("1. Log an event\n");
    printf("2. Exit\n");
}

// Main function
int main() {
    int choice;
    char event[EVENT_LENGTH];

    printf("Welcome to the Event Logger!\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter event description (max %d characters): ", EVENT_LENGTH - 1);
                fgets(event, EVENT_LENGTH, stdin);
                // Remove newline character from input
                event[strcspn(event, "\n")] = 0; 
                
                logEvent(event);
                printf("Event logged successfully!\n");
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}