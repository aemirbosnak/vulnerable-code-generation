//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10  // The highest floor the elevator can go to
#define MAX_PEOPLE 10  // The maximum number of people in the elevator

// Struct to represent each person
typedef struct {
    int current_floor;
    int destination_floor;
} Person;

// Struct to represent the elevator
typedef struct {
    int current_floor;
    int num_people;
    Person people[MAX_PEOPLE];
} Elevator;

int get_input(int min, int max, char *prompt);
void take_people(Elevator *e);
void move_elevator(Elevator *e, int target_floor);
void drop_people(Elevator *e);
bool is_person_destined_for_floor(Person p, int floor);

int main() {
    Elevator e = {1, 0, {}};

    while (true) {
        int target_floor = get_input(1, MAX_FLOORS, "Enter a floor number to go to: ");
        move_elevator(&e, target_floor);
        take_people(&e);
        drop_people(&e);
    }

    return 0;
}

void take_people(Elevator *e) {
    while (e->num_people < MAX_PEOPLE) {
        int current_floor = e->current_floor;
        int needed_space = MAX_PEOPLE - e->num_people;

        printf("There is space for %d people left. Will anyone enter on floor %d? (y/n) ",
                needed_space, current_floor);
        char choice = getchar();
        if (choice == '\n') {
            choice = getchar();  // account for user hitting enter before y/n
        }

        if (choice == 'y') {
            printf("How many people are entering? ");
            int num_entering = get_input(1, needed_space, "");

            for (int i = 0; i < num_entering; i++) {
                printf("Person %d, what floor will you be going to? ", i+1);
                int destination_floor = get_input(1, MAX_FLOORS, "");

                Person p = {current_floor, destination_floor};
                e->people[e->num_people++] = p;
            }
        } else {
            break;
        }
    }
}

void drop_people(Elevator *e) {
    int num_dropped = 0;
    for (int i = 0; i < e->num_people; i++) {
        if (is_person_destined_for_floor(e->people[i], e->current_floor)) {
            printf("Person exiting the elevator at floor %d\n", e->current_floor);
            e->num_people--;
            e->people[i--] = e->people[e->num_people];  // replace person with last person in array
            num_dropped++;
        }
    }
    if (num_dropped > 0) {
        printf("%d people have exited the elevator\n", num_dropped);
    }
}

bool is_person_destined_for_floor(Person p, int floor) {
    return p.destination_floor == floor;
}

void move_elevator(Elevator *e, int target_floor) {
    printf("Elevator moving from floor %d to floor %d\n", e->current_floor, target_floor);

    if (target_floor > e->current_floor) {
        for (int i = e->current_floor + 1; i <= target_floor; i++) {
            e->current_floor = i;
            printf("Elevator arrives at floor %d\n", i);
        }
    } else if (target_floor < e->current_floor) {
        for (int i = e->current_floor - 1; i >= target_floor; i--) {
            e->current_floor = i;
            printf("Elevator arrives at floor %d\n", i);
        }
    }

    printf("Elevator has arrived at floor %d\n", target_floor);
}

int get_input(int min, int max, char *prompt) {
    int num = min - 1;
    while (num < min || num > max) {
        printf("%s", prompt);
        scanf("%d", &num);
        if (num < min || num > max) {
            printf("Please enter a number between %d and %d\n", min, max);
        }
    }
    return num;
}