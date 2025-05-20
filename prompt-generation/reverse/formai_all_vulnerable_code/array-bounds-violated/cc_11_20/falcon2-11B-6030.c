//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int floor;
    int people;
} elevator;

int main() {
    int n;
    printf("Enter number of floors: ");
    scanf("%d", &n);

    elevator floors[n];

    printf("Enter floors: ");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &floors[i].floor, &floors[i].people);
    }

    int max_floor = floors[0].floor;
    int max_people = floors[0].people;

    for (int i = 1; i < n; i++) {
        if (floors[i].floor > max_floor) {
            max_floor = floors[i].floor;
        }

        if (floors[i].people > max_people) {
            max_people = floors[i].people;
        }
    }

    elevator destination = floors[0];

    while (1) {
        printf("Enter floor and people: ");
        scanf("%d%d", &destination.floor, &destination.people);

        if (destination.floor == max_floor && destination.people == max_people) {
            break;
        }

        int next_floor = max_floor - 1;

        while (next_floor >= 0 && destination.people > floors[next_floor].people) {
            next_floor--;
        }

        if (next_floor >= 0) {
            destination.floor = next_floor;
        }

        printf("Moving to floor %d\n", destination.floor);
        destination.people = 0;
    }

    printf("Destination reached.\n");

    return 0;
}