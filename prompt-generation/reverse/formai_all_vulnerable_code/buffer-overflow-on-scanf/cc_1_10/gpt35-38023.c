//FormAI DATASET v1.0 Category: System event logger ; Style: immersive
#include <stdio.h>

int main()
{
    printf("Initializing System Event Logger...\n\n");
    printf("Welcome to the immersive System Event Logger!\n");
    printf("This program will log all system events on your device.\n");
    printf("You will be able to track all the key events happening on your system.\n");
    printf("Press enter to start logging events...\n");

    getchar();

    printf("Event logging has started...\n\n");

    FILE *fptr;
    fptr = fopen("system_log.txt", "a");

    if(fptr == NULL)
    {
        printf("Error! Unable to create/open system log file.\n");
        return 1;
    }

    int event_count = 0;
    char event_name[50];
    char event_description[200];

    printf("Enter events to log. Type \"exit\" to stop logging.\n");

    while(1)
    {
        event_count++;

        printf("Enter Event Name: ");
        scanf("%s", event_name);

        if(strcmp(event_name, "exit") == 0)
            break;

        printf("Enter Event Description: ");
        scanf("%s", event_description);

        fprintf(fptr, "Event %d:\nEvent Name: %s\nEvent Description: %s\n\n", event_count, event_name, event_description);
    }

    fclose(fptr);

    printf("All events have been logged.\n");
    printf("System Event Logger is now shutting down.\n");

    return 0;
}