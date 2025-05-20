//FormAI DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define a struct to hold system events */
struct SystemEvent {
    char name[50];
    time_t timestamp;
};

/* Define a function to write system events to a log file */
void logEvent(struct SystemEvent event) {
    FILE *logFile;
    logFile = fopen("system_event_log.txt", "a");
    fprintf(logFile, "%s occurred at %s\n", event.name, ctime(&event.timestamp));
    fclose(logFile);
}

int main() {
    /* Seed the random number generator */
    srand(time(0));
    
    /* Define an array of system event names */
    char* eventNames[] = {"Shutdown", "Startup", "Crash", "Update", "Install", "Login", "Logout", "Error", "Warning", "Info"};
    
    /* Define a loop to generate random system events */
    for (int i = 1; i <= 50; i++) {
        /* Generate a random event name */
        int randomIndex = rand() % 10;
        char randomEventName[50];
        strcpy(randomEventName, eventNames[randomIndex]);
        
        /* Generate a random timestamp for the event */
        time_t timestamp = time(0) - (rand() % 86400);
        
        /* Create a new system event */
        struct SystemEvent newEvent = {randomEventName, timestamp};
        
        /* Write the event to the log file */
        logEvent(newEvent);
    }
    
    /* Print out the contents of the log file */
    FILE *logFile;
    logFile = fopen("system_event_log.txt", "r");
    char logLine[100];
    printf("System Event Log:\n");
    while (fgets(logLine, 100, logFile)) {
        printf("%s", logLine);
    }
    fclose(logFile);
    
    return 0;
}