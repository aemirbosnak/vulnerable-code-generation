//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 10

typedef struct Passenger
{
    char name[50];
    char flight_number[20];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void addPassenger(Passenger** head)
{
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));

    printf("Enter your name: ");
    scanf("%s", newPassenger->name);

    printf("Enter your flight number: ");
    scanf("%s", newPassenger->flight_number);

    printf("Enter your baggage weight: ");
    scanf("%d", &newPassenger->baggage_weight);

    newPassenger->next = NULL;

    if (*head == NULL)
    {
        *head = newPassenger;
    }
    else
    {
        (*head)->next = newPassenger;
    }
}

void printPassengers(Passenger* head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Flight number: %s\n", head->flight_number);
        printf("Baggage weight: %d\n", head->baggage_weight);
        printf("\n");
        head = head->next;
    }
}

void calculateTotalBaggageWeight(Passenger* head)
{
    int total_weight = 0;

    while (head)
    {
        total_weight += head->baggage_weight;
        head = head->next;
    }

    printf("Total baggage weight: %d\n", total_weight);
}

int main()
{
    Passenger* head = NULL;

    // Add passengers
    addPassenger(&head);
    addPassenger(&head);
    addPassenger(&head);

    // Print passengers
    printPassengers(head);

    // Calculate total baggage weight
    calculateTotalBaggageWeight(head);

    return 0;
}