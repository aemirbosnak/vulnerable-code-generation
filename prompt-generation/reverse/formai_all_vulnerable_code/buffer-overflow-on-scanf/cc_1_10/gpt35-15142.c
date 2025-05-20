//FormAI DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Struct for Event Log
typedef struct {
    int event_id;
    char details[200];
    char timestamp[30];
} event_log_t;


// Prototypes
void log_event(int, char*);
void read_logs();
void clear_logs();


// Main
int main() {

    int choice;

    printf("Event Logger\n");

    while (1) {

        printf("\nMenu:\n");
        printf("1. Log an Event \n");
        printf("2. Read Logs \n");
        printf("3. Clear Logs \n");
        printf("4. Exit \n");

        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Log an Event
                printf("\n\tEnter Event ID: ");
                int event_id;
                scanf("%d", &event_id);

                printf("\tEnter Event Details: ");
                char event_details[200];
                scanf("%s", event_details);

                log_event(event_id, event_details);
                break;

            case 2:
                // Read Logs
                printf("\n\tEVENT ID\t\tEVENT DETAILS\t\t\t\t\tTIMESTAMP\n");
                read_logs();
                break;

            case 3:
                // Clear Logs
                clear_logs();
                printf("\n\tEvent Logs Cleared!\n");
                break;

            case 4:
                // Exit Program
                printf("\n\tGoodbye!\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid Choice, Please Try Again!\n");
                break;
        }
    }

    return 0;
}


// Logs an Event into Event Log
void log_event(int event_id, char* event_details) {
    event_log_t event;
    event.event_id = event_id;
    strcpy(event.details, event_details);

    time_t rawtime;
    struct tm * timeinfo;
    char time_format[30];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(time_format, sizeof(time_format), "%d-%m-%Y %H:%M:%S", timeinfo);
    strcpy(event.timestamp, time_format);

    FILE *file = fopen("event_log.txt", "a");

    if (file == NULL) {
        printf("\n\tError Opening File!\n");
        exit(1);
    }

    fwrite(&event, sizeof(event_log_t), 1, file);
    fclose(file);

    printf("\n\tEvent Logged Successfully!\n");
}


// Reads the Event Logs
void read_logs() {
    event_log_t event;
    FILE *file = fopen("event_log.txt", "r");

    if (file == NULL) {
        printf("\n\tError Opening File!\n");
        exit(1);
    }

    while (fread(&event, sizeof(event_log_t), 1, file)) {
        printf("\t%d\t\t%s\t\t%s\n", event.event_id, event.details, event.timestamp);
    }

    fclose(file);
}


// Clears the Event Logs
void clear_logs() {
    FILE *file = fopen("event_log.txt", "w");
    fclose(file);
}