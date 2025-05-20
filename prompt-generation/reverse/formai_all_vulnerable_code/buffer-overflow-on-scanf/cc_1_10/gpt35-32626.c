//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Event Event;
struct Event {
    char* name;
    char* date;
};

#define MAX_EVENTS 100
Event events[MAX_EVENTS];
int events_count = 0;

void add_event(char* name, char* date) {
    if(events_count == MAX_EVENTS) {
        printf("Sorry, cannot add any more events.\n");
        return;
    }

    events[events_count].name = name;
    events[events_count].date = date;
    printf("An event has been added: %s on %s.\n", name, date);
    events_count++;
}

void print_events() {
    if(events_count == 0) {
        printf("There are no events to show.\n");
        return;
    }

    printf("Here are all the events:\n");
    for(int i=0; i<events_count; i++) {
        printf("%d. %s on %s.\n", i+1, events[i].name, events[i].date);
    }
}

int main() {
    printf("Welcome explorer, to the Medieval Digital Diary.\n");
    printf("We will record all your events and help you remember them.\n");

    while(1) {
        printf("Please choose an option (1-3):\n");
        printf("1. Add an event.\n");
        printf("2. Show all events.\n");
        printf("3. Exit.\n");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            printf("What is the name of the event?\n");
            char* name = malloc(100);
            scanf("%s", name);

            printf("What is the date of the event?\n");
            char* date = malloc(20);
            scanf("%s", date);

            add_event(name, date);
        } else if(choice == 2) {
            print_events();
        } else if(choice == 3) {
            printf("Farewell, explorer.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}