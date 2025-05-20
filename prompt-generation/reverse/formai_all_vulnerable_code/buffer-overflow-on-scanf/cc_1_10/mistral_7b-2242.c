//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Event {
    int timestamp;
    char description[100];
    struct Event *next;
} Event;

Event *current = NULL;
Event *head = NULL;

void print_event() {
    if (current == NULL) {
        printf("No event is currently selected.\n");
        return;
    }

    printf("Event at %d:\n%s\n", current->timestamp, current->description);
}

void travel_back(int steps) {
    while (current != NULL && steps > 0) {
        current = current->next;
        steps--;
    }

    if (current == NULL) {
        printf("Traveled too far back in time.\n");
    }
}

void travel_forward(int steps) {
    Event *temp = current;

    while (temp != NULL && steps > 0) {
        current = current->next;
        temp = current;
        steps--;
    }

    if (current == NULL) {
        printf("Traveled too far forward in time.\n");
        current = temp;
    }
}

void add_event(int timestamp, char *description) {
    Event *new_event = (Event *)malloc(sizeof(Event));

    strcpy(new_event->description, description);
    new_event->timestamp = timestamp;
    new_event->next = head;

    head = new_event;
}

int main() {
    int choice, steps, timestamp;
    char description[100];

    while (1) {
        printf("\nTime Travel Simulator\n");
        printf("1. Add Event\n");
        printf("2. Print Current Event\n");
        printf("3. Travel Back in Time\n");
        printf("4. Travel Forward in Time\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter timestamp: ");
                scanf("%d", &timestamp);
                printf("Enter event description: ");
                scanf("%s", description);
                add_event(timestamp, description);
                break;
            case 2:
                print_event();
                break;
            case 3:
                printf("Enter number of steps to travel back in time: ");
                scanf("%d", &steps);
                travel_back(steps);
                break;
            case 4:
                printf("Enter number of steps to travel forward in time: ");
                scanf("%d", &steps);
                travel_forward(steps);
                break;
            case 5:
                free(current);
                free(head);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}