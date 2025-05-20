//FormAI DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random error code
int getErrorCode() {
    int codes[] = {100, 200, 300, 400, 500};
    int index = rand() % 5;
    return codes[index];
}

int main() {
    int eventCode;
    time_t currentTime;
    char* eventDescription;

    // Get current time
    time(&currentTime);

    // Open log file
    FILE* logFile = fopen("systemEventLog.txt", "a");
    if(logFile == NULL) {
        printf("Error: Could not open log file.");
        return 1;
    }

    // Log system start event
    eventCode = 100;
    eventDescription = "System started successfully";
    fprintf(logFile, "%ld,%d,%s\n", currentTime, eventCode, eventDescription);

    // Simulate some system events
    int i;
    for(i = 0; i < 10; i++) {
        eventCode = getErrorCode();
        if(eventCode == 200) {
            eventDescription = "Low memory warning";
        } else if(eventCode == 400) {
            eventDescription = "Disk space full";
        } else {
            eventDescription = "Unspecified error occurred";
        }
        fprintf(logFile, "%ld,%d,%s\n", currentTime+i, eventCode, eventDescription);
    }

    // Log system stop event
    eventCode = 500;
    eventDescription = "System shut down";
    fprintf(logFile, "%ld,%d,%s\n", currentTime+i, eventCode, eventDescription);

    // Close log file
    fclose(logFile);

    printf("System event log created successfully.");

    return 0;
}