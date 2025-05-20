//FormAI DATASET v1.0 Category: System event logger ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* eventName, char* eventDescription, char* eventDate) {
    FILE *fp;
    fp = fopen("event_log.txt", "a");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    char* date = asctime(localTime);
    date[strlen(date)-1] = '\0';

    fprintf(fp, "Event Name: %s\n", eventName);
    fprintf(fp, "Event Description: %s\n", eventDescription);
    fprintf(fp, "Event Date: %s\n", eventDate);
    fprintf(fp, "Current Time: %s\n", date);
    fprintf(fp, "\n");

    fclose(fp);
}

int main() {
    char eventName[50];
    char eventDescription[100];
    char eventDate[20];

    printf("Enter Event Name: ");
    fgets(eventName, 50, stdin);
    eventName[strlen(eventName)-1] = '\0';

    printf("Enter Event Description: ");
    fgets(eventDescription, 100, stdin);
    eventDescription[strlen(eventDescription)-1] = '\0';

    printf("Enter Event Date (in the format of yyyy-mm-dd): ");
    fgets(eventDate, 20, stdin);
    eventDate[strlen(eventDate)-1] = '\0';

    logEvent(eventName, eventDescription, eventDate);

    printf("Event has been logged successfully\n");

    return 0;
}