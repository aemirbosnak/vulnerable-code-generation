//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define BUFFER_SIZE 50

typedef struct {
    int floor;
    char name[BUFFER_SIZE];
} elevator;

int main() {
    elevator elevatorArray[MAX_FLOORS];

    int n = 0;
    printf("Enter the number of floors in the building: ");
    scanf("%d", &n);

    int i = 0;
    while (i < n) {
        printf("Floor %d: ", i + 1);
        scanf("%s", elevatorArray[i].name);
        elevatorArray[i].floor = i + 1;
        i++;
    }

    int x = 0;
    while (x < n) {
        printf("Enter the floor you want to go to: ");
        scanf("%d", &x);

        int y = 0;
        while (y < n) {
            if (x == elevatorArray[y].floor) {
                printf("You are already on floor %d.\n", x);
            } else if (x > elevatorArray[y].floor) {
                printf("Going up to floor %d...\n", x);
                elevatorArray[y].floor = x;
                break;
            } else {
                printf("Going down to floor %d...\n", x);
                elevatorArray[y].floor = x;
                break;
            }
            y++;
        }
    }

    int z = 0;
    while (z < n) {
        printf("The elevator is on floor %d.\n", elevatorArray[z].floor);
        z++;
    }

    return 0;
}