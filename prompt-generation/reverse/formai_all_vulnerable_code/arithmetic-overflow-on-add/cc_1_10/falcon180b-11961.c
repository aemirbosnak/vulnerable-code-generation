//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100

struct time_travel {
    time_t timestamp;
    int duration;
    struct time_travel *next;
};

struct time_travel *time_travels = NULL;
int num_time_travels = 0;

void add_time_travel(time_t timestamp, int duration) {
    struct time_travel *new_time_travel = malloc(sizeof(struct time_travel));
    new_time_travel->timestamp = timestamp;
    new_time_travel->duration = duration;
    new_time_travel->next = NULL;

    if (time_travels == NULL) {
        time_travels = new_time_travel;
    } else {
        struct time_travel *last_time_travel = time_travels;
        while (last_time_travel->next!= NULL) {
            last_time_travel = last_time_travel->next;
        }
        last_time_travel->next = new_time_travel;
    }

    num_time_travels++;
}

void print_time_travels() {
    printf("Total time travels: %d\n", num_time_travels);

    struct time_travel *current_time_travel = time_travels;
    while (current_time_travel!= NULL) {
        printf("Timestamp: %ld, Duration: %d\n", current_time_travel->timestamp, current_time_travel->duration);
        current_time_travel = current_time_travel->next;
    }
}

void time_travel(time_t target_timestamp) {
    if (num_time_travels == 0) {
        printf("No previous time travels.\n");
        return;
    }

    struct time_travel *last_time_travel = time_travels;
    while (last_time_travel->next!= NULL) {
        last_time_travel = last_time_travel->next;
    }

    time_t current_timestamp = time(NULL);
    int duration = difftime(target_timestamp, current_timestamp);

    if (duration <= 0) {
        printf("Cannot travel to the past.\n");
        return;
    }

    add_time_travel(target_timestamp, duration);

    printf("Time traveling to %ld...\n", target_timestamp);
    sleep(duration);

    printf("Arrived at %ld.\n", target_timestamp);
}

int main() {
    time_t current_timestamp = time(NULL);

    add_time_travel(current_timestamp, 0);

    time_travel(current_timestamp + 3600);

    print_time_travels();

    return 0;
}