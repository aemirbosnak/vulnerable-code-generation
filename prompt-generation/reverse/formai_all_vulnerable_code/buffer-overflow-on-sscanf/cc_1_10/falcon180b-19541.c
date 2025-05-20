//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EVENTS 1000
#define MAX_FILE_NAME 100

typedef struct {
    char *ip_address;
    char *event;
    time_t timestamp;
} Event;

void add_event(Event *events, int count, char *ip_address, char *event) {
    if (count >= MAX_EVENTS) {
        printf("Event buffer is full. Dropping event.\n");
        return;
    }

    events[count].ip_address = strdup(ip_address);
    events[count].event = strdup(event);
    events[count].timestamp = time(NULL);

    printf("Added event: %s - %s - %s\n", events[count].ip_address, events[count].event, ctime(&events[count].timestamp));
    count++;
}

void print_events(Event *events, int count) {
    printf("\nEvent log:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s - %s\n", i + 1, events[i].ip_address, events[i].event, ctime(&events[i].timestamp));
    }
}

int main() {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];
    char ip_address[MAX_LINE_LENGTH];
    char event[MAX_LINE_LENGTH];
    Event events[MAX_EVENTS];
    int event_count = 0;

    log_file = fopen("intrusion_detection.log", "a");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        if (sscanf(line, "%s - %s", ip_address, event) == 2) {
            add_event(events, event_count, ip_address, event);
        }
    }

    fclose(log_file);

    print_events(events, event_count);

    return 0;
}