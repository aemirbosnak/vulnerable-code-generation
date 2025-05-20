//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 7
#define ELEVATORS 3

typedef struct {
    int id;
    int current_floor;
    int destination;
    int passengers;
    bool in_use;
} Elevator;

void initialize_elevators(Elevator elevators[]) {
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].id = i+1;
        elevators[i].current_floor = rand() % FLOORS + 1;
        elevators[i].destination = -1;
        elevators[i].passengers = 0;
        elevators[i].in_use = false;
    }
}

int find_closest_elevator(Elevator elevators[], int floor) {
    int closest_id = -1;
    int closest_distance = FLOORS; // maximum distance between floors
    
    for (int i = 0; i < ELEVATORS; i++) {
        int distance = abs(elevators[i].current_floor - floor);
        if (distance < closest_distance && !elevators[i].in_use) {
            closest_id = elevators[i].id;
            closest_distance = distance;
        }
    }
    
    return closest_id;
}

void take_elevator(int floor, Elevator elevators[]) {
    int id = find_closest_elevator(elevators, floor);
    printf("Elevator %d is coming to floor %d\n", id, floor);
    elevators[id-1].in_use = true;
    elevators[id-1].destination = floor;
}

void move_elevator(Elevator *elevator) {
    if (elevator->current_floor < elevator->destination)
        elevator->current_floor++;
    else if (elevator->current_floor > elevator->destination)
        elevator->current_floor--;
}

void update_elevators(Elevator elevators[]) {
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevators[i].in_use) {
            move_elevator(&elevators[i]);
            if (elevators[i].current_floor == elevators[i].destination) {
                elevators[i].in_use = false;
                elevators[i].destination = -1;
                printf("Elevator %d arrived at floor %d with %d passengers\n", elevators[i].id, elevators[i].current_floor, elevators[i].passengers);
                elevators[i].passengers = 0;
            }
        }
    }
}

void print_elevators(Elevator elevators[]) {
    for (int i = 0; i < ELEVATORS; i++) {
        printf("Elevator %d is at floor %d with %d passengers\n", elevators[i].id, elevators[i].current_floor, elevators[i].passengers);
    }
}

int main() {
    srand(time(NULL));
    
    Elevator elevators[ELEVATORS];
    initialize_elevators(elevators);
    
    printf("Welcome to Retro Elevator Simulator!\n");
    printf("There are %d floors and %d elevators in our building.\n", FLOORS, ELEVATORS);
    
    int choice = 0;
    while (choice != 3) {
        printf("What would you like to do?\n");
        printf("1. Call an elevator\n");
        printf("2. View elevators\n");
        printf("3. Quit\n");
        printf("Your choice: ");
        
        scanf("%d", &choice);
        
        if (choice == 1) {
            int floor = 0;
            printf("Which floor are you on? ");
            scanf("%d", &floor);
            
            if (floor < 1 || floor > FLOORS) {
                printf("Invalid floor number.\n");
                continue;
            }
            
            take_elevator(floor, elevators);
        } else if (choice == 2) {
            print_elevators(elevators);
        } else if (choice != 3) {
            printf("Invalid choice.\n");
        }
        
        update_elevators(elevators);
    }
    
    printf("Thank you for using Retro Elevator Simulator!\n");
    
    return 0;
}