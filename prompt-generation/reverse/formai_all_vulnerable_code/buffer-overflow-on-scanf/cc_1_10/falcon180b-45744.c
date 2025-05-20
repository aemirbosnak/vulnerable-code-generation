//Falcon-180B DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_MSG_LEN 512

// Struct to hold event details
typedef struct {
    char msg[MAX_MSG_LEN];
    time_t timestamp;
} Event;

// Function to log an event
void log_event(const char* msg) {
    Event evt;
    time_t now = time(NULL);
    strncpy(evt.msg, msg, MAX_MSG_LEN-1);
    evt.msg[MAX_MSG_LEN-1] = '\0';
    evt.timestamp = now;
    printf("Event logged: %s\n", msg);
}

// Function to display all logged events
void display_events() {
    FILE* fp;
    Event evt;
    char filename[20];
    sprintf(filename, "events.log");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("No events logged yet.\n");
        return;
    }
    while (fread(&evt, sizeof(Event), 1, fp) == 1) {
        printf("%s - %s\n", ctime(&evt.timestamp), evt.msg);
    }
    fclose(fp);
}

// Main function
int main() {
    int choice;
    char input[MAX_MSG_LEN];

    while (1) {
        printf("\nEvent Logger\n");
        printf("1. Log an event\n");
        printf("2. Display events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the event message: ");
                fgets(input, MAX_MSG_LEN, stdin);
                log_event(input);
                break;
            case 2:
                display_events();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}