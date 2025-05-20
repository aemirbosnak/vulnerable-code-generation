//Falcon-180B DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOGFILE "event.log"
#define MAX_LOG_ENTRIES 1000

// Log entry structure
typedef struct {
    time_t timestamp;
    char event[100];
} LogEntry;

// Function prototypes
void initLog(FILE *logfile);
void logEvent(FILE *logfile, char *event);
void closeLog(FILE *logfile);

// Main function
int main() {
    FILE *logfile;
    char event[100];

    // Initialize log file
    logfile = fopen(LOGFILE, "w");
    if (logfile == NULL) {
        printf("Error: could not create log file\n");
        exit(1);
    }

    // Initialize log with header
    initLog(logfile);

    // Loop to log events
    while (1) {
        printf("Enter event to log (or type 'quit' to exit): ");
        scanf("%s", event);

        if (strcmp(event, "quit") == 0) {
            break;
        }

        logEvent(logfile, event);
    }

    // Close log file
    fclose(logfile);

    return 0;
}

// Initialize log file with header
void initLog(FILE *logfile) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    fprintf(logfile, "Timestamp\tEvent\n");
    fprintf(logfile, "%d-%02d-%02d %02d:%02d:%02d\tInitialized\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
}

// Log event to file
void logEvent(FILE *logfile, char *event) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    fprintf(logfile, "%d-%02d-%02d %02d:%02d:%02d\t%s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, event);
}

// Close log file
void closeLog(FILE *logfile) {
    fprintf(logfile, "\n");
    fclose(logfile);
}