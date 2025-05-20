//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_PASSENGERS 100  
#define NUM_BAGGAGE_CAROUSELS 5 
#define MAX_BAGGAGE_PER_PASSENGER 3 
#define MAX_WAIT_TIME 10 

pthread_t passengers[NUM_PASSENGERS]; 
pthread_t baggage_carousels[NUM_BAGGAGE_CAROUSELS]; 

int bags[NUM_PASSENGERS][MAX_BAGGAGE_PER_PASSENGER]; 

void *passenger_thread(void *arg) {
    int id = *(int*) arg; 
    printf("Passenger %d has arrived at the airport.\n", id);

    srand(time(NULL) * id); 
    int num_bags = rand() % MAX_BAGGAGE_PER_PASSENGER + 1; 
    for (int i = 0; i < num_bags; i++) {
        bags[id][i] = rand() % 1000 + 1; 
        printf("Passenger %d has checked in bag %d.\n", id, bags[id][i]);
    }

    int wait_time = rand() % MAX_WAIT_TIME + 1; 
    printf("Passenger %d is waiting for %d seconds.\n", id, wait_time);
    sleep(wait_time);

    printf("Passenger %d has picked up their bags and left the airport.\n", id);
    pthread_exit(NULL);
}

void *baggage_carousel_thread(void *arg) {
    int id = *(int*) arg; 
    printf("Baggage Carousel %d has started running.\n", id);

    int curr_bag = 0; 
    while (curr_bag < MAX_BAGGAGE_PER_PASSENGER * NUM_PASSENGERS) {
        for (int i = 0; i < NUM_PASSENGERS; i++) {
            for (int j = 0; j < MAX_BAGGAGE_PER_PASSENGER; j++) {
                if (bags[i][j] > 0 && bags[i][j] / 100 == id) {
                    curr_bag++; 
                    printf("Baggage Carousel %d is handling bag %d for Passenger %d.\n", id, bags[i][j], i);
                    bags[i][j] = -1; 
                }
            }
        }
    }

    printf("Baggage Carousel %d has finished running.\n", id);
    pthread_exit(NULL);
}

int main() {
    int passenger_ids[NUM_PASSENGERS]; 
    int baggage_carousel_ids[NUM_BAGGAGE_CAROUSELS]; 

    for (int i = 0; i < NUM_PASSENGERS; i++) {
        passenger_ids[i] = i; 
        pthread_create(&passengers[i], NULL, passenger_thread, &passenger_ids[i]);
    }

    for (int i = 0; i < NUM_BAGGAGE_CAROUSELS; i++) {
        baggage_carousel_ids[i] = i; 
        pthread_create(&baggage_carousels[i], NULL, baggage_carousel_thread, &baggage_carousel_ids[i]);
    }

    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_join(passengers[i], NULL); 
    }

    for (int i = 0; i < NUM_BAGGAGE_CAROUSELS; i++) {
        pthread_join(baggage_carousels[i], NULL); 
    }

    return 0; 
}