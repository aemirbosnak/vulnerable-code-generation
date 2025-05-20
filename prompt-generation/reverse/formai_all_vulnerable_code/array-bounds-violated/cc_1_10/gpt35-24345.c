//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 50
#define MAX_FLIGHTS 5

typedef struct {
    char name[20];
    int num_bags;
} Passenger;

typedef struct {
    int flight_num;
    int num_passengers;
    Passenger passengers[MAX_CAPACITY];
} Flight;

int num_flights = 0;
Flight flights[MAX_FLIGHTS];

void addPassenger(int flight_num, Passenger p);
void displayFlightDetails(Flight f);
void displayFlightSummary(int flight_num);
void displayAllFlightsSummary();
void initializeFlights();

int main() {
    initializeFlights();
    while(1) {
        int choice;
        printf("Airport Baggage Handling Simulation\n");
        printf("------------------------------------\n");
        printf("1. Add Passenger\n");
        printf("2. Display Flight Details\n");
        printf("3. Display Flight Summary\n");
        printf("4. Display All Flights Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int flight_num, num_bags;
                char name[20];
                printf("Enter flight number: ");
                scanf("%d", &flight_num);
                printf("Enter passenger name: ");
                scanf("%s", name);
                printf("Enter number of bags: ");
                scanf("%d", &num_bags);
                Passenger p = { .num_bags = num_bags };
                strcpy(p.name, name);
                addPassenger(flight_num, p);
                printf("Passenger added successfully!\n\n");
                break;
            }
            case 2: {
                int flight_num;
                printf("Enter flight number: ");
                scanf("%d", &flight_num);
                Flight f = flights[flight_num];
                displayFlightDetails(f);
                break;
            }
            case 3: {
                int flight_num;
                printf("Enter flight number: ");
                scanf("%d", &flight_num);
                displayFlightSummary(flight_num);
                break;
            }
            case 4: {
                displayAllFlightsSummary();
                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n\n");
                break;
            }
        }
    }
    return 0;
}

void addPassenger(int flight_num, Passenger p) {
    Flight* f = &flights[flight_num];
    if(f->num_passengers >= MAX_CAPACITY) {
        printf("Flight %d is full. Cannot add passenger.\n\n", flight_num);
        return;
    }
    f->passengers[f->num_passengers++] = p;
}

void displayFlightDetails(Flight f) {
    printf("Flight Details\n");
    printf("--------------\n");
    printf("Flight Number: %d\n", f.flight_num);
    printf("Number of Passengers: %d\n", f.num_passengers);
    printf("Passenger Details:\n\n");
    for(int i = 0; i < f.num_passengers; i++) {
        Passenger p = f.passengers[i];
        printf("Passenger Name: %s\n", p.name);
        printf("Number of Bags: %d\n\n", p.num_bags);
    }
}

void displayFlightSummary(int flight_num) {
    Flight f = flights[flight_num];
    int total_bags = 0;
    for(int i = 0; i < f.num_passengers; i++) {
        total_bags += f.passengers[i].num_bags;
    }
    printf("Flight Summary for Flight %d\n", flight_num);
    printf("----------------------------\n");
    printf("Number of Passengers: %d\n", f.num_passengers);
    printf("Total Number of Bags: %d\n\n", total_bags);
}

void displayAllFlightsSummary() {
    printf("All Flights Summary\n");
    printf("-------------------\n");
    for(int i = 0; i < num_flights; i++) {
        displayFlightSummary(i);
    }
}

void initializeFlights() {
    flights[0] = (Flight) { .flight_num = 0 };
    flights[1] = (Flight) { .flight_num = 1 };
    flights[2] = (Flight) { .flight_num = 2 };
    flights[3] = (Flight) { .flight_num = 3 };
    flights[4] = (Flight) { .flight_num = 4 };
    num_flights = 5;
}