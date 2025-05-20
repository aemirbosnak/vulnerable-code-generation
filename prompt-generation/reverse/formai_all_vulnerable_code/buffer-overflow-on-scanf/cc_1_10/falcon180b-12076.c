//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 1000

struct event {
    int time;
    char *description;
};

void travel_to_time(int target_time) {
    printf("Traveling to time: %d\n", target_time);
    srand(target_time);
    printf("Arrived at time: %d\n", rand() % MAX_TIME);
}

int main() {
    struct event events[] = {
        {1, "Big Bang"},
        {100, "Formation of Earth"},
        {200, "First life on Earth"},
        {500, "Invention of wheel"},
        {1000, "Viking Age begins"},
        {1500, "Columbus discovers America"},
        {2000, "Y2K panic"},
        {3000, "Humans colonize Mars"},
        {4000, "AI singularity"}
    };

    int num_events = sizeof(events) / sizeof(events[0]);
    int current_time = 0;

    printf("Welcome to the Time Travel Simulator!\n");

    while (current_time < MAX_TIME) {
        printf("Current time: %d\n", current_time);
        for (int i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                printf("Event: %s\n", events[i].description);
            }
        }
        printf("Enter a time to travel to (0 to exit): ");
        scanf("%d", &current_time);
        if (current_time >= 0 && current_time < MAX_TIME) {
            travel_to_time(current_time);
        }
    }

    return 0;
}