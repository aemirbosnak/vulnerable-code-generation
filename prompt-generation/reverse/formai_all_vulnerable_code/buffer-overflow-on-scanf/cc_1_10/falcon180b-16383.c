//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define LOG_FILE "event_log.txt"

typedef struct {
    char type[20];
    char message[100];
    time_t timestamp;
} EventLogEntry;

void addEntry(EventLogEntry* entries, int numEntries, char* type, char* message) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Event log is full.\n");
        return;
    }
    strcpy(entries[numEntries].type, type);
    strcpy(entries[numEntries].message, message);
    entries[numEntries].timestamp = time(NULL);
    numEntries++;
}

void displayEntries(EventLogEntry* entries, int numEntries) {
    printf("Event Log:\n");
    printf("-------------------------------\n");
    printf("Type\tMessage\tTimestamp\n");
    printf("-------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%-20s", entries[i].type);
        printf("%-80s", entries[i].message);
        printf("%-20s", ctime(&entries[i].timestamp));
        printf("\n");
    }
}

int main() {
    FILE* logFile;
    EventLogEntry entries[MAX_ENTRIES];
    int numEntries = 0;

    printf("Cyberpunk Event Logger\n");

    logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        printf("Error: Unable to open log file.\n");
        return 1;
    }

    while (1) {
        printf("\nEnter event type (max 20 characters): ");
        scanf("%s", entries[numEntries].type);

        printf("Enter event message (max 100 characters): ");
        scanf("%[^\n]", entries[numEntries].message);

        addEntry(entries, numEntries, entries[numEntries].type, entries[numEntries].message);
        numEntries++;

        if (numEntries == MAX_ENTRIES) {
            break;
        }
    }

    fclose(logFile);

    displayEntries(entries, numEntries);

    return 0;
}