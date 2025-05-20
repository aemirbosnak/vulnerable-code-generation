//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct elevator {
    int floor;
    int current_floor;
    int direction;
    int people;
};

int main() {
    struct elevator elevator;
    elevator.floor = 0;
    elevator.current_floor = 0;
    elevator.direction = 0;
    elevator.people = 0;

    while(1) {
        printf("Floor: %d\n", elevator.current_floor);
        printf("Direction: %d\n", elevator.direction);
        printf("People: %d\n", elevator.people);
        printf("Enter action (n: next floor, d: down, u: up, q: quit): ");
        char action[3];
        scanf("%s", action);

        switch(action[0]) {
            case 'n':
                if(elevator.current_floor + 1 > elevator.floor) {
                    elevator.current_floor++;
                    elevator.direction = 1;
                }
                else {
                    printf("Cannot go to next floor.\n");
                }
                break;
            case 'd':
                if(elevator.current_floor > 0) {
                    elevator.current_floor--;
                    elevator.direction = -1;
                }
                else {
                    printf("Cannot go down.\n");
                }
                break;
            case 'u':
                if(elevator.current_floor < elevator.floor) {
                    elevator.current_floor++;
                    elevator.direction = 1;
                }
                else {
                    printf("Cannot go up.\n");
                }
                break;
            case 'q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid action.\n");
                break;
        }
    }

    return 0;
}