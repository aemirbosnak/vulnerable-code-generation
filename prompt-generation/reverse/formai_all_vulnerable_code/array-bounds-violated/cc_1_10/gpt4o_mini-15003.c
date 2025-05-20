//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_TRAVELERS 5
#define MAX_TIMELINES 10

// Define a structure for the time travelers
typedef struct {
    int id;
    int current_time;
} TimeTraveler;

void* travel(void* arg) {
    TimeTraveler* traveler = (TimeTraveler*)arg;
    int time_visited[MAX_TIMELINES] = {0};

    srand(time(NULL) ^ traveler->id); // Seed random number with traveler id
    int time_count = 0;

    while (time_count < MAX_TIMELINES) {
        int new_time = rand() % 100; // Random time period between 0 and 99
        if (time_visited[new_time] == 0) { // Ensure each time period is unique
            time_visited[new_time] = 1; // Mark this time period as visited
            traveler->current_time = new_time; // Update current time for traveler

            printf("Time Traveler %d traveled to year %d\n", traveler->id, traveler->current_time);
            time_count++;
            sleep(1); // Simulate the time travel duration
        }
    }

    printf("Time Traveler %d completed their journey through timelines.\n", traveler->id);
    pthread_exit(NULL);
}

int main() {
    pthread_t travelers[NUM_TRAVELERS];
    TimeTraveler time_travelers[NUM_TRAVELERS];

    // Create time travelers
    for (int i = 0; i < NUM_TRAVELERS; i++) {
        time_travelers[i].id = i + 1;
        time_travelers[i].current_time = 0;
        pthread_create(&travelers[i], NULL, travel, (void*)&time_travelers[i]);
    }

    // Wait for all travelers to finish
    for (int i = 0; i < NUM_TRAVELERS; i++) {
        pthread_join(travelers[i], NULL);
    }

    printf("All time travelers have completed their journeys.\n");
    return 0;
}