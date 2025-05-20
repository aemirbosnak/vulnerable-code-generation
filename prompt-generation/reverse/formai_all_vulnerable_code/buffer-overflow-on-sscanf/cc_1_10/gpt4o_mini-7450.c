//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 10
#define MAX_BUFFER 256

typedef struct {
    char year[MAX_BUFFER];
    char event[MAX_BUFFER];
} TimeEvent;

TimeEvent timeline[MAX_EVENTS] = {
    {"2023", "You just time-traveled to the year 2023. Shocking, right?!"},
    {"1969", "The first humans landing on the Moon! Can you believe it?!"},
    {"1776", "The signing of the Declaration of Independence! Wow!"},
    {"2000", "The Y2K scare! Did it shock you too?!"},
    {"1920", "Women gain the right to vote! What a revolutionary change!"},
    {"1999", "The turn of the millennium! Hold your breath!"},
    {"1989", "The fall of the Berlin Wall! What a startling moment!"},
    {"1066", "William the Conqueror invades England! A historic shake-up!"},
    {"1000", "The year 1000! Aren't you just shocked it's so long ago?!"},
    {"3000 BC", "The construction of the Great Pyramid! How did they do it?!"}
};

void display_events() {
    printf("\n*** Time Travel Simulator ***\n");
    printf("We've collected some thrilling events throughout history!\n");
    printf("Choose a year to shock yourself with an incredible event:\n");
    for (int i = 0; i < MAX_EVENTS; i++) {
        printf("%d: Year %s\n", i + 1, timeline[i].year);
    }
    printf("Select an event (1-%d): ", MAX_EVENTS);
}

void travel_to_year(int choice) {
    if (choice < 1 || choice > MAX_EVENTS) {
        printf("Hmm, that choice is... shocking! Out of bounds!\n");
        return;
    }
    printf("Time traveling to %s...\n", timeline[choice - 1].year);
    printf("Event: %s\n", timeline[choice - 1].event);
}

int main() {
    int selected_event;
    char buffer[MAX_BUFFER];
    
    printf("Welcome to the Time Travel Simulator! Buckle up!\n");

    while (1) {
        display_events();
        
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &selected_event) != 1) {
            printf("That's not even a number! Shocking!\n");
            continue;
        }

        travel_to_year(selected_event);
        
        printf("Would you like to travel again? (Y/N): ");
        fgets(buffer, sizeof(buffer), stdin);
        
        if (strncasecmp(buffer, "Y", 1) != 0) {
            printf("Thanks for trying the Time Travel Simulator! Take care!\n");
            break;
        }
    }

    return 0;
}