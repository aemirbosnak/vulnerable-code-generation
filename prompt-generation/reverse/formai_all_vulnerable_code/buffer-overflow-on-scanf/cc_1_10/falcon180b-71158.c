//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TIME_TRAVEL 1
#define TIME_MACHINE 2
#define TIME_PORTAL 3
#define TIME_DILATION 4
#define TIME_PARADOX 5

typedef struct {
    char *name;
    int type;
    int year;
} TimeTravelEvent;

TimeTravelEvent events[] = {
    {"Invention of the Time Machine", TIME_MACHINE, 2022},
    {"Discovery of Time Portals", TIME_PORTAL, 2030},
    {"First Successful Time Travel", TIME_TRAVEL, 2040},
    {"Detection of Time Dilation", TIME_DILATION, 2050},
    {"Resolution of the Grandfather Paradox", TIME_PARADOX, 2060}
};

int main() {
    int choice;
    int num_events = sizeof(events) / sizeof(events[0]);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose an event:\n");

    for (int i = 0; i < num_events; i++) {
        printf("%d. %s\n", i+1, events[i].name);
    }

    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_events) {
        TimeTravelEvent event = events[choice-1];

        if (event.type == TIME_TRAVEL) {
            printf("You travel back in time to the year %d.\n", event.year);
        } else if (event.type == TIME_MACHINE) {
            printf("You invent a time machine!\n");
        } else if (event.type == TIME_PORTAL) {
            printf("You discover a time portal!\n");
        } else if (event.type == TIME_DILATION) {
            printf("You detect time dilation!\n");
        } else if (event.type == TIME_PARADOX) {
            printf("You resolve the grandfather paradox!\n");
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}