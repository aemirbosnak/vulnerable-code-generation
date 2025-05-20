//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_NAME_LEN 50
#define EVENT_DATE_LEN 20

typedef struct {
    char name[EVENT_NAME_LEN];
    char date[EVENT_DATE_LEN];
    time_t timestamp;
    int duration;
} Event;

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;
    char input_buffer[100];
    char* token;
    time_t current_time;
    int choice;

    time(&current_time);
    printf("Current time: %s\n", ctime(&current_time));

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add event\n");
        printf("2. Remove event\n");
        printf("3. List events\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter event name: ");
            scanf("%s", input_buffer);
            printf("Enter event date (YYYY-MM-DD): ");
            scanf("%s", input_buffer);
            printf("Enter event duration in minutes: ");
            scanf("%d", &events[num_events].duration);

            strcpy(events[num_events].name, input_buffer);
            strcpy(events[num_events].date, input_buffer);
            events[num_events].timestamp = current_time;
            events[num_events].timestamp += events[num_events].duration * 60;

            num_events++;
            printf("Event added successfully.\n");
            break;

        case 2:
            printf("Enter event name to remove: ");
            scanf("%s", input_buffer);

            for (int i = 0; i < num_events; i++) {
                if (strcmp(events[i].name, input_buffer) == 0) {
                    printf("Event removed successfully.\n");
                    num_events--;
                    break;
                }
            }

            break;

        case 3:
            if (num_events == 0) {
                printf("No events scheduled.\n");
            } else {
                printf("List of events:\n");
                for (int i = 0; i < num_events; i++) {
                    printf("Name: %s\nDate: %s\nDuration: %d minutes\n", events[i].name, events[i].date, events[i].duration);
                }
            }

            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}