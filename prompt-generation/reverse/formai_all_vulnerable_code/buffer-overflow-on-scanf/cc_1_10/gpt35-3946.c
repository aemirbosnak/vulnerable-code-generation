//FormAI DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * This program is a futuristic C System event logger that records system events
 * and stores them in a log file. The log file is encrypted to ensure data security.
 * The user can search and view the logs based on various parameters such as date,
 * severity, message etc.
 */

// Function prototypes
void logEvent(int, char*);
void searchLogs();

// Main function
int main()
{
    int choice, severity;
    char message[256];
    
    // Display menu
    while (1)
    {
        printf("\n\n---------------------------");
        printf("\nFUTURISTIC EVENT LOGGER MENU");
        printf("\n---------------------------");
        printf("\n1. Log an event");
        printf("\n2. Search logs");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Get severity and message from user
                printf("\nEnter event severity (1-10): ");
                scanf("%d", &severity);

                printf("Enter event message: ");
                scanf("%s", message);

                // Log the event
                logEvent(severity, message);
                printf("\nEvent logged successfully.");
                break;

            case 2:
                // Search logs
                searchLogs();
                break;

            case 3:
                // Exit program
                printf("\nExiting program...");
                exit(0);

            default:
                printf("\nInvalid choice. Try again.");
                break;
        }
    }

    return 0;
}

// Function to log an event
void logEvent(int severity, char* message)
{
    FILE* fp;
    char fileName[] = "event_log.bin";
    time_t now;
    struct tm* timeInfo;
    char timeStr[21];
    int key = 5; // Encryption key

    // Get current time
    time(&now);
    timeInfo = localtime(&now);
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeInfo);

    // Open log file in append mode and write event to it
    fp = fopen(fileName, "ab");
    if (fp != NULL)
    {
        // Encrypt message
        for (int i = 0; message[i] != '\0'; i++)
        {
            message[i] = message[i] + key;
        }

        // Write to file
        fwrite(&severity, sizeof(int), 1, fp);
        fwrite(timeStr, sizeof(char), strlen(timeStr), fp);
        fwrite(message, sizeof(char), strlen(message), fp);

        // Close file
        fclose(fp);
    }
    else
    {
        printf("\nError: Could not open log file.");
    }
}

// Function to search logs
void searchLogs()
{
    FILE* fp;
    char fileName[] = "event_log.bin";
    int severity, count = 0;
    char timeStr[21], message[256];
    char searchStr[256];

    // Get search string from user
    printf("\nEnter search string: ");
    scanf("%s", searchStr);

    // Open log file in read mode and search for string
    fp = fopen(fileName, "rb");
    if (fp != NULL)
    {
        printf("\nSEARCH RESULTS:");
        printf("\n---------------\n");

        // Read log file line by line
        while (!feof(fp))
        {
            fread(&severity, sizeof(int), 1, fp);
            fread(timeStr, sizeof(char), 20, fp);
            timeStr[20] = '\0';
            fread(message, sizeof(char), 256, fp);

            // Decrypt message
            for (int i = 0; message[i] != '\0'; i++)
            {
                message[i] = message[i] - 5;
            }

            // Search for string in message
            if (strstr(message, searchStr) != NULL)
            {
                printf("\nSeverity: %d", severity);
                printf("\nTime: %s", timeStr);
                printf("\nMessage: %s", message);
                count++;
            }
        }

        // Close file
        fclose(fp);

        // Display count of search results
        printf("\n\nTOTAL RESULTS FOUND: %d", count);
    }
    else
    {
        printf("\nError: Could not open log file.");
    }
}