//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BAGGAGE 100
#define MAX_PASSPORTS 50

typedef struct {
    char passport[20];
    char baggage[20][30];
    int baggage_count;
} Passenger;

Passenger passengers[MAX_PASSPORTS];
int passenger_count = 0;

void check_in_baggage(Passenger *passenger) {
    if (passenger->baggage_count < 20) {
        printf("Enter baggage description for passenger %s: ", passenger->passport);
        scanf("%s", passenger->baggage[passenger->baggage_count]);
        passenger->baggage_count++;
        printf("Baggage check-in successful for passenger %s!\n", passenger->passport);
    } else {
        printf("Maximum baggage limit reached for passenger %s!\n", passenger->passport);
    }
}

void load_baggage() {
    printf("\nLoading baggage onto planes...\n");
    for (int i = 0; i < passenger_count; i++) {
        printf("Passenger %s has the following baggage:\n", passengers[i].passport);
        for (int j = 0; j < passengers[i].baggage_count; j++) {
            printf(" - %s\n", passengers[i].baggage[j]);
        }
    }
    printf("All baggage loaded successfully!\n");
}

void print_passengers() {
    printf("\nList of Passengers:\n");
    for (int i = 0; i < passenger_count; i++) {
        printf("Passenger %d: %s with %d bag(s)\n", i + 1, passengers[i].passport, passengers[i].baggage_count);
    }
}

void add_passenger() {
    if (passenger_count < MAX_PASSPORTS) {
        printf("Enter passport number for new passenger: ");
        scanf("%s", passengers[passenger_count].passport);
        passengers[passenger_count].baggage_count = 0;
        passenger_count++;
        printf("Passenger %s added successfully!\n", passengers[passenger_count - 1].passport);
    } else {
        printf("Passenger limit reached!\n");
    }
}

int main() {
    int choice;

    srand(time(0));  // Initialize random number generator

    printf("Welcome to the Airport Baggage Handling System!\n");

    while (1) {
        printf("\n1. Add Passenger\n2. Check-in Baggage\n3. Load Baggage\n4. View Passengers\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_passenger();
                break;
            case 2:
                {
                    printf("Choose a passenger to check-in baggage (1-%d): ", passenger_count);
                    int index;
                    scanf("%d", &index);
                    if (index > 0 && index <= passenger_count) {
                        check_in_baggage(&passengers[index - 1]);
                    } else {
                        printf("Invalid passenger selection!\n");
                    }
                }
                break;
            case 3:
                load_baggage();
                break;
            case 4:
                print_passengers();
                break;
            case 5:
                printf("Exiting the system. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}