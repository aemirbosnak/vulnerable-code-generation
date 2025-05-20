//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_ACTORS 100
#define MAX_CONSPIRACY_EVENTS 1000

typedef struct {
    char name[50];
    int involvement;
} Actor;

typedef struct {
    char description[200];
    int probability;
} Event;

void generate_conspiracy(int num_actors, int num_events) {
    srand(time(NULL));

    Actor actors[MAX_CONSPIRACY_ACTORS];
    for (int i = 0; i < num_actors; i++) {
        actors[i].involvement = rand() % 100;
        sprintf(actors[i].name, "Actor %d", i + 1);
    }

    Event events[MAX_CONSPIRACY_EVENTS];
    for (int i = 0; i < num_events; i++) {
        events[i].probability = rand() % 100;
        sprintf(events[i].description, "Event %d", i + 1);
    }

    int num_links = rand() % (num_actors * num_events) + 1;
    int links[MAX_CONSPIRACY_LENGTH];
    for (int i = 0; i < num_links; i++) {
        int actor_index = rand() % num_actors;
        int event_index = rand() % num_events;
        links[i] = actor_index * num_events + event_index;
    }

    printf("Conspiracy:\n");
    for (int i = 0; i < num_actors; i++) {
        printf("- %s (%d%% involved)\n", actors[i].name, actors[i].involvement);
    }

    for (int i = 0; i < num_events; i++) {
        printf("- %s (%d%% likely)\n", events[i].description, events[i].probability);
    }

    printf("Links:\n");
    for (int i = 0; i < num_links; i++) {
        int actor_index = links[i] / num_events;
        int event_index = links[i] % num_events;
        printf("- %s is linked to %s (%d%% likely)\n", actors[actor_index].name, events[event_index].description, links[i] % 100);
    }
}

int main() {
    int num_actors, num_events;

    printf("Enter the number of actors in the conspiracy (1-100): ");
    scanf("%d", &num_actors);

    printf("Enter the number of events in the conspiracy (1-1000): ");
    scanf("%d", &num_events);

    generate_conspiracy(num_actors, num_events);

    return 0;
}