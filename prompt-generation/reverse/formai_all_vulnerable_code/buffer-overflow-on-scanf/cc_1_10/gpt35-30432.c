//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define LOG_SIZE 100

struct EventLog {
    int eventId;
    char eventTime[20];
    char eventDesc[100];
};

void logEvent(struct EventLog* log, int* currentSize) {
    if (*currentSize >= LOG_SIZE) {
        printf("Log limit reached!\n");
        return;
    }

    printf("Enter event ID: ");
    scanf("%d", &log[*currentSize].eventId);

    // Implementing secure input via fgets
    printf("Enter event time in format dd/mm/yyyy hh:mm:ss: ");
    fgets(log[*currentSize].eventTime, sizeof(log[*currentSize].eventTime), stdin);
    log[*currentSize].eventTime[strlen(log[*currentSize].eventTime) - 1] = '\0';

    printf("Enter event description: ");
    fgets(log[*currentSize].eventDesc, sizeof(log[*currentSize].eventDesc), stdin);
    log[*currentSize].eventDesc[strlen(log[*currentSize].eventDesc) - 1] = '\0';

    printf("Event logged successfully!\n");
    (*currentSize)++;
}

void viewLog(struct EventLog* log, int currentSize) {
    if (currentSize == 0) {
        printf("Log is empty!\n");
        return;
    }

    printf("ID\tTime\t\t\t\t\tDescription\n");
    for (int i = 0; i < currentSize; i++) {
        printf("%d\t%s\t%s\n", log[i].eventId, log[i].eventTime, log[i].eventDesc);
    }
}

int menu() {
    int choice;
    printf("\n1. Log an event\n");
    printf("2. View event log\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct EventLog log[LOG_SIZE];
    int currentSize = 0;

    while (1) {
        switch (menu()) {
            case 1:
                // logging an event
                logEvent(log, &currentSize);
                break;
            case 2:
                // viewing log
                viewLog(log, currentSize);
                break;
            case 3:
                // exiting
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}