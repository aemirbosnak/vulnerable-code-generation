//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

typedef struct {
    int id;
    int current_floor;
    int destination_floor;
} Person;

typedef struct {
    int floor_number;
    int people_count;
    Person people[MAX_PEOPLE];
} Floor;

typedef struct {
    int current_floor;
    int capacity;
    int people_count;
    Person people[MAX_PEOPLE];
} Elevator;

int main() {
    int num_floors;
    printf("Enter number of floors: ");
    scanf("%d", &num_floors);

    Floor floors[MAX_FLOORS];
    for (int i = 0; i < num_floors; i++) {
        floors[i].floor_number = i;
        floors[i].people_count = 0;
    }

    Elevator elevator;
    elevator.current_floor = 0;
    elevator.capacity = MAX_PEOPLE;
    elevator.people_count = 0;

    while (1) {
        printf("Elevator is on floor %d\n", elevator.current_floor);

        // let people inside the elevator
        for (int i = 0; i < floors[elevator.current_floor].people_count; i++) {
            if (elevator.people_count < elevator.capacity) {
                elevator.people[elevator.people_count++] = floors[elevator.current_floor].people[i];
            } else {
                printf("Elevator is full!\n");
                break;
            }
        }
        floors[elevator.current_floor].people_count = 0;

        // drop people off at their destination floors
        for (int i = 0; i < elevator.people_count; i++) {
            if (elevator.people[i].destination_floor == elevator.current_floor) {
                printf("Person %d got off the elevator on floor %d\n", elevator.people[i].id, elevator.current_floor);
            } else {
                floors[elevator.people[i].destination_floor].people[floors[elevator.people[i].destination_floor].people_count++] = elevator.people[i];
            }
        }
        elevator.people_count = 0;

        // let people outside the elevator in
        for (int i = 0; i < floors[elevator.current_floor].people_count; i++) {
            if (elevator.people_count < elevator.capacity) {
                elevator.people[elevator.people_count++] = floors[elevator.current_floor].people[i];
            } else {
                printf("Elevator is full!\n");
                break;
            }
        }
        floors[elevator.current_floor].people_count = 0;

        // if there are no more people waiting or inside the elevator, exit the loop
        int has_people = 0;
        for (int i = 0; i < num_floors; i++) {
            if (floors[i].people_count > 0) {
                has_people = 1;
            }
        }
        if (elevator.people_count > 0) {
            has_people = 1;
        }
        if (!has_people) {
            break;
        }

        // move the elevator to the next floor
        if (elevator.current_floor == 0) {
            printf("Elevator is going up!\n");
        } else if (elevator.current_floor == num_floors - 1) {
            printf("Elevator is going down!\n");
        }
        elevator.current_floor += (elevator.current_floor == 0) ? 1 : -1;
    }

    printf("Elevator simulation complete!\n");

    return 0;
}