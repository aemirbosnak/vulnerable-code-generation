//FormAI DATASET v1.0 Category: System event logger ; Style: complete
// A C System Event Logger Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Event codes:
    0 = System Startup
    1 = Login
    2 = Logout
    3 = System Shutdown
    4 = Program Error
*/

void logEvent(int eventCode)
{
    FILE *logFile;

    // Attempt to open/create log file
    logFile = fopen("systemlog.txt", "a");

    if (logFile == NULL) {
        printf("Error: Unable to create/open log file.\n");
        return;
    }

    // Get current time and format for log entry
    time_t currentTime;
    char timeString[20];
    time(&currentTime);
    strftime(timeString, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

    // Output log entry to file
    switch(eventCode) {
        case 0:
            fprintf(logFile, "[%s] SYSTEM STARTUP\n", timeString);
            break;
        case 1:
            fprintf(logFile, "[%s] LOGIN\n", timeString);
            break;
        case 2:
            fprintf(logFile, "[%s] LOGOUT\n", timeString);
            break;
        case 3:
            fprintf(logFile, "[%s] SYSTEM SHUTDOWN\n", timeString);
            break;
        case 4:
            fprintf(logFile, "[%s] PROGRAM ERROR\n", timeString);
            break;
        default:
            printf("Error: Invalid event code.\n");
            fclose(logFile);
            return;
    }

    fclose(logFile);
}

int main()
{
    int eventCode;

    printf("Enter an event code: ");
    scanf("%d", &eventCode);

    logEvent(eventCode);

    return 0;
}