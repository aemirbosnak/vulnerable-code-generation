//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 5
#define BUFFER_SIZE 256

typedef struct {
    char name[BUFFER_SIZE];
    char year[BUFFER_SIZE];
    char description[BUFFER_SIZE];
} TimeEvent;

void displayEvents(TimeEvent events[], int count) {
    printf("Available Time Travel Events:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s (%s)\n", i + 1, events[i].name, events[i].year);
    }
}

void travelToEvent(TimeEvent event) {
    printf("Traveling to %s in the year %s...\n", event.name, event.year);
    printf("Description: %s\n", event.description);
    printf("You have arrived at %s!\n", event.name);
}

int main() {
    TimeEvent events[MAX_EVENTS] = {
        {"Moon Landing", "1969", "Humans landed on the moon for the first time."},
        {"Fall of the Berlin Wall", "1989", "The wall that divided East and West Berlin fell."},
        {"Invention of the Internet", "1960s", "The creation of a network that revolutionized communication."},
        {"Signing of the Declaration of Independence", "1776", "The thirteen colonies declared independence from Britain."},
        {"First Man in Space", "1961", "Yuri Gagarin becomes the first human to journey into outer space."}
    };

    int choice;
    while (1) {
        displayEvents(events, MAX_EVENTS);
        printf("Enter the number of the event to travel to (0 to quit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
            break;
        } else if (choice > 0 && choice <= MAX_EVENTS) {
            travelToEvent(events[choice - 1]);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}