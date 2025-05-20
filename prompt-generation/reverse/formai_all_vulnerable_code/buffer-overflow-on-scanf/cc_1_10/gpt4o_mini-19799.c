//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LEN 256

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        return;
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Write timestamp and event to the log file
    fprintf(file, "[%02d-%02d-%04d %02d:%02d:%02d] %s\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec, event);

    fclose(file);
}

void simulate_event(const char *event_type) {
    char event[MAX_EVENT_LEN];
    snprintf(event, sizeof(event), "Simulated event: %s", event_type);
    log_event(event);
}

void display_menu() {
    printf("Event Logger Menu:\n");
    printf("1. Simulate User Login\n");
    printf("2. Simulate User Logout\n");
    printf("3. Simulate Error Event\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                simulate_event("User Login");
                printf("User Login event logged.\n");
                break;
            case 2:
                simulate_event("User Logout");
                printf("User Logout event logged.\n");
                break;
            case 3:
                simulate_event("Error Occurred");
                printf("Error event logged.\n");
                break;
            case 4:
                printf("Exiting Logger. Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}