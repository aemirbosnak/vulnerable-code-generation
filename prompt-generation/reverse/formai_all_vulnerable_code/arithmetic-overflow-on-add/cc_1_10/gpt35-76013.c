//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAGGAGE_CAPACITY 100
#define MAX_BAGGAGE_HANDLERS 5
#define MAX_FLIGHTS 10
#define MAX_DELAY_TIME 30

typedef struct {
    int flight_number;
    int number_of_bags;
} Flight;

typedef struct {
    int num_bags_handled;
    int time_sleeping;
    int baggage_array[BAGGAGE_CAPACITY];
} BaggageHandler;

void delay(int seconds) {
    int mili_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + mili_seconds);
}

int main() {
    srand(time(NULL));
    int num_flights = rand() % MAX_FLIGHTS + 1;
    Flight flights[num_flights];
    for (int i=0; i<num_flights; i++) {
        flights[i].flight_number = i+1;
        flights[i].number_of_bags = rand() % BAGGAGE_CAPACITY + 1;
    }
    int num_baggage_handlers = rand() % MAX_BAGGAGE_HANDLERS + 1;
    BaggageHandler handlers[num_baggage_handlers];
    for (int i=0; i<num_baggage_handlers; i++) {
        handlers[i].num_bags_handled = 0;
        handlers[i].time_sleeping = 0;
    }
    printf("Welcome to the airport baggage handling simulation!\n");
    printf("There are %d flights today\n", num_flights);
    printf("There are %d baggage handlers available\n", num_baggage_handlers);
    printf("Let's get started!\n\n");
    int current_flight = 0;
    while (current_flight < num_flights) {
        printf("Flight %d arrived at the airport with %d bags.\n", flights[current_flight].flight_number, flights[current_flight].number_of_bags);
        for (int i=0; i<flights[current_flight].number_of_bags; i++) {
            int handler_index = rand() % num_baggage_handlers;
            while (handlers[handler_index].num_bags_handled == BAGGAGE_CAPACITY) {
                printf("Baggage handler %d is currently at full capacity! Checking next handler...\n", handler_index+1);
                handler_index++;
                if (handler_index == num_baggage_handlers) {
                    handler_index = 0;
                }
            }
            handlers[handler_index].baggage_array[handlers[handler_index].num_bags_handled] = i+1;
            handlers[handler_index].num_bags_handled++;
            printf("Bag %d from flight %d has been loaded onto baggage handler %d!\n", i+1, flights[current_flight].flight_number, handler_index+1);
            int delay_time = rand() % MAX_DELAY_TIME;
            handlers[handler_index].time_sleeping += delay_time;
            delay(delay_time);
        }
        printf("\nAll bags from flight %d have been loaded onto baggage handlers.\n", flights[current_flight].flight_number);
        current_flight++;
    }
    printf("\nAll flights have been handled! Summary report:\n");
    for (int i=0; i<num_baggage_handlers; i++) {
        printf("Baggage handler %d handled %d bags and was delayed for a total of %d seconds.\n", i+1, handlers[i].num_bags_handled, handlers[i].time_sleeping);
    }
    return 0;
}