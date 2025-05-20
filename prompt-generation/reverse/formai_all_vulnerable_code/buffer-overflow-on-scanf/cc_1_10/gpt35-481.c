//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    printf("Surprise! You are now running a unique C System Event Logger program!\n\n");

    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char filename[50];
    strftime(filename, sizeof(filename), "Event_Log_%m-%d-%Y_%H-%M-%S.txt", timeinfo);

    printf("Your event log file has been created: %s\n\n", filename);

    FILE *fptr;
    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Error creating file. Exiting program.\n");
        return 1;
    }

    fprintf(fptr, "*****SYSTEM EVENT LOGGER*****\n\n");

    char eventName[100];
    char eventDate[50];
    char eventTime[50];
    char eventDescription[1000];
    int eventNumber = 0;

    printf("Please enter the name of the event you would like to log: ");
    scanf("%s", eventName);

    printf("\nPlease enter the date of the event in MM/DD/YYYY format: ");
    scanf("%s", eventDate);

    printf("\nPlease enter the time the event occurred in HH:MM:SS format: ");
    scanf("%s", eventTime);

    printf("\nPlease enter a brief description of the event: ");
    scanf("%s", eventDescription);

    fprintf(fptr, "Event #%d: %s\nDate: %s\nTime: %s\nDescription: %s\n\n", eventNumber, eventName, eventDate, eventTime, eventDescription);
    printf("\nEvent successfully logged!\n\n");

    printf("Would you like to log another event? (Y/N): ");
    char response[10];
    scanf("%s", response);

    while (strcmp(response, "Y") == 0 || strcmp(response, "y") == 0) {
        printf("Please enter the name of the event you would like to log: ");
        scanf("%s", eventName);

        printf("\nPlease enter the date of the event in MM/DD/YYYY format: ");
        scanf("%s", eventDate);

        printf("\nPlease enter the time the event occurred in HH:MM:SS format: ");
        scanf("%s", eventTime);

        printf("\nPlease enter a brief description of the event: ");
        scanf("%s", eventDescription);

        eventNumber++;

        fprintf(fptr, "Event #%d: %s\nDate: %s\nTime: %s\nDescription: %s\n\n", eventNumber, eventName, eventDate, eventTime, eventDescription);
        printf("\nEvent successfully logged!\n\n");

        printf("Would you like to log another event? (Y/N): ");
        scanf("%s", response);
    }

    fclose(fptr);

    printf("Thank you for using the System Event Logger program. Goodbye!\n");

    return 0;
}