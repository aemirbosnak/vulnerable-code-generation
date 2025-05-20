//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256
#define MAX_EVENT_LENGTH 128

void log_event(const char *event) {
    // Check if the event is too long
    if (strlen(event) >= MAX_EVENT_LENGTH) {
        fprintf(stderr, "Event exceeds maximum length. Logging aborted for event: %s\n", event);
        return;
    }

    // Create and open log file
    int fd = open(LOG_FILE, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if (fd == -1) {
        fprintf(stderr, "Failed to open log file! Are we under surveillance?\n");
        return;
    }

    // Prepare event message with a timestamp
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n", 
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
             t->tm_hour, t->tm_min, t->tm_sec, event);

    // Log the event into the file
    write(fd, buffer, strlen(buffer));
    close(fd);
}

void paranoid_mode() {
    // Randomize a delay to confuse anyone watching
    usleep((rand() % 5 + 1) * 100000); // sleep for 100ms to 500ms

    // Check the environment
    log_event("Suspicious activity detected! Scanning environment...");
    log_event("Checking for unauthorized access...");

    // Simulate checking logs (could be a system checker)
    FILE *file = fopen(LOG_FILE, "r");
    if (file) {
        log_event("Log file accessed. Ensuring integrity...");
        fclose(file);
    } else {
        log_event("Log file could not be accessed! Potential breach!");
    }
}

void event_listener() {
    char command[BUFFER_SIZE];
    while (1) {
        printf("Enter an event to log (or type 'exit' to quit): ");
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            log_event("Exiting event listener.");
            break;
        }

        log_event(command);
        paranoid_mode(); // Check environment after each log entry
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    log_event("Starting the paranoid event logger.");

    // Initialize event listener
    event_listener();

    log_event("Paranoid event logger has stopped.");
    return 0;
}