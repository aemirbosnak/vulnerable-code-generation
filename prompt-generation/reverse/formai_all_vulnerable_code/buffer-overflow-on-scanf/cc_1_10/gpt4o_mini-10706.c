//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_EVENTS 100
#define EVENT_LENGTH 256

// Event structure
typedef struct {
    char message[EVENT_LENGTH];
    time_t timestamp;
} Event;

// Global event array
Event events[MAX_EVENTS];
int event_count = 0;

// Function to get current timestamp as a formatted string
char* get_timestamp() {
    static char buffer[20];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, sizeof(buffer)-1, "%Y-%m-%d %H:%M:%S", t);
    return buffer;
}

// Function to add an event
void log_event(const char *message) {
    if (event_count < MAX_EVENTS) {
        strncpy(events[event_count].message, message, EVENT_LENGTH - 1);
        events[event_count].message[EVENT_LENGTH - 1] = '\0'; // Ensure null-termination
        events[event_count].timestamp = time(NULL);
        event_count++;
        printf("\033[32mEvent logged successfully!\033[0m\n"); // Green text
    } else {
        printf("\033[31mEvent log is full! Unable to log new event.\033[0m\n"); // Red text
    }
}

// Function to display logged events
void display_events() {
    if (event_count == 0) {
        printf("\033[33mNo events logged yet.\033[0m\n"); // Yellow text
        return;
    }
    printf("\033[34m--- Event Log ---\033[0m\n"); // Blue text
    for (int i = 0; i < event_count; i++) {
        printf("[%s] %s\n", get_timestamp(), events[i].message);
    }
}

void show_menu() {
    printf("\033[35m-- Event Logger Menu --\033[0m\n"); // Magenta text
    printf("1. Log a new event\n");
    printf("2. Display all events\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;
    char event_message[EVENT_LENGTH];

    while (1) {
        show_menu();
        scanf("%d", &option);
        getchar(); // Consume newline character

        switch (option) {
            case 1:
                printf("Enter your event message: ");
                fgets(event_message, EVENT_LENGTH, stdin);
                event_message[strcspn(event_message, "\n")] = 0; // Remove newline
                log_event(event_message);
                break;
            case 2:
                display_events();
                break;
            case 3:
                printf("\033[36mExiting the Event Logger. Goodbye!\033[0m\n"); // Cyan text
                exit(0);
            default:
                printf("\033[31mInvalid option! Please try again.\033[0m\n"); // Red text
        }
        sleep(1); // Pause for a moment
    }

    return 0;
}