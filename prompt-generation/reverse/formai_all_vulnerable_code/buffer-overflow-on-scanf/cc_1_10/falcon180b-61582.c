//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 10

typedef struct {
    int id;
    int destination_year;
} TimeTraveler;

void *time_travel(void *arg) {
    TimeTraveler *traveler = (TimeTraveler *) arg;
    int current_year = 2022;

    while (current_year!= traveler->destination_year) {
        printf("Time traveler %d is currently in the year %d\n", traveler->id, current_year);
        sleep(1);
        current_year++;
    }

    printf("Time traveler %d has arrived in the year %d\n", traveler->id, traveler->destination_year);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_TIME_TRAVELERS];
    TimeTraveler travelers[MAX_TIME_TRAVELERS];

    int num_travelers = 0;

    while (num_travelers < MAX_TIME_TRAVELERS) {
        printf("Enter the ID of a time traveler (0 to quit): ");
        scanf("%d", &travelers[num_travelers].id);

        if (travelers[num_travelers].id == 0) {
            break;
        }

        printf("Enter the destination year for time traveler %d: ", travelers[num_travelers].id);
        scanf("%d", &travelers[num_travelers].destination_year);

        num_travelers++;
    }

    for (int i = 0; i < num_travelers; i++) {
        pthread_create(&threads[i], NULL, time_travel, (void *) &travelers[i]);
    }

    for (int i = 0; i < num_travelers; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}