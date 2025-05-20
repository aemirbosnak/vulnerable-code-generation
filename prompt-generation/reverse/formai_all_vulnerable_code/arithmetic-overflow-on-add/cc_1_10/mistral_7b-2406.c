//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME_TRAVELERS 100
#define TIME_TRAVEL_DELTA 86400 // 1 day in seconds

typedef struct TimeTraveler {
    char name[50];
    time_t travel_time;
} TimeTraveler;

TimeTraveler time_travelers[MAX_TIME_TRAVELERS];
int num_time_travelers = 0;

void travel_back_in_time(TimeTraveler* traveler, time_t travel_time) {
    if (difftime(travel_time, traveler->travel_time) > TIME_TRAVEL_DELTA) {
        perror("Time Traveler cannot go back in time more than a day.");
        return;
    }

    traveler->travel_time = travel_time;
}

void print_time_travelers() {
    printf("Current Time Travelers:\n");
    for (int i = 0; i < num_time_travelers; i++) {
        printf("%s traveled to %s\n", time_travelers[i].name, ctime(&time_travelers[i].travel_time));
    }
}

int main() {
    srand(time(NULL));

    while (num_time_travelers < 5) {
        TimeTraveler new_traveler;
        strcpy(new_traveler.name, "Time Traveler");
        new_traveler.travel_time = time(NULL) - rand() % (2 * TIME_TRAVEL_DELTA);

        travel_back_in_time(&new_traveler, new_traveler.travel_time);

        for (int i = 0; i < num_time_travelers; i++) {
            if (difftime(new_traveler.travel_time, time_travelers[i].travel_time) < TIME_TRAVEL_DELTA) {
                printf("Time Traveler %s conflicts with existing traveler %s.\n", new_traveler.name, time_travelers[i].name);
                travel_back_in_time(&new_traveler, new_traveler.travel_time + TIME_TRAVEL_DELTA);
                break;
            }
        }

        time_travelers[num_time_travelers++] = new_traveler;
    }

    print_time_travelers();

    return 0;
}