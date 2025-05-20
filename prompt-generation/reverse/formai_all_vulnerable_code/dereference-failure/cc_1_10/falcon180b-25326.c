//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000

// Struct to store event information
typedef struct {
    char type[20];
    char message[MAX_LINE_LENGTH];
    time_t timestamp;
} Event;

// Function prototypes
void log_event(const char* type, const char* message);
void print_log(FILE* log_file);
void close_log(FILE* log_file);

// Global variables
FILE* log_file = NULL;
char log_filename[50] = "event_log.txt";

int main() {
    log_file = fopen(log_filename, "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    atexit(close_log);

    // Example events
    log_event("INFO", "Program started.");
    log_event("WARNING", "Some warning message.");
    log_event("ERROR", "An error occurred.");

    return 0;
}

// Log an event to the log file
void log_event(const char* type, const char* message) {
    Event event;
    strcpy(event.type, type);
    strcpy(event.message, message);
    time(&event.timestamp);

    fprintf(log_file, "%s - %s\n", ctime(&event.timestamp), event.message);
}

// Print the contents of the log file
void print_log(FILE* log_file) {
    rewind(log_file);
    while (fgets(log_filename, MAX_LINE_LENGTH, log_file)!= NULL) {
        printf("%s", log_filename);
    }
}

// Close the log file
void close_log(FILE* log_file) {
    fclose(log_file);
}