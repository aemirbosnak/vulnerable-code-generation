//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: genius
/*
 * Digital Diary
 * A genius-style C program to keep track of your daily events.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 256

struct Event {
    char title[MAX_EVENT_LENGTH];
    char description[MAX_EVENT_LENGTH];
    char date[11];
};

struct Event events[MAX_EVENTS];
int num_events = 0;

void add_event(char *title, char *description, char *date) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    strcpy(events[num_events].title, title);
    strcpy(events[num_events].description, description);
    strcpy(events[num_events].date, date);

    num_events++;
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        printf("%s\n%s\n%s\n\n", events[i].title, events[i].description, events[i].date);
    }
}

int main() {
    char title[MAX_EVENT_LENGTH], description[MAX_EVENT_LENGTH], date[11];

    while (1) {
        printf("Enter the title of the event: ");
        scanf("%s", title);
        printf("Enter the description of the event: ");
        scanf("%s", description);
        printf("Enter the date of the event (DD/MM/YYYY): ");
        scanf("%s", date);

        add_event(title, description, date);

        printf("Add another event? (y/n): ");
        char response;
        scanf(" %c", &response);

        if (response == 'n') {
            break;
        }
    }

    print_events();

    return 0;
}