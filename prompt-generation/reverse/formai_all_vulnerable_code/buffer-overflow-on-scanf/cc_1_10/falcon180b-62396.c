//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVEL 100
#define TIME_STEP 1
#define MAX_TIME 100

struct time_travel {
    int time;
    int destination;
    struct time_travel *next;
};

struct time_travel *time_travel_list = NULL;
int time_travel_count = 0;

void add_time_travel(int time, int destination) {
    struct time_travel *new_time_travel = (struct time_travel *)malloc(sizeof(struct time_travel));
    if (new_time_travel == NULL) {
        printf("Error: Could not allocate memory for new time travel.\n");
        exit(1);
    }
    new_time_travel->time = time;
    new_time_travel->destination = destination;
    new_time_travel->next = NULL;
    if (time_travel_list == NULL) {
        time_travel_list = new_time_travel;
    } else {
        struct time_travel *temp_time_travel = time_travel_list;
        while (temp_time_travel->next!= NULL) {
            temp_time_travel = temp_time_travel->next;
        }
        temp_time_travel->next = new_time_travel;
    }
    time_travel_count++;
}

void print_time_travel_list() {
    struct time_travel *temp_time_travel = time_travel_list;
    printf("Time travel list:\n");
    while (temp_time_travel!= NULL) {
        printf("Time: %d, Destination: %d\n", temp_time_travel->time, temp_time_travel->destination);
        temp_time_travel = temp_time_travel->next;
    }
}

void time_travel() {
    int time = 0;
    int destination = 0;
    int choice;
    do {
        printf("Enter time travel destination (0 to exit): ");
        scanf("%d", &destination);
        if (destination == 0) {
            break;
        }
        add_time_travel(time, destination);
        time += TIME_STEP;
    } while (time <= MAX_TIME);
    printf("Time travel destinations:\n");
    print_time_travel_list();
}

int main() {
    srand(time(NULL));
    int seed;
    printf("Enter seed for random number generator: ");
    scanf("%d", &seed);
    srand(seed);
    time_travel();
    return 0;
}