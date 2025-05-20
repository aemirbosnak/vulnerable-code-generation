//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 10
#define MAX_FLIGHTS 5

typedef struct {
    char name[50];
    int weight;
} Baggage;

typedef struct {
    char flight_number[10];
    Baggage bags[MAX_BAGS];
    int count;
} Flight;

void print_baggage(const Flight flight) {
    printf("For the flight %s, the baggage is as follows:\n", flight.flight_number);
    for (int i = 0; i < flight.count; i++) {
        printf("Baggage %d: %s weighs %d kg\n", i + 1, flight.bags[i].name, flight.bags[i].weight);
    }
}

void add_baggage(Flight* flight) {
    if (flight->count < MAX_BAGS) {
        Baggage bag;
        printf("Enter baggage name: ");
        scanf("%s", bag.name);
        printf("Enter baggage weight: ");
        scanf("%d", &bag.weight);
        
        flight->bags[flight->count] = bag;
        flight->count++;
        printf("Baggage added to the flight %s!\n", flight->flight_number);
    } else {
        printf("No more baggage can be added to flight %s.\n", flight->flight_number);
    }
}

void remove_baggage(Flight* flight) {
    if (flight->count > 0) {
        printf("Removing baggage from the flight %s.\n", flight->flight_number);
        flight->count--;
    } else {
        printf("No baggage to remove from flight %s.\n", flight->flight_number);
    }
}

void manage_flights(Flight flights[], int* flight_count) {
    while (1) {
        printf("\nRomeo airport baggage handling - Choose an action:\n");
        printf("1. Add a flight\n");
        printf("2. Add baggage to a flight\n");
        printf("3. Remove baggage from a flight\n");
        printf("4. Show all baggage\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (*flight_count < MAX_FLIGHTS) {
                    Flight flight;
                    printf("Enter flight number: ");
                    scanf("%s", flight.flight_number);
                    flight.count = 0;
                    flights[*flight_count] = flight;
                    (*flight_count)++;
                    printf("Flight %s added!\n", flight.flight_number);
                } else {
                    printf("Cannot add more flights.\n");
                }
                break;
            }
            case 2: {
                char flight_number[10];
                printf("Enter flight number to add baggage: ");
                scanf("%s", flight_number);

                int found = 0;
                for (int i = 0; i < *flight_count; i++) {
                    if (strcmp(flights[i].flight_number, flight_number) == 0) {
                        add_baggage(&flights[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Flight %s not found.\n", flight_number);
                }
                break;
            }
            case 3: {
                char flight_number[10];
                printf("Enter flight number to remove baggage: ");
                scanf("%s", flight_number);

                int found = 0;
                for (int i = 0; i < *flight_count; i++) {
                    if (strcmp(flights[i].flight_number, flight_number) == 0) {
                        remove_baggage(&flights[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Flight %s not found.\n", flight_number);
                }
                break;
            }
            case 4: {
                for (int i = 0; i < *flight_count; i++) {
                    print_baggage(flights[i]);
                }
                break;
            }
            case 5:
                printf("Farewell! Until we meet again...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}

int main() {
    Flight flights[MAX_FLIGHTS];
    int flight_count = 0;

    printf("A tragic tale begins at Romeo Airport...\n");
    manage_flights(flights, &flight_count);

    return 0;
}