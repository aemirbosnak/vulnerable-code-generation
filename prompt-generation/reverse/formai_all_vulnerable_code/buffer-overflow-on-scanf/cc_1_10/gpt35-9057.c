//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_IP_LENGTH 20
#define MAX_MESSAGE_LENGTH 100

typedef struct Event {
    char ip[MAX_IP_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Event;

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;
    int i;

    printf("Welcome to the Intrusion Detection System.\n\n");

    while (1) {
        // Simulate an event occurring
        Event event;
        printf("Enter IP address of event: ");
        scanf("%s", event.ip);
        printf("Enter message for event: ");
        scanf("%s", event.message);

        // Add event to array of events
        events[num_events] = event;
        num_events++;

        // Check if there are too many events
        if (num_events > MAX_EVENTS) {
            printf("Too many events, clearing array.\n\n");
            num_events = 0;
            memset(events, 0, sizeof(events));
        }

        // Check for suspicious behavior
        if (num_events > 2
                && strcmp(events[num_events - 1].ip, events[num_events - 3].ip) == 0
                && strcmp(events[num_events - 1].message, events[num_events - 3].message) == 0) {
            printf("Possible intrusion detected! IP address: %s, message: %s\n\n",
                   events[num_events - 1].ip, events[num_events - 1].message);
        }

        // Print current events
        printf("Current events:\n");
        for (i = 0; i < num_events; i++) {
            printf("%s - %s\n", events[i].ip, events[i].message);
        }
        printf("\n");
    }

    return 0;
}