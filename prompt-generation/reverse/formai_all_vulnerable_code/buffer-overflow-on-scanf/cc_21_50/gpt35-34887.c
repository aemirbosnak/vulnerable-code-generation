//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100
#define MAX_FLIGHTS 10
#define MAX_BAGS_PER_FLIGHT 10

typedef struct {
    int flight_number;
    int num_bags;
    int bags[MAX_BAGS_PER_FLIGHT];
} Flight;

typedef struct {
    int num_flights;
    Flight flights[MAX_FLIGHTS];
} BaggageReclaim;

typedef struct {
    int num_bags;
    int bags[MAX_CAPACITY];
} ConveyorBelt;

int main() {
    bool running = true;
    int choice;

    BaggageReclaim reclaim = {0};
    ConveyorBelt belt = {0};

    printf("Airport Baggage Handling Simulation\n");

    while (running) {
        printf("\n1. Add flight\n");
        printf("2. Add bags to conveyor belt\n");
        printf("3. Remove bags from conveyor belt and load onto flight\n");
        printf("4. View baggage reclaim\n");
        printf("5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (reclaim.num_flights < MAX_FLIGHTS) {
                    int flight_num, num_bags;
                    printf("\nEnter flight number: ");
                    scanf("%d", &flight_num);
                    printf("Enter number of bags: ");
                    scanf("%d", &num_bags);

                    if (num_bags <= MAX_BAGS_PER_FLIGHT) {
                        Flight new_flight = {flight_num, num_bags};
                        for (int i = 0; i < num_bags; i++) {
                            printf("Enter bag %d weight: ", i + 1);
                            scanf("%d", &new_flight.bags[i]);
                        }
                        reclaim.flights[reclaim.num_flights++] = new_flight;
                        printf("Flight %d added to baggage reclaim.\n", flight_num);
                    } else {
                        printf("Maximum baggage per flight is %d.\n", MAX_BAGS_PER_FLIGHT);
                    }
                } else {
                    printf("Maximum number of flights reached.\n");
                }
                break;
            case 2:
                if (belt.num_bags < MAX_CAPACITY) {
                    int num_bags;
                    printf("\nEnter number of bags to add: ");
                    scanf("%d", &num_bags);

                    if (belt.num_bags + num_bags <= MAX_CAPACITY) {
                        for (int i = 0; i < num_bags; i++) {
                            printf("Enter bag %d weight: ", i + 1);
                            scanf("%d", &belt.bags[belt.num_bags++]);
                        }
                        printf("%d bags added to conveyor belt.\n", num_bags);
                    } else {
                        printf("Maximum capacity of conveyor belt is %d.\n", MAX_CAPACITY);
                    }
                } else {
                    printf("Conveyor belt is at maximum capacity.\n");
                }
                break;
            case 3:
                if (belt.num_bags > 0) {
                    int flight_num;
                    printf("\nEnter flight number: ");
                    scanf("%d", &flight_num);

                    bool found_flight = false;
                    for (int i = 0; i < reclaim.num_flights; i++) {
                        if (reclaim.flights[i].flight_number == flight_num) {
                            found_flight = true;

                            if (reclaim.flights[i].num_bags + belt.num_bags <= MAX_BAGS_PER_FLIGHT) {
                                for (int j = 0; j < belt.num_bags; j++) {
                                    reclaim.flights[i].bags[reclaim.flights[i].num_bags++] = belt.bags[j];
                                }
                                belt.num_bags = 0;
                                printf("%d bags loaded onto flight %d.\n", reclaim.flights[i].num_bags, flight_num);
                            } else {
                                printf("Flight %d is at maximum baggage allowance.\n", flight_num);
                            }

                            break;
                        }
                    }

                    if (!found_flight) {
                        printf("Flight %d not found in baggage reclaim.\n", flight_num);
                    }
                } else {
                    printf("Conveyor belt is empty.\n");
                }
                break;
            case 4:
                printf("\nBaggage Reclaim\n");

                for (int i = 0; i < reclaim.num_flights; i++) {
                    printf("Flight %d (%d bags)\n", reclaim.flights[i].flight_number, reclaim.flights[i].num_bags);

                    for (int j = 0; j < reclaim.flights[i].num_bags; j++) {
                        printf("\tBag %d: %d kg\n", j + 1, reclaim.flights[i].bags[j]);
                    }
                }
                break;
            case 5:
                running = false;
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}