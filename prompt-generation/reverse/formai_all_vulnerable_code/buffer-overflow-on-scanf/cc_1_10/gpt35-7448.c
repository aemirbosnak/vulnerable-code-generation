//FormAI DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
// Post-Apocalyptic C System Event Logger Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get the current timestamp
char* get_timestamp() {
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    return asctime(timeinfo);
}

// Function to log system events
void log_event(char* event) {
    FILE *fp;
    fp = fopen("event.log", "a+");
    fprintf(fp, "%s: %s\n", get_timestamp(), event);
    fclose(fp);
}

int main() {
    char choice;
    char eventData[100];

    printf("Welcome to the Post-Apocalyptic C System Event Logger!\n");

    while(1) {
        printf("\nEnter 1 to log an event\nEnter 2 to exit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("\nEnter the event data:\n");
                scanf(" %[^\n]s", eventData);
                log_event(eventData);
                printf("\nEvent logged successfully!\n");
                break;
            case '2':
                printf("\nExiting the program...");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}