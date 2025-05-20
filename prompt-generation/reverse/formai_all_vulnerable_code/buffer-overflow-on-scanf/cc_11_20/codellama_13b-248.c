//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
/*
 * Elevator Simulation
 *
 * This program simulates the operation of an elevator.
 *
 * The program will ask the user for the number of floors in the building,
 * the number of elevators, and the number of people to be simulated.
 *
 * The program will then simulate the elevators moving up and down the floors,
 * and the people entering and exiting the elevators.
 *
 * The program will also simulate the situation where the elevator is full,
 * and the people have to wait for the next elevator.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 100
#define MAX_ELEVATORS 10
#define MAX_PEOPLE 1000

int main() {
    int num_floors, num_elevators, num_people, i, j, k;
    int floors[MAX_FLOORS];
    int elevators[MAX_ELEVATORS];
    int people[MAX_PEOPLE];

    printf("Enter the number of floors in the building: ");
    scanf("%d", &num_floors);

    printf("Enter the number of elevators: ");
    scanf("%d", &num_elevators);

    printf("Enter the number of people to be simulated: ");
    scanf("%d", &num_people);

    // Initialize the floors and elevators
    for (i = 0; i < num_floors; i++) {
        floors[i] = 0;
    }
    for (i = 0; i < num_elevators; i++) {
        elevators[i] = 0;
    }

    // Simulate the elevators moving up and down the floors
    for (i = 0; i < num_people; i++) {
        printf("Enter the floor number for person %d: ", i + 1);
        scanf("%d", &people[i]);

        // Find the elevator that is closest to the person's floor
        int closest_elevator = -1;
        int closest_distance = -1;
        for (j = 0; j < num_elevators; j++) {
            int distance = abs(elevators[j] - people[i]);
            if (closest_distance == -1 || distance < closest_distance) {
                closest_elevator = j;
                closest_distance = distance;
            }
        }

        // If the elevator is full, make the person wait
        if (elevators[closest_elevator] == 0) {
            printf("Person %d is entering elevator %d on floor %d\n", i + 1, closest_elevator + 1, elevators[closest_elevator]);
            elevators[closest_elevator] = people[i];
        } else {
            printf("Person %d is waiting for elevator %d\n", i + 1, closest_elevator + 1);
        }

        // Move the elevator up and down the floors
        for (j = 0; j < num_floors; j++) {
            if (elevators[closest_elevator] == 0) {
                break;
            }
            printf("Elevator %d is moving from floor %d to floor %d\n", closest_elevator + 1, elevators[closest_elevator], elevators[closest_elevator] + 1);
            elevators[closest_elevator]++;
        }

        // If the elevator reaches the top floor, loop back to the bottom floor
        if (elevators[closest_elevator] == num_floors) {
            printf("Elevator %d is looping back to floor 1\n", closest_elevator + 1);
            elevators[closest_elevator] = 1;
        }

        // If the elevator is empty, exit the loop
        if (elevators[closest_elevator] == 0) {
            break;
        }
    }

    return 0;
}