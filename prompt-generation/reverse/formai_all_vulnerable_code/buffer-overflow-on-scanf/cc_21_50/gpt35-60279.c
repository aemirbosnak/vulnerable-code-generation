//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOOR 30
#define MIN_FLOOR 1
#define MAX_PASSENGER 10
#define MAX_CAPACITY 1000

typedef struct
{
    int weight;
    int current_floor;
    int destination_floor;
} Passenger;

typedef struct
{
    int current_floor;
    int passengers[MAX_PASSENGER];
    int current_weight;
} Elevator;

int main()
{
    Passenger passengers[MAX_PASSENGER];
    Elevator elevator;
    int i, j, num_passenger, num_floors;

    printf("Welcome to the Elevator Simulation Program!\n\n");

    printf("Please enter the number of passengers: ");
    scanf("%d", &num_passenger);

    printf("Please enter the number of floors: ");
    scanf("%d", &num_floors);

    while (num_floors > MAX_FLOOR || num_floors < MIN_FLOOR)
    {
        printf("Invalid number of floors. Please enter a number between %d and %d: ", MIN_FLOOR, MAX_FLOOR);
        scanf("%d", &num_floors);
    }

    printf("\n");

    for (i = 0; i < num_passenger; i++)
    {
        printf("Please enter the weight of passenger %d: ", i + 1);
        scanf("%d", &passengers[i].weight);

        while (passengers[i].weight <= 0 || passengers[i].weight > MAX_CAPACITY)
        {
            printf("Invalid weight. Please enter a weight between 1 and %d: ", MAX_CAPACITY);
            scanf("%d", &passengers[i].weight);
        }

        printf("Please enter the current floor of passenger %d: ", i + 1);
        scanf("%d", &passengers[i].current_floor);

        while (passengers[i].current_floor < MIN_FLOOR || passengers[i].current_floor > num_floors)
        {
            printf("Invalid floor number. Please enter a number between %d and %d: ", MIN_FLOOR, num_floors);
            scanf("%d", &passengers[i].current_floor);
        }

        printf("Please enter the destination floor of passenger %d: ", i + 1);
        scanf("%d", &passengers[i].destination_floor);

        while (passengers[i].destination_floor < MIN_FLOOR || passengers[i].destination_floor > num_floors || passengers[i].destination_floor == passengers[i].current_floor)
        {
            printf("Invalid floor number. Please enter a number between %d and %d (excluding current floor): ", MIN_FLOOR, num_floors);
            scanf("%d", &passengers[i].destination_floor);
        }

        printf("\n");
    }

    elevator.current_floor = MIN_FLOOR;
    elevator.current_weight = 0;

    while (1)
    {
        printf("Elevator at floor %d.\n", elevator.current_floor);

        for (i = 0; i < num_passenger; i++)
        {
            if (passengers[i].current_floor == elevator.current_floor)
            {
                if (elevator.current_weight + passengers[i].weight <= MAX_CAPACITY)
                {
                    printf("Passenger %d enters elevator.\n", i + 1);
                    elevator.passengers[i] = 1;
                    elevator.current_weight += passengers[i].weight;
                }
                else
                {
                    printf("Elevator full! Passenger %d cannot enter.\n", i + 1);
                }
            }

            if (passengers[i].destination_floor == elevator.current_floor && elevator.passengers[i] == 1)
            {
                printf("Passenger %d exits elevator.\n", i + 1);
                elevator.passengers[i] = 0;
                elevator.current_weight -= passengers[i].weight;
            }
        }

        for (j = elevator.current_floor + 1; j <= num_floors; j++)
        {
            for (i = 0; i < num_passenger; i++)
            {
                if (passengers[i].current_floor == j && elevator.current_weight + passengers[i].weight <= MAX_CAPACITY)
                {
                    printf("Elevator going up to floor %d.\n", j);
                    elevator.current_floor = j;
                    break;
                }
            }
        }

        for (j = elevator.current_floor - 1; j >= MIN_FLOOR; j--)
        {
            for (i = 0; i < num_passenger; i++)
            {
                if (passengers[i].current_floor == j && elevator.current_weight + passengers[i].weight <= MAX_CAPACITY)
                {
                    printf("Elevator going down to floor %d.\n", j);
                    elevator.current_floor = j;
                    break;
                }
            }
        }

        if (elevator.current_floor == MIN_FLOOR)
        {
            printf("Elevator at ground floor. Simulation over.\n");
            break;
        }
    }

    return 0;
}