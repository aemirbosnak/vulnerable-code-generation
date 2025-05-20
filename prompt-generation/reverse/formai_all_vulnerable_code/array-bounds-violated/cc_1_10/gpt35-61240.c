//FormAI DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 100

struct EventLog {
    char event[100];
    char date[20];
    char time[20];
};

int main() {
    struct EventLog eventLog[MAX_LOG_SIZE];
    int logCount = 0;

    // Set the current date and time
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    char currentDate[20];
    char currentTime[20];
    sprintf(currentDate, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(currentTime, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("Enter events to log. Type 'exit' to exit.\n");

    while (logCount < MAX_LOG_SIZE) {
        // Prompt user to enter an event
        printf("\nWhat happened? ");
        fgets(eventLog[logCount].event, 100, stdin);

        // Remove newline character from input
        if (eventLog[logCount].event[strlen(eventLog[logCount].event) - 1] == '\n') {
            eventLog[logCount].event[strlen(eventLog[logCount].event) - 1] = '\0';
        }

        // Check if user wants to exit
        if (strcmp(eventLog[logCount].event, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Log the current date and time
        strcpy(eventLog[logCount].date, currentDate);
        strcpy(eventLog[logCount].time, currentTime);

        // Increment log count
        logCount++;

        // Display confirmation message to user
        printf("\n> %s, at %s on %s, was logged.\n", eventLog[logCount-1].event, eventLog[logCount-1].time, eventLog[logCount-1].date);
    }

    // Print out the entire event log
    printf("\n\nEvent Log\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        printf("%s on %s, at %s\n", eventLog[i].event, eventLog[i].date, eventLog[i].time);
    }
    printf("-------------------------------------------------------\n");

    return 0;
}