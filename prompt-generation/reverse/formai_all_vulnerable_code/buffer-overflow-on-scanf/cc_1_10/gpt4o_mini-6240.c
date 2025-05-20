//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256
#define DATE_TIME_FORMAT "%Y-%m-%d %H:%M:%S"

// Function to get current date and time as a string
char* get_current_datetime(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 20, DATE_TIME_FORMAT, t);
    return buffer;
}

// Function to log events to a file
void log_event(const char *event) {
    int fd = open(LOG_FILE, O_APPEND | O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("Failed to open log file");
        return;
    }

    char datetime[20];
    get_current_datetime(datetime);

    char log_entry[MAX_EVENT_LENGTH];
    snprintf(log_entry, sizeof(log_entry), "[%s] %s\n", datetime, event);
    
    write(fd, log_entry, strlen(log_entry));
    close(fd);
}

// Function to display the menu
void display_menu() {
    printf("==== Event Logger ====\n");
    printf("1. Log a system event\n");
    printf("2. Exit\n");
    printf("======================\n");
}

// Function to read a string from user
void read_event(char *buffer, size_t size) {
    printf("Enter event description: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}


int main() {
    char event[MAX_EVENT_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after scanf

        switch (choice) {
            case 1:
                read_event(event, sizeof(event));
                log_event(event);
                printf("Event logged successfully!\n");
                break;
            case 2:
                printf("Exiting the event logger.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}