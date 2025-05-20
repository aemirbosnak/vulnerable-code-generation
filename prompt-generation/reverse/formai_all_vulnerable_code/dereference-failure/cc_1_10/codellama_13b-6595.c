//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MIN_BAGGAGE 10
#define MAX_TICKETS 50
#define MIN_TICKETS 10

typedef struct {
    int id;
    char name[20];
    char flight[10];
    int ticket_number;
    int baggage_count;
    int baggage_size[MAX_BAGGAGE];
} passenger;

void generate_passengers(passenger *passengers, int num_passengers) {
    int i, j;
    for (i = 0; i < num_passengers; i++) {
        passengers[i].id = i;
        strcpy(passengers[i].name, "John Doe");
        strcpy(passengers[i].flight, "AF001");
        passengers[i].ticket_number = rand() % (MAX_TICKETS - MIN_TICKETS) + MIN_TICKETS;
        passengers[i].baggage_count = rand() % (MAX_BAGGAGE - MIN_BAGGAGE) + MIN_BAGGAGE;
        for (j = 0; j < passengers[i].baggage_count; j++) {
            passengers[i].baggage_size[j] = rand() % (500 - 100) + 100;
        }
    }
}

void print_passengers(passenger *passengers, int num_passengers) {
    int i, j;
    for (i = 0; i < num_passengers; i++) {
        printf("Passenger %d:\n", passengers[i].id);
        printf("Name: %s\n", passengers[i].name);
        printf("Flight: %s\n", passengers[i].flight);
        printf("Ticket Number: %d\n", passengers[i].ticket_number);
        printf("Baggage Count: %d\n", passengers[i].baggage_count);
        for (j = 0; j < passengers[i].baggage_count; j++) {
            printf("Baggage %d: %d kg\n", j, passengers[i].baggage_size[j]);
        }
    }
}

int main() {
    int num_passengers = 50;
    passenger *passengers = malloc(num_passengers * sizeof(passenger));
    generate_passengers(passengers, num_passengers);
    print_passengers(passengers, num_passengers);
    free(passengers);
    return 0;
}