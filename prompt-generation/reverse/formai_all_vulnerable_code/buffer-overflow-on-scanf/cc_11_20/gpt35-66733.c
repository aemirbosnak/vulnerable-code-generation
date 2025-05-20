//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include<stdio.h>

int main() {
    int i, j, n, c, floor, max, min, curr = 0;
    int dest[10], arr[10], time[10];
    printf("Enter the number of floors: ");
    scanf("%d", &n);

    printf("Enter the maximum persons allowed in the elevator: ");
    scanf("%d", &max);

    printf("Enter the minimum and maximum floor range for the elevator: ");
    scanf("%d %d", &min, &floor);

    printf("How many people will use the elevator: ");
    scanf("%d", &c);

    printf("Enter the floor at which the people are waiting: ");
    for (i = 0; i < c; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the floor to which the person wants to go: ");
    for (i = 0; i < c; i++) {
        scanf("%d", &dest[i]);
    }
    printf("Enter the time at which the person will enter the elevator: ");
    for (i = 0; i<c; i++) {
        scanf("%d", &time[i]);
    }

    for (i = 0; i < c; i++) {
        printf("Person %d is on floor %d and wants to go to floor %d at time %d\n", i+1, arr[i], dest[i], time[i]);
    }

    printf("Starting the simulation...\n");

    for (i = min; i <= floor; i++) {
        printf("Current floor: %d\n", i);
        curr = i;
        for(j = 0; j < c; j++) {
            if (arr[j] == i) {
                if (max > 0) {
                    max--;
                    printf("Person %d entered the elevator at floor %d at time %d\n", j+1, i, time[j]);
                }
                else {
                    printf("Elevator is full, person %d has to wait for the next trip\n", j+1);
                }
            }
        }

        for (j = 0; j < c; j++) {
            if (dest[j] == i) {
                printf("Person %d left the elevator at floor %d at time %d\n", j+1, i, time[j]);
                max++;
            }
        }

    }

    return 0;
}