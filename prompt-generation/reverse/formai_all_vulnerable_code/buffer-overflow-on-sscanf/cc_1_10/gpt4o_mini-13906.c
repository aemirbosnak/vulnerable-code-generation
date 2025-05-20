//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 10
#define MAX_DESCRIPTION 256

typedef struct Event {
    char description[MAX_DESCRIPTION];
    int year;
} Event;

Event timeMachine[MAX_EVENTS];
int event_count = 0;

void add_event(const char *description, int year) {
    if (event_count >= MAX_EVENTS) {
        printf("Unable to add more events. Maximum limit reached.\n");
        return;
    }
    strncpy(timeMachine[event_count].description, description, MAX_DESCRIPTION);
    timeMachine[event_count].year = year;
    event_count++;
}

void view_events() {
    printf("Chronological Events:\n");
    for (int i = 0; i < event_count; i++) {
        printf("%d: %s (%d)\n", i + 1, timeMachine[i].description, timeMachine[i].year);
    }
}

void simulate_time_travel(int destination_year) {
    int closest_year = 0;
    char closest_event[MAX_DESCRIPTION];

    for (int i = 0; i < event_count; i++) {
        if (timeMachine[i].year == destination_year) {
            printf("Time Travel to %d: %s\n", destination_year, timeMachine[i].description);
            return;
        }
        if (timeMachine[i].year < destination_year && 
            (closest_year == 0 || timeMachine[i].year > closest_year)) {
            closest_year = timeMachine[i].year;
            strncpy(closest_event, timeMachine[i].description, MAX_DESCRIPTION);
        }
    }

    if (closest_year > 0) {
        printf("No exact event for %d. Closest event was:\n", destination_year);
        printf("%s (%d)\n", closest_event, closest_year);
    } else {
        printf("No events were found prior to %d.\n", destination_year);
    }
}

void print_help() {
    printf("Sherlock Holmes Time Travel Simulator Help:\n");
    printf("Commands:\n");
    printf("  1. add <description> <year> - Add a historical event.\n");
    printf("  2. view - View all recorded events.\n");
    printf("  3. travel <year> - Attempt to travel to a specified year.\n");
    printf("  4. exit - Exit the simulator.\n");
}

int main() {
    char command[512];
    char description[MAX_DESCRIPTION];
    int year;

    print_help();

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "add ", 4) == 0) {
            if (sscanf(command + 4, "%s %d", description, &year) != 2) {
                printf("Invalid command format. Use: add <description> <year>\n");
            } else {
                add_event(description, year);
                printf("Event added: %s (%d)\n", description, year);
            }
        } 
        else if (strncmp(command, "view", 4) == 0) {
            view_events();
        } 
        else if (strncmp(command, "travel ", 7) == 0) {
            if (sscanf(command + 7, "%d", &year) != 1) {
                printf("Invalid command format. Use: travel <year>\n");
            } else {
                simulate_time_travel(year);
            }
        } 
        else if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting the Time Travel Simulator. Farewell!\n");
            break;
        } 
        else {
            printf("Unknown command. Type 'help' for options.\n");
        }
    }

    return 0;
}