//FormAI DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <time.h>

void logEvent(const char* eventName) {
    // Get current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Open log file
    FILE* file = fopen("system_events.log", "a");
    if (file == NULL) {
        printf("Error opening log file!");
        return;
    }

    // Write log message
    fprintf(file, "%d-%02d-%02d %02d:%02d:%02d - %s\n", 
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, 
            t->tm_hour, t->tm_min, t->tm_sec, eventName);

    // Close log file
    fclose(file);

    // Print confirmation message
    printf("Event \"%s\" logged successfully!\n", eventName);
}

int main() {
    printf("Welcome to the Happy System Event Logger!\n");
    printf("========================================\n");

    char eventName[50];

    // Loop until user wishes to exit
    while (1) {
        // Prompt user for event name
        printf("Please enter an event name (or \"exit\" to quit): ");
        scanf("%s", eventName);

        // Check if user wants to exit
        if (strcmp(eventName, "exit") == 0) {
            printf("Thank you for using the Happy System Event Logger!\n");
            break;
        }

        // Log event
        logEvent(eventName);
    }

    return 0;
}