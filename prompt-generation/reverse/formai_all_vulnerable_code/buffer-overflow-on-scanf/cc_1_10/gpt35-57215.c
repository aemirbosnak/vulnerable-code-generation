//FormAI DATASET v1.0 Category: System event logger ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum log length
#define MAX_LOG_LENGTH 100

// Declare the struct for log
typedef struct {
    char date[20];
    char time[20];
    char event[50];
} Log;

// Declare a function to get the current date and time
void currentDateTime(char* dateStr, char* timeStr) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(dateStr, 20, "%Y-%m-%d", t);
    strftime(timeStr, 20, "%H:%M:%S", t);
}

int main() {

    Log log[MAX_LOG_LENGTH];

    int i = 0;

    // Open the log file for writing in append mode
    FILE *logFile = fopen("system_log.txt", "a");

    // Loop to get system events
    while (i < MAX_LOG_LENGTH) {
        char date[20];
        char time[20];
        currentDateTime(date, time);

        printf("Enter the system event: ");
        char event[50];
        scanf(" %[^\n]s", event);

        // Save the log into the struct
        strcpy(log[i].date, date);
        strcpy(log[i].time, time);
        strcpy(log[i].event, event);

        // Write the log into the file
        fprintf(logFile, "%s %s : %s\n", date, time, event);

        printf("Log saved successfully.\n");

        printf("Do you want to save another log? (Y/N) ");
        char choice;
        scanf(" %c", &choice);

        // Check if the user wants to save another log or not
        if (choice == 'Y' || choice == 'y') {
            i++;
        }
        else {
            break;
        }
    }

    // Close the file after writing
    fclose(logFile);

    printf("\nAll logs have been saved successfully.\n\n");
    printf("========== SYSTEM LOG ==========\n");

    for (int j = 0; j <= i; j++) {
        printf("%s %s : %s\n", log[j].date, log[j].time, log[j].event);
    }

    return 0;
}