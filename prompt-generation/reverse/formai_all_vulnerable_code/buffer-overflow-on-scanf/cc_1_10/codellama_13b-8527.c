//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_BAGGAGE 1000
#define MAX_PASSENGERS 1000
#define MAX_DELAY 1000

typedef struct {
    int id;
    char* name;
    char* destination;
    char* status;
} Passenger;

Passenger passengers[MAX_PASSENGERS];

void print_menu() {
    printf("Airport Baggage Handling Simulation\n");
    printf("1. Add a passenger\n");
    printf("2. Check in a passenger\n");
    printf("3. Check out a passenger\n");
    printf("4. Print passenger information\n");
    printf("5. Exit\n");
}

void add_passenger() {
    int id;
    char name[50];
    char destination[50];

    printf("Enter passenger ID: ");
    scanf("%d", &id);
    printf("Enter passenger name: ");
    scanf("%s", name);
    printf("Enter destination: ");
    scanf("%s", destination);

    Passenger passenger;
    passenger.id = id;
    passenger.name = name;
    passenger.destination = destination;
    passenger.status = "checked in";

    passengers[id] = passenger;
}

void check_in_passenger() {
    int id;
    printf("Enter passenger ID: ");
    scanf("%d", &id);

    Passenger passenger = passengers[id];
    passenger.status = "checked in";

    passengers[id] = passenger;
}

void check_out_passenger() {
    int id;
    printf("Enter passenger ID: ");
    scanf("%d", &id);

    Passenger passenger = passengers[id];
    passenger.status = "checked out";

    passengers[id] = passenger;
}

void print_passenger_info() {
    int id;
    printf("Enter passenger ID: ");
    scanf("%d", &id);

    Passenger passenger = passengers[id];
    printf("Passenger ID: %d\n", passenger.id);
    printf("Passenger name: %s\n", passenger.name);
    printf("Destination: %s\n", passenger.destination);
    printf("Status: %s\n", passenger.status);
}

int main() {
    int option;

    while (1) {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_passenger();
                break;
            case 2:
                check_in_passenger();
                break;
            case 3:
                check_out_passenger();
                break;
            case 4:
                print_passenger_info();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}