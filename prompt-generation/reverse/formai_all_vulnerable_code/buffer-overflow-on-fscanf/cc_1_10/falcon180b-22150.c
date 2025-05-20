//Falcon-180B DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_EVENTS 1000
#define EVENT_FILE "events.log"

typedef struct {
    time_t timestamp;
    char event[100];
} Event;

int main() {
    FILE *event_file;
    int event_count = 0;
    Event events[MAX_EVENTS];

    event_file = fopen(EVENT_FILE, "a+");
    if (event_file == NULL) {
        printf("Error opening event file.\n");
        return 1;
    }

    // Read existing events from file
    rewind(event_file);
    while (fscanf(event_file, "%s %ld\n", events[event_count].event, &events[event_count].timestamp)!= EOF) {
        event_count++;
    }

    int choice;
    do {
        printf("1. Log event\n2. View event log\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter event: ");
                scanf("%s", events[event_count].event);
                events[event_count].timestamp = time(NULL);
                fprintf(event_file, "%s %ld\n", events[event_count].event, events[event_count].timestamp);
                event_count++;
                break;
            case 2:
                printf("\nEvent log:\n");
                for (int i = 0; i < event_count; i++) {
                    printf("%s %s\n", ctime(&events[i].timestamp), events[i].event);
                }
                break;
            case 3:
                fclose(event_file);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
}