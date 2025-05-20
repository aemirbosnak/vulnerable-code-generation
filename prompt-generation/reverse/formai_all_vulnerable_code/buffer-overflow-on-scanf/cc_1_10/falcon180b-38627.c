//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 50
#define MAX_EVENT_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_EVENT_NAME_LENGTH];
    char description[MAX_EVENT_DESCRIPTION_LENGTH];
    int probability;
} Event;

int num_events;
Event events[MAX_EVENTS];

void generate_events() {
    srand(time(NULL));

    num_events = rand() % MAX_EVENTS + 1;

    for (int i = 0; i < num_events; i++) {
        events[i].probability = rand() % 101;
        sprintf(events[i].name, "Event %d", i + 1);
        sprintf(events[i].description, "This is event %d. Its probability is %d%%.", i + 1, events[i].probability);
    }
}

int main() {
    generate_events();

    int player_x = 0;
    int player_y = 0;

    while (1) {
        system("clear");

        printf("You are in space at coordinates (%d, %d).\n", player_x, player_y);

        int event_index = rand() % num_events;
        if (events[event_index].probability > rand() % 101) {
            printf("\nAn event has occurred:\n");
            printf("Name: %s\n", events[event_index].name);
            printf("Description: %s\n", events[event_index].description);
        }

        char move;
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                player_y--;
                break;
            case's':
                player_y++;
                break;
            case 'a':
                player_x--;
                break;
            case 'd':
                player_x++;
                break;
            default:
                printf("Invalid move.\n");
        }
    }

    return 0;
}