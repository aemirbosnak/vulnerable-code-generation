//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "system_events.log"
#define MAX_EVENT_LENGTH 256

void log_event(const char *event) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Unable to open log file");
        return;
    }

    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    
    // Remove newline character from timestamp
    timestamp[strcspn(timestamp, "\n")] = 0;

    fprintf(fp, "[%s] %s\n", timestamp, event);
    fclose(fp);
}

void simulate_event(const char *event_type) {
    if (strcmp(event_type, "start") == 0) {
        log_event("Service started successfully.");
    } else if (strcmp(event_type, "stop") == 0) {
        log_event("Service stopped.");
    } else if (strcmp(event_type, "error") == 0) {
        log_event("An error occurred.");
    } else if (strcmp(event_type, "login") == 0) {
        log_event("User logged in.");
    } else {
        log_event("Unknown event.");
    }
}

void display_menu() {
    printf("System Event Logger Menu:\n");
    printf("1. Simulate Service Start\n");
    printf("2. Simulate Service Stop\n");
    printf("3. Simulate Error\n");
    printf("4. Simulate User Login\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                simulate_event("start");
                printf("Logged: Service started.\n");
                break;
            case 2:
                simulate_event("stop");
                printf("Logged: Service stopped.\n");
                break;
            case 3:
                simulate_event("error");
                printf("Logged: Error event occurred.\n");
                break;
            case 4:
                simulate_event("login");
                printf("Logged: User has logged in.\n");
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
        sleep(1);  // Introduce a small delay for better readability
    }

    return 0;
}