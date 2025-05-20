//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOOR 10
#define MAX_PERSONS 5

struct Person {
    int origin;
    int destination;
    int weight;
};

struct Elevator {
    int currentFloor;
    int direction;
    int persons;
    struct Person passengers[MAX_PERSONS];
};

void addPerson(struct Person person, struct Elevator *elevator) {
    if(elevator->persons < MAX_PERSONS && elevator->currentFloor == person.origin && elevator->direction == (person.destination > person.origin ? 1 : -1)) {
        int totalWeight = elevator->persons * 70 + person.weight;
        if(totalWeight <= 500) {
            elevator->passengers[elevator->persons++] = person;
            printf("Person added to elevator. Current weight: %d\n", totalWeight);
        } else {
            printf("Elevator has exceeded maximum weight capacity!\n");
        }
    } else {
        printf("Person cannot be added to elevator.\n");
    }
}

void moveElevator(struct Elevator *elevator) {
    if(elevator->direction > 0 && elevator->currentFloor < MAX_FLOOR) {
        elevator->currentFloor++;
    } else if(elevator->direction < 0 && elevator->currentFloor > 1) {
        elevator->currentFloor--;
    } else {
        elevator->direction *= -1;
    }
}

void removePersons(struct Elevator *elevator) {
    int i = 0;
    int floor = elevator->currentFloor;
    while(i < elevator->persons) {
        if(elevator->passengers[i].destination == floor) {
            elevator->persons--;
            if(elevator->persons > i) {
                elevator->passengers[i] = elevator->passengers[elevator->persons];
            }
            printf("Person has left the elevator.\n");
        } else {
            i++;
        }
    }
}

void printElevator(struct Elevator *elevator) {
    printf("Elevator is currently at floor %d and is moving %s. It contains %d persons:\n", elevator->currentFloor, elevator->direction > 0 ? "up" : "down", elevator->persons);
    for(int i = 0; i < elevator->persons; i++) {
        printf("\tPerson %d: Origin floor %d, Destination floor %d, Weight %d\n", i+1, elevator->passengers[i].origin, elevator->passengers[i].destination, elevator->passengers[i].weight);
    }
}

int main() {
    struct Person person1 = {2, 6, 70};
    struct Person person2 = {3, 10, 80};
    struct Person person3 = {6, 1, 50};
    struct Person person4 = {8, 1, 60};
    struct Elevator elevator = {1, 1, 0, {}};

    printf("Welcome to the elevator simulation!\n");

    while(elevator.currentFloor > 0) {
        printf("\nEnter the floor where you are: ");
        int origin;
        scanf("%d", &origin);

        printf("Where are you going to? ");
        int destination;
        scanf("%d", &destination);

        printf("What is your weight? ");
        int weight;
        scanf("%d", &weight);

        struct Person person = {origin, destination, weight};
        addPerson(person, &elevator);

        printElevator(&elevator);
        removePersons(&elevator);
        moveElevator(&elevator);
    }

    printf("\nEnd of simulation.\n");
    return 0;
}