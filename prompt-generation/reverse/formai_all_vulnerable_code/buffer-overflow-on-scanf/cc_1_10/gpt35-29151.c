//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[15];
    int position;
};

struct elevator {
    int current_floor;
    int target_floor;
    int direction;
    int num_people;
    struct person people[10];
};

void initialize_elevator(struct elevator *e) {
    e->current_floor = 1;
    e->target_floor = 1;
    e->direction = 1;
    e->num_people = 0;
}

void add_person(struct elevator *e, char name[], int position) {
    struct person new_person;
    strcpy(new_person.name, name);
    new_person.position = position;
    e->people[e->num_people] = new_person;
    e->num_people++;
}

void print_elevator(struct elevator *e) {
    printf("Current Floor: %d\n", e->current_floor);
    printf("Target Floor: %d\n", e->target_floor);
    printf("Direction: %d\n", e->direction);
    printf("Number of People: %d\n", e->num_people);
    for(int i = 0; i < e->num_people; i++) {
        printf("Person %d: %s, Position: %d\n", i+1, e->people[i].name, e->people[i].position);
    }
}

void window_scene(int total_people) {
    printf("Enter the names of individuals waiting for the elevator:\n");
    char name[15];
    int position;
    struct elevator e;
    initialize_elevator(&e);
    for(int i = 0; i < total_people; i++) {
        printf("Name of person %d: ", i+1);
        scanf("%s", name);
        printf("Position of person %d: ", i+1);
        scanf("%d", &position);
        add_person(&e, name, position);
    }
    printf("------------------------\n");
    printf("Elevator has arrived.\n");
    print_elevator(&e);
    printf("------------------------\n");
}

int main() {
    printf("Act 1: Scene 1 - A Window Scene\n");
    window_scene(4);
    printf("Act 1: Scene 2 - An Elevator Scene\n");
    struct elevator e;
    initialize_elevator(&e);
    add_person(&e, "Romeo", 12);
    add_person(&e, "Juliet", 3);
    printf("Elevator is moving up from floor 1 to floor 3.\n");
    e.direction = 1;
    e.current_floor = 1;
    e.target_floor = 3;
    print_elevator(&e);
    printf("Elevator has arrived on floor 3.\n");
    printf("Romeo and Juliet kiss and exit the elevator together.\n");
    e.num_people = 0;
    printf("------------------------\n");
    printf("Act 2: Scene 1 - A Party Scene\n");
    window_scene(6);
    printf("Act 2: Scene 2 - An Elevator Scene\n");
    initialize_elevator(&e);
    add_person(&e, "Romeo", 2);
    add_person(&e, "Juliet", 5);
    add_person(&e, "Tybalt", 9);
    printf("Elevator is moving down from floor 5 to floor 2.\n");
    e.direction = -1;
    e.current_floor = 5;
    e.target_floor = 2;
    print_elevator(&e);
    printf("Elevator has arrived on floor 2.\n");
    printf("Romeo and Juliet exit the elevator together.\n");
    e.num_people = 0;
    printf("Tybalt remains in the elevator and goes back up.\n");
    e.current_floor = 2;
    e.target_floor = 9;
    e.direction = 1;
    add_person(&e, "Tybalt", 1);
    print_elevator(&e);
    printf("Elevator is moving up from floor 2 to floor 9.\n");
    printf("The elevator doors close.\n");
    printf("------------------------\n");
    printf("Fin.\n");
    return 0;
}