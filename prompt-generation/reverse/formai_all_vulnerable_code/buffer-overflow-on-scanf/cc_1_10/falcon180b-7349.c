//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 100
#define MAX_TIME_TRAVEL_DISTANCE 1000

typedef struct {
    int id;
    char name[50];
    int distance;
    int time;
} TimeTraveler;

void print_traveler(TimeTraveler traveler) {
    printf("ID: %d\nName: %s\nDistance: %d\nTime: %d\n", traveler.id, traveler.name, traveler.distance, traveler.time);
}

int main() {
    int num_travelers;
    printf("Enter the number of time travelers: ");
    scanf("%d", &num_travelers);

    TimeTraveler travelers[MAX_TIME_TRAVELERS];
    for (int i = 0; i < num_travelers; i++) {
        printf("Enter the details for traveler %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &travelers[i].id);
        printf("Name: ");
        scanf("%s", travelers[i].name);
        printf("Distance: ");
        scanf("%d", &travelers[i].distance);
        printf("Time: ");
        scanf("%d", &travelers[i].time);
    }

    int max_distance = 0;
    for (int i = 0; i < num_travelers; i++) {
        if (travelers[i].distance > max_distance) {
            max_distance = travelers[i].distance;
        }
    }

    int max_time = 0;
    for (int i = 0; i < num_travelers; i++) {
        if (travelers[i].time > max_time) {
            max_time = travelers[i].time;
        }
    }

    printf("\nStarting time travel simulation...\n");
    srand(time(NULL));
    int current_time = 0;
    while (current_time < max_time) {
        for (int i = 0; i < num_travelers; i++) {
            if (travelers[i].time == current_time) {
                printf("Traveler %d (%s) traveled %d units at time %d.\n", travelers[i].id, travelers[i].name, travelers[i].distance, current_time);
            }
        }
        current_time++;
    }

    return 0;
}