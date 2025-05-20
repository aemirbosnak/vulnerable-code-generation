//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024 /* Maximum length of a line */
#define MAX_EVENTS 100 /* Maximum number of events to store */

typedef struct {
    char *event_type;
    char *ip_address;
    char *timestamp;
} Event;

Event events[MAX_EVENTS]; /* Array to store events */
int num_events = 0; /* Number of events stored */

void add_event(char *event_type, char *ip_address, char *timestamp) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached\n");
        return;
    }
    events[num_events].event_type = strdup(event_type);
    events[num_events].ip_address = strdup(ip_address);
    events[num_events].timestamp = strdup(timestamp);
    num_events++;
}

void print_events() {
    printf("ID\tEvent Type\tIP Address\tTimestamp\n");
    for (int i = 0; i < num_events; i++) {
        printf("%d\t%s\t%s\t%s\n", i + 1, events[i].event_type, events[i].ip_address, events[i].timestamp);
    }
}

int main() {
    char line[MAX_LINE_LEN];
    char event_type[MAX_LINE_LEN];
    char ip_address[MAX_LINE_LEN];
    char *timestamp;
    int i = 0;

    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        if (line[0] == '#') {
            continue; /* Skip comments */
        }
        i++;
        if (i == 1) {
            sscanf(line, "Event Type: %s", event_type);
        } else if (i == 2) {
            sscanf(line, "IP Address: %s", ip_address);
        } else if (i == 3) {
            timestamp = strtok(line, " ");
            add_event(event_type, ip_address, timestamp);
        } else {
            printf("Error: Invalid input\n");
            return 1;
        }
    }
    print_events();
    return 0;
}