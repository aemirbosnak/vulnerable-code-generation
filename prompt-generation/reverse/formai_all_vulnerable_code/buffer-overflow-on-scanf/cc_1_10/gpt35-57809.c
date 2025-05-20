//FormAI DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <time.h>

/*
This is a program to log system events in a scalable style.
In this program, we will create a C structure called event.
Event structure will store data and time of the event along with a message describing the event.
The program will accept user input and collect the data in a dynamically allocated array of events.
The event log can then be displayed by the user.
*/

#define MAX_EVENTS 1000 // Maximum number of events that can be logged

// Event structure to store event time, date and message
struct event {
    char date[11];
    char time[6];
    char message[100];
};

int main() {
    struct event* event_log; // Pointer to dynamically allocated array of events
    int event_count = 0; // Number of events logged
    char choice; // User input for choice of operation
    
    // Allocate memory for event log
    event_log = (struct event*) malloc(MAX_EVENTS * sizeof(struct event));
    
    // Display menu to user
    printf("System event logger\n");
    do {
        printf("1. Log an event\n");
        printf("2. Display event log\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                // Log an event
                if (event_count == MAX_EVENTS) {
                    printf("Event log is full!\n");
                } else {
                    struct event new_event;
                    time_t t = time(NULL); // Get current time
                    struct tm* tm = localtime(&t); // Convert to local time
                    // Store event time and date in event struct
                    snprintf(new_event.date, 11, "%04d-%02d-%02d", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);
                    snprintf(new_event.time, 6, "%02d:%02d", tm->tm_hour, tm->tm_min);
                    // Get event message from user
                    printf("Enter event message: ");
                    scanf(" %[^\n]", new_event.message);
                    // Add event to event log
                    event_log[event_count++] = new_event;
                    printf("Event logged!\n");
                }
                break;
                
            case '2':
                // Display event log
                printf("---- Event Log ----\n");
                for (int i = 0; i < event_count; i++) {
                    printf("%s %s - %s\n", event_log[i].date, event_log[i].time, event_log[i].message);
                }
                printf("--------------------\n");
                break;
                
            case '3':
                // Exit
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != '3');
    
    // Free allocated memory
    free(event_log);
    
    return 0;
}