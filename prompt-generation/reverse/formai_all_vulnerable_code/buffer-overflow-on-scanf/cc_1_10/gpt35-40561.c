//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 20

int elevator_floor = 1; // Starting floor of elevator
int people_waiting[MAX_FLOORS] = {0}; // Initialize waiting elevator people to 0

void print_elevator(int floor) {
    printf("\nElevator is now at floor %d.\n", floor);
}

void print_waiting_people(int floor) {
    printf("\nPeople waiting at floor %d: %d\n", floor, people_waiting[floor-1]);
}

void welcome_msg() {
    printf("Welcome to our elevator simulation program!\n");
}

void goodbye_msg() {
    printf("\nEnd of simulation. Thank you for using our program!\n");
}

int get_user_direction() {
    char input;
    int direction;
    printf("\nEnter 'U' for going up or 'D' for going down: ");
    scanf(" %c", &input);
    while(input != 'U' && input != 'D') {
        printf("Invalid input! Enter 'U' for going up or 'D' for going down: ");
        scanf(" %c", &input);
    }

    direction = (input == 'U') ? 1 : -1; // 1 for up, -1 for down
    return direction;
}

int get_user_floor() {
    int floor;
    printf("\nEnter the floor number you are currently on: ");
    scanf("%d", &floor);
    while(floor < 1 || floor > MAX_FLOORS) {
        printf("Invalid floor number! Enter a floor number between 1 and %d: ", MAX_FLOORS);
        scanf("%d", &floor);
    }
    return floor;
}

int get_user_num_people() {
    int num_people;
    printf("\nEnter the number of people waiting to get on the elevator: ");
    scanf("%d", &num_people);
    while(num_people < 1 || num_people > MAX_PEOPLE) {
        printf("Invalid number of people! Enter a number between 1 and %d: ", MAX_PEOPLE);
        scanf("%d", &num_people);
    }
    return num_people;
}

void add_people_to_elevator(int floor, int num_people) {
    if(people_waiting[floor-1] < num_people) {
        printf("\nError: There are only %d people waiting at this floor.\n", people_waiting[floor-1]);
        return;
    }

    printf("\nAdding %d people to the elevator...\n", num_people);
    people_waiting[floor-1] -= num_people;
}

void remove_people_from_elevator() {
    char input;
    int num_people_to_remove;
    printf("\nDo you want to remove people from the elevator? (Y/N): ");
    scanf(" %c", &input);
    if(input == 'Y' || input == 'y') {
        printf("\nEnter the number of people to remove: ");
        scanf("%d", &num_people_to_remove);
        while(num_people_to_remove < 0 || num_people_to_remove > MAX_PEOPLE) {
            printf("Invalid number of people! Enter a number between 1 and %d: ", MAX_PEOPLE);
            scanf("%d", &num_people_to_remove);
        }
        printf("\nRemoving %d people from the elevator...\n", num_people_to_remove);
    }
}

int main() {
    int floor, direction, num_people;
    welcome_msg();

    while(1) {
        floor = get_user_floor();
        print_waiting_people(floor);

        if(people_waiting[floor-1] == 0) {
            printf("\nThere are no people waiting at this floor.\n");
            continue;
        }

        direction = get_user_direction();

        if(direction == 1) { // Going up
            for(int i=floor; i<=MAX_FLOORS; i++) {
                if(people_waiting[i-1] > 0) { // Stop at floor with waiting people
                    print_elevator(i);
                    num_people = get_user_num_people();
                    add_people_to_elevator(i, num_people);
                    remove_people_from_elevator();
                }
            }
        }
        else if(direction == -1) { // Going down
            for(int i=floor; i>=1; i--) {
                if(people_waiting[i-1] > 0) { // Stop at floor with waiting people
                    print_elevator(i);
                    num_people = get_user_num_people();
                    add_people_to_elevator(i, num_people);
                    remove_people_from_elevator();
                }
            }
        }
        else {
            printf("\nError: Invalid direction!\n");
            break;
        }
    }

    goodbye_msg();
    return 0;
}