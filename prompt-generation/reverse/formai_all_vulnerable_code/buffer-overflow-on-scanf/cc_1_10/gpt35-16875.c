//FormAI DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXEVENTS 20

int main(void) {

    char* eventLog[MAXEVENTS];
    int eventCounter = 0;

    time_t currentTime;
    struct tm* timeInfo;
    char timeStr[30];

    // Romeo: My dear event logger, pray tell thy name
    printf("Romeo: My dear event logger, pray tell thy name\n");

    // Juliet: My name is Juliet, and I am here to serve thee
    printf("Juliet: My name is Juliet, and I am here to serve thee\n");

    while (1) {

        // Romeo: We need to log an event, can you help us Juliet?
        printf("Romeo: We need to log an event, can you help us Juliet?\n");

        // Juliet: Of course, what is the event?
        printf("Juliet: Of course, what is the event?\n");

        char event[50];
        scanf("%s", event);

        // Romeo: Wonderful, now we need to get the current time
        printf("Romeo: Wonderful, now we need to get the current time\n");

        currentTime = time(NULL);
        timeInfo = localtime(&currentTime);

        strftime(timeStr, sizeof(timeStr), "%c", timeInfo);

        // Juliet: The event was logged at %s. Shall I add it to the event log?
        printf("Juliet: The event was logged at %s. Shall I add it to the event log?\n", timeStr);

        // Romeo: Yes, please do
        printf("Romeo: Yes, please do\n");

        if (eventCounter < MAXEVENTS) {
            eventLog[eventCounter] = (char *) malloc(sizeof(event));
            sprintf(eventLog[eventCounter], "%s - %s", timeStr, event);

            eventCounter++;

            // Juliet: The event was successfully logged.
            printf("Juliet: The event was successfully logged.\n");
        } else {
            // Juliet: The event log is full, cannot log further events.
            printf("Juliet: The event log is full, cannot log further events.\n");
        }

        // Romeo: Should we log another event?
        printf("Romeo: Should we log another event?\n");

        char answer[5];
        scanf("%s", answer);

        if (strcmp(answer, "yes") != 0) {
            // Juliet: Farewell, Romeo. May your code be free of bugs.
            printf("Juliet: Farewell, Romeo. May your code be free of bugs.\n");
            break;
        }
    }

    // Printing all events in the log
    printf("\n\nEvent Log:\n\n");

    for (int i = 0; i < eventCounter; i++) {
        printf("%s\n", eventLog[i]);
        free(eventLog[i]);
    }

    // Juliet: This concludes my service. Farewell!
    printf("Juliet: This concludes my service. Farewell!\n");

    return 0;
}