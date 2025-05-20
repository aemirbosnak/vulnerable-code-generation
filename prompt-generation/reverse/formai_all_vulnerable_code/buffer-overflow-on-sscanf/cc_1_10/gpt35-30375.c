//FormAI DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <time.h>

void logEvent(char* event)
{
    char timeString[32];
    time_t currentTime;
    struct tm* timeInfo;

    time(&currentTime);
    timeInfo = localtime(&currentTime);

    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo);

    FILE* logFile;
    logFile = fopen("system_events.log", "a");

    if (logFile != NULL)
    {
        fprintf(logFile, "[%s]: %s\n", timeString, event);
        fclose(logFile);
    }
}

int main()
{
    char userInput[128];
    int choice = 0;

    printf("Welcome to Retro System Event Logger\n\n");

    while (1)
    {
        printf("1. Log an event\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        fgets(userInput, sizeof(userInput), stdin);

        if (sscanf(userInput, "%d", &choice) != 1)
        {
            printf("Invalid choice! Try again.\n\n");
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                char event[256];
                printf("Enter the event description: ");
                fgets(event, sizeof(event), stdin);
                logEvent(event);
                printf("Event logged successfully.\n\n");
                break;
            }
            case 2:
            {
                printf("Exiting Retro System Event Logger...\n");
                return 0;
            }
            default:
            {
                printf("Invalid choice! Try again.\n\n");
                break;
            }
        }
    }

    return 0;
}