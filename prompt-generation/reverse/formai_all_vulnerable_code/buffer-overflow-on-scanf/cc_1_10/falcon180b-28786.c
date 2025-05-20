//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TIMESTAMPS 1000
#define TIMESTAMP_SIZE 20

typedef struct {
    char timestamp[TIMESTAMP_SIZE];
    int index;
} Timestamp;

Timestamp *timestamps;
int num_timestamps;

void init_timestamps() {
    timestamps = malloc(MAX_TIMESTAMPS * sizeof(Timestamp));
    num_timestamps = 0;
}

void add_timestamp(char *timestamp) {
    Timestamp *new_timestamps = realloc(timestamps, (num_timestamps + 1) * sizeof(Timestamp));
    if (new_timestamps == NULL) {
        printf("Error: Unable to add timestamp.\n");
        exit(1);
    }
    timestamps = new_timestamps;
    strncpy(timestamps[num_timestamps].timestamp, timestamp, TIMESTAMP_SIZE);
    timestamps[num_timestamps].index = num_timestamps;
    num_timestamps++;
}

void print_timestamps() {
    for (int i = 0; i < num_timestamps; i++) {
        printf("%s (%d)\n", timestamps[i].timestamp, i);
    }
}

void travel_to_timestamp(char *timestamp) {
    for (int i = 0; i < num_timestamps; i++) {
        if (strcmp(timestamps[i].timestamp, timestamp) == 0) {
            printf("Traveling to timestamp %s (%d)...\n", timestamp, i);
            // TODO: Implement time travel logic here
            break;
        }
    }
}

int main() {
    init_timestamps();

    char input[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char timestamp[TIMESTAMP_SIZE];
            printf("Enter timestamp: ");
            scanf("%s", timestamp);
            add_timestamp(timestamp);
        } else if (strcmp(input, "list") == 0) {
            print_timestamps();
        } else if (strcmp(input, "travel") == 0) {
            char timestamp[TIMESTAMP_SIZE];
            printf("Enter timestamp to travel to: ");
            scanf("%s", timestamp);
            travel_to_timestamp(timestamp);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}