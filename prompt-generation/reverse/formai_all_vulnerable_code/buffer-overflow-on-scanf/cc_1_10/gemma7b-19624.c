//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSENGERS 10

typedef struct Passenger {
    char name[20];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void add_passenger(Passenger* head) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    printf("Enter passenger name: ");
    scanf("%s", new_passenger->name);
    printf("Enter baggage weight (in kg): ");
    scanf("%d", &new_passenger->baggage_weight);
    new_passenger->next = NULL;
    if (head == NULL) {
        head = new_passenger;
    } else {
        head->next = new_passenger;
    }
    head = new_passenger;
}

void print_passengers(Passenger* head) {
    while (head) {
        printf("Name: %s, Baggage weight: %d kg\n", head->name, head->baggage_weight);
        head = head->next;
    }
}

void calculate_total_baggage_weight(Passenger* head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->baggage_weight;
        head = head->next;
    }
    printf("Total baggage weight: %d kg\n", total_weight);
}

int main() {
    Passenger* head = NULL;
    int num_passengers = 0;

    printf("Welcome to the C Airport Baggage Handling Simulation!\n");
    printf("Please select an option:\n");
    printf("1. Add passenger\n");
    printf("2. Print passengers\n");
    printf("3. Calculate total baggage weight\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_passenger(head);
            num_passengers++;
            break;
        case 2:
            print_passengers(head);
            break;
        case 3:
            calculate_total_baggage_weight(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}