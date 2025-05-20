//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PEOPLE 10
#define ELEVATOR_SPEED 5

typedef struct {
    char name[30];
    int age;
    float weight;
} Person;

int current_floor = 0;
int num_people = 0;
Person people[MAX_PEOPLE];

void add_person(Person p) {
    if (num_people >= MAX_PEOPLE) {
        printf("Sorry, the elevator is full!\n");
        return;
    }
    strcpy(people[num_people].name, p.name);
    people[num_people].age = p.age;
    people[num_people].weight += p.weight;
    num_people++;
}

void remove_person() {
    if (num_people == 0) {
        printf("Oops, the elevator is empty!\n");
        return;
    }
    num_people--;
}

void elevator_movement(int dest_floor) {
    int travel_time = abs(dest_floor - current_floor) * ELEVATOR_SPEED;
    printf("Elevator is moving to floor %d. Travel time: %d seconds...\n", dest_floor, travel_time);
    fflush(stdin);
    clock_t start = clock();
    while (clock() - start < travel_time * CLOCKS_PER_SEC / ELEVATOR_SPEED) {
        // Do nothing, just simulate the elevator movement
    }
    current_floor = dest_floor;
    printf("Elevator has reached floor %d.\n", dest_floor);
}

int main() {
    srand(time(NULL));

    printf("Welcome to the High-Tech Elevator Simulation!\n");

    add_person((Person){"John Doe", 35, 75.5});
    add_person((Person){"Jane Smith", 28, 58.3});
    add_person((Person){"Bob Johnson", 42, 92.1});

    while (num_people > 0) {
        int dest_floor = rand() % 10;
        printf("Passenger %s (age: %d, weight: %.2f) wants to go to floor %d.\n", people[num_people - 1].name, people[num_people - 1].age, people[num_people - 1].weight, dest_floor);
        remove_person();
        elevator_movement(dest_floor);
    }

    printf("All passengers have left the elevator.\n");

    return 0;
}