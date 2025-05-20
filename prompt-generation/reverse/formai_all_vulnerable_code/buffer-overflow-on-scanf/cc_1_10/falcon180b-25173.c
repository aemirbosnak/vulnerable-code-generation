//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 1000
#define MAX_EVENTS 100

struct event {
    int time;
    int type;
    int data;
};

int main() {
    srand(time(NULL));

    struct event events[MAX_EVENTS];
    int num_events = 0;

    int current_time = 0;
    int player_time = 0;

    while (1) {
        printf("Current time: %d\n", current_time);
        printf("Your time: %d\n", player_time);

        int choice;
        printf("What do you want to do?\n");
        printf("1. Travel forward in time\n");
        printf("2. Travel backward in time\n");
        printf("3. Create an event\n");
        printf("4. View events\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            current_time += rand() % 100 + 1;
            player_time = current_time;
            break;
        case 2:
            current_time -= rand() % 100 + 1;
            player_time = current_time;
            break;
        case 3:
            if (num_events >= MAX_EVENTS) {
                printf("Too many events!\n");
            } else {
                events[num_events].time = current_time + rand() % 100 + 1;
                events[num_events].type = rand() % 2;
                events[num_events].data = rand() % 100;
                num_events++;
            }
            break;
        case 4:
            for (int i = 0; i < num_events; i++) {
                printf("Event %d:\n", i);
                printf("Time: %d\n", events[i].time);
                printf("Type: %s\n", events[i].type? "forward" : "backward");
                printf("Data: %d\n", events[i].data);
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}