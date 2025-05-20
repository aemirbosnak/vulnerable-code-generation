//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGGAGE 20
#define MAX_NAME 30

typedef struct {
    char name[MAX_NAME];
    int flightNumber;
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGGAGE];
    int count;
} BaggageHandler;

void addBaggage(BaggageHandler *handler, char *passengerName, int flightNumber) {
    if (handler->count < MAX_BAGGAGE) {
        strcpy(handler->bags[handler->count].name, passengerName);
        handler->bags[handler->count].flightNumber = flightNumber;
        handler->count++;
        printf("O sweet baggage, thou art added for %s on flight %d\n", passengerName, flightNumber);
    } else {
        printf("Alas! The baggage handler overfloweth! No more bags shall be taken.\n");
    }
}

void retrieveBaggage(BaggageHandler *handler) {
    if (handler->count == 0) {
        printf("Forsooth! No baggage to retrieve!\n");
        return;
    }
    
    printf("Retrieving thy baggage, fair passenger...\n");
    for (int i = 0; i < handler->count; i++) {
        printf("Behold! Baggage of %s for flight %d\n", handler-> bags[i].name, handler->bags[i].flightNumber);
    }
    handler->count = 0; // All baggage retrieved
}

void flightConflict(int flight1, int flight2) {
    printf("O woe! A conflict arises between flights %d and %d!\n", flight1, flight2);
    printf("Shall the baggage be divided by fate or run asunder? Choose wisely!\n");
}

int main() {
    BaggageHandler handler = { .count = 0 };
    int choice = 0;
    
    printf("Welcome to the Baggage Handling Play of Fate!\n");
    
    while (1) {
        printf("\nChoose thy destiny:\n");
        printf("1. Add Baggage\n");
        printf("2. Retrieve Baggage\n");
        printf("3. Conflict between Flights\n");
        printf("4. Exit the stage\n");
        printf("Enter thy choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char passengerName[MAX_NAME];
            int flightNumber;
            printf("Enter passenger name: ");
            scanf("%s", passengerName);
            printf("Enter flight number: ");
            scanf("%d", &flightNumber);
            addBaggage(&handler, passengerName, flightNumber);
        } else if (choice == 2) {
            retrieveBaggage(&handler);
        } else if (choice == 3) {
            int flight1, flight2;
            printf("Enter flight number one: ");
            scanf("%d", &flight1);
            printf("Enter flight number two: ");
            scanf("%d", &flight2);
            flightConflict(flight1, flight2);
        } else if (choice == 4) {
            printf("Fare thee well! The play ends, as all things must.\n");
            break;
        } else {
            printf("O misfortune! Choose a valid path!\n");
        }
    }

    return 0;
}