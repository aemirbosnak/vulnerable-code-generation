//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 5

typedef struct {
    int current_floor;
    int destination_floor;
    int direction;
} elevator;

elevator elevators[MAX_ELEVATORS];

int main() {
    int i, j, k, n, choice, current_floor, destination_floor;
    char direction;

    printf("Enter the number of elevators: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        elevators[i].current_floor = 0;
        elevators[i].destination_floor = 0;
        elevators[i].direction = 0;
    }

    while(1) {
        printf("\n");
        printf("Enter the floor you are on: ");
        scanf("%d", &current_floor);

        printf("Enter the floor you want to go to: ");
        scanf("%d", &destination_floor);

        printf("Enter the direction you are facing: ");
        scanf(" %c", &direction);

        for(i = 0; i < n; i++) {
            if(elevators[i].current_floor == current_floor && elevators[i].direction == direction) {
                elevators[i].destination_floor = destination_floor;
                break;
            }
        }

        if(i == n) {
            printf("No elevator available.\n");
        } else {
            printf("Elevator %d is going to %d floor.\n", i+1, elevators[i].destination_floor);
        }

        printf("\n");
    }

    return 0;
}