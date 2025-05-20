//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

int current_floor = 0;
int direction = 1; // 1 for up, -1 for down
int people_count = 0;

typedef struct {
    int destination_floor;
} Person;

Person elevator[MAX_PEOPLE];

void add_person(int floor) {
    if (people_count >= MAX_PEOPLE) {
        printf("Elevator is full!\n");
        return;
    }
    Person person;
    person.destination_floor = floor;
    elevator[people_count] = person;
    people_count++;
}

void move_elevator() {
    current_floor += direction;
    printf("Elevator has arrived at floor %d\n", current_floor);
    for (int i = 0; i < people_count; i++) {
        if (elevator[i].destination_floor == current_floor) {
            printf("Person %d has arrived at their destination at floor %d\n", i+1, current_floor);
            for (int j = i; j < people_count-1; j++) {
                elevator[j] = elevator[j+1];
            }
            people_count--;
        }
    }
    if (current_floor == MAX_FLOORS) {
        direction = -1;
    } else if (current_floor == 1) {
        direction = 1;
    }
}

int main() {
    char input[10];
    while (1) {
        printf("Current Floor: %d\n", current_floor);
        printf("Number of People in Elevator: %d\n", people_count);
        printf("Enter 'add' to add a person to the elevator, or 'move' to move the elevator: ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            int floor;
            printf("Enter floor for new passenger: ");
            scanf("%d", &floor);
            add_person(floor);
        } else if (strcmp(input, "move") == 0) {
            move_elevator();
        } else {
            printf("Invalid input\n");
        }
    }
    return 0;
}