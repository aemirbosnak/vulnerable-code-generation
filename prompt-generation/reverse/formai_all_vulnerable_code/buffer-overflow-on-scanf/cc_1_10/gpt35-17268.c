//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAXEVENTS 1000
#define EVENTSIZE 100

char events_log[MAXEVENTS][EVENTSIZE];
int event_counter = 0;

void log_event(char* event, char* user, char* timestamp)
{
    char log_entry[EVENTSIZE];
    sprintf(log_entry, "%s - User %s did %s at %s", timestamp, user, event, timestamp);
    strcpy(events_log[event_counter++], log_entry);

    if(event_counter == MAXEVENTS) {
        printf("Event Log is full");
    }
}

void display_events()
{
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("Event Log\n");
    printf("-------------------------------------------------------------------------------------------------\n\n");

    for(int i=0; i<event_counter; i++) {
        printf("%s\n", events_log[i]);
    }
}

int main()
{
    char user[20];
    char event[EVENTSIZE];
    char timestamp[30];
    time_t t;
    time(&t);

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&t));

    printf("Enter your username: ");
    scanf("%s", user);

    printf("\nType your event here: ");
    scanf(" %[^\n]", event);

    log_event(event, user, timestamp);

    display_events();
    
    return 0;
}