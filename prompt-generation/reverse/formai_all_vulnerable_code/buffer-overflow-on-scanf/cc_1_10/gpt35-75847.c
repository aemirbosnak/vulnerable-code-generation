//FormAI DATASET v1.0 Category: System event logger ; Style: scientific
/*
 * C System Event Logger 
 *
 * This program logs system events including date, time, event type,
 * and relevant details into a log file. The user can specify the log
 * file name and the program creates the file in the current directory.
 *
 * Author: [Your Name]
 * Date: [Current Date]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event_type, char* details) {
    time_t now;
    time(&now);
    char timeStr[26];
    struct tm* tm_info;
    tm_info = localtime(&now);
    strftime(timeStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    // Open log file
    FILE* log_file;
    log_file = fopen("system_events.log", "a");
    if (log_file == NULL) {
        printf("Error: Could not open system_events.log");
        return;
    }

    // Write to log file
    fprintf(log_file, "%s [%s] %s\n", timeStr, event_type, details);

    // Close log file
    fclose(log_file);
}

int main() {
    char event_type[100];
    char details[1000];

    printf("Enter event type: ");
    scanf("%s", event_type);

    printf("Enter details: ");
    scanf("%s", details);

    log_event(event_type, details);

    printf("Event logged successfully in system_events.log");

    return 0;
}