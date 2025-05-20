//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>

int main() {

    int currentFloor = 1;
    int numFloors, numElevators;
    int targetFloors[10];
    int elevatorFloors[10];
    int i, j, k, closest;
    int flag = 0;

    printf("Enter the number of floors: ");
    scanf("%d", &numFloors);

    printf("Enter the number of elevators: ");
    scanf("%d", &numElevators);

    printf("\n");

    for(i = 0; i < numElevators; i++) {
        elevatorFloors[i] = 1;
    }

    while(1) {
        printf("Current floor: %d \n", currentFloor);

        for(i = 0; i < numElevators; i++) {
            printf("Elevator %d is currently on floor %d \n", i, elevatorFloors[i]);
        }

        printf("Enter target floor: ");
        scanf("%d", &targetFloors[flag]);

        if(targetFloors[flag] >= 1 && targetFloors[flag] <= numFloors) {
            flag++;
        } else {
            printf("Invalid floor number! \n");
            continue;
        }

        if(flag == numElevators) {
            closest = 0;

            for(i = 0; i < numElevators; i++) {
                if(abs(targetFloors[0] - elevatorFloors[i]) < abs(targetFloors[0] - elevatorFloors[closest])) {
                    closest = i;
                }
            }

            printf("Sending elevator %d to floor %d \n", closest, targetFloors[0]);

            for(i = 1; i < numElevators; i++) {
                targetFloors[i - 1] = targetFloors[i];
            }

            flag--;
        }

        if(flag == 0) {
            break;
        }

    }

    return 0;
}