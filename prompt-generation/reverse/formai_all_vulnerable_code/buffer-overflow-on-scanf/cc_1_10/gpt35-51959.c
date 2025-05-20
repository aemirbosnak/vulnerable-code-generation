//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLIGHTS 10
#define MAX_BAGS 50
#define MAX_CAPACITY 100

// Baggage struct
typedef struct Baggage {
    int id;
    int weight;
    struct tm arrival_time;
} Baggage;

// Flight struct
typedef struct Flight {
    int id;
    int capacity;
    Baggage bags[MAX_BAGS];
    int num_bags;
} Flight;

// Function prototypes
void add_bag_to_flight(Baggage* bag, Flight* flight);
void print_bag(Baggage* bag);
void print_flight(Flight* flight);

int main()
{
    srand(time(NULL));
    Flight flights[MAX_FLIGHTS];
    int num_flights = 0;

    printf("Welcome to the Baggage Handling Simulation!\n");

    while (1) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Add a Flight\n");
        printf("2. Add a Baggage\n");
        printf("3. Print Flights\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_flights < MAX_FLIGHTS) {
                Flight flight;
                flight.id = num_flights + 1;
                flight.capacity = rand() % MAX_CAPACITY + 1;
                flight.num_bags = 0;
                flights[num_flights] = flight;
                num_flights++;
                printf("Flight %d added. Capacity: %d\n", flight.id, flight.capacity);
            } else {
                printf("Sorry, the maximum number of flights has been reached.\n");
            }
        } else if (choice == 2) {
            if (num_flights == 0) {
                printf("Sorry, no flights created yet.\n");
            } else {
                int flight_choice;
                printf("Which flight would you like to add the baggage to?\n");
                for (int i = 0; i < num_flights; i++) {
                    printf("%d. Flight %d\n", i+1, flights[i].id);
                }
                printf("> ");
                scanf("%d", &flight_choice);

                if (flight_choice < 1 || flight_choice > num_flights) {
                    printf("Sorry, invalid choice.\n");
                } else {
                    Baggage bag;
                    bag.id = flights[flight_choice-1].num_bags + 1;
                    bag.weight = rand() % 50 + 1;
                    time_t now = time(NULL);
                    bag.arrival_time = *localtime(&now);
                    add_bag_to_flight(&bag, &flights[flight_choice-1]);
                    printf("Baggage %d added to Flight %d. Weight: %d kg\n", bag.id, flights[flight_choice-1].id, bag.weight);
                }
            }
        } else if (choice == 3) {
            if (num_flights == 0) {
                printf("No flights created yet.\n");
            } else {
                for (int i = 0; i < num_flights; i++) {
                    print_flight(&flights[i]);
                }
            }
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Sorry, invalid choice.\n");
        }
    }

    return 0;
}

// Add a baggage to a flight
void add_bag_to_flight(Baggage* bag, Flight* flight)
{
    if (flight->num_bags < MAX_BAGS && flight->capacity >= bag->weight) {
        flight->bags[flight->num_bags] = *bag;
        flight->num_bags++;
    } else {
        printf("Sorry, baggage could not be added to flight.\n");
    }
}

// Print the details of a baggage
void print_bag(Baggage* bag)
{
    printf("Baggage ID: %d\n", bag->id);
    printf("Weight: %d kg\n", bag->weight);
    printf("Arrival Time: %02d:%02d:%02d\n", bag->arrival_time.tm_hour, bag->arrival_time.tm_min, bag->arrival_time.tm_sec);
}

// Print the details of a flight and all its baggage
void print_flight(Flight* flight)
{
    printf("Flight ID: %d\n", flight->id);
    printf("Capacity: %d\n", flight->capacity);
    printf("Number of Bags: %d\n", flight->num_bags);
    printf("Baggage Details:\n");
    for (int i = 0; i < flight->num_bags; i++) {
        print_bag(&flight->bags[i]);
    }
}