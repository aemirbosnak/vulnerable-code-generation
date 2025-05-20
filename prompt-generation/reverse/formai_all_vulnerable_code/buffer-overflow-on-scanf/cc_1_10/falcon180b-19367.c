//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME 50
#define MAX_EVENT_DESCRIPTION 100

typedef struct {
    char name[MAX_EVENT_NAME];
    char description[MAX_EVENT_DESCRIPTION];
    int start_time;
    int end_time;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    int choice;
    int event_index;

    printf("Welcome to the Shape Shifting Appointment Scheduler!\n");
    printf("Please choose an option:\n");
    printf("1. Add event\n");
    printf("2. View events\n");
    printf("3. Delete event\n");
    printf("4. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_events >= MAX_EVENTS) {
                    printf("Maximum number of events reached!\n");
                } else {
                    printf("Enter event name (max %d characters): ", MAX_EVENT_NAME);
                    scanf("%s", events[num_events].name);

                    printf("Enter event description (max %d characters): ", MAX_EVENT_DESCRIPTION);
                    scanf("%s", events[num_events].description);

                    printf("Enter start time (HH:MM AM/PM): ");
                    scanf("%d:%d %s", &events[num_events].start_time, &events[num_events].start_time, events[num_events].name);

                    printf("Enter end time (HH:MM AM/PM): ");
                    scanf("%d:%d %s", &events[num_events].end_time, &events[num_events].end_time, events[num_events].name);

                    num_events++;
                }
                break;

            case 2:
                printf("Event Name\t\tStart Time\t\tEnd Time\n");
                for (event_index = 0; event_index < num_events; event_index++) {
                    printf("%s\t\t%d:%02d %s\t\t%d:%02d %s\n", events[event_index].name, events[event_index].start_time/100, events[event_index].start_time%100, events[event_index].name, events[event_index].end_time/100, events[event_index].end_time%100);
                }
                break;

            case 3:
                printf("Enter event name to delete: ");
                scanf("%s", events[event_index].name); // assuming event_index is already set

                printf("Event deleted successfully!\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}