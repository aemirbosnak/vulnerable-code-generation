//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

int numOfFloors, capacity, currFloor = 0, currFilled = 0, direction = 1;
int *floorUp, *floorDown;
int upFlag = 0, downFlag = 0;

void goToFloor(int floor) {
    printf("Elevator going to floor %d...\n", floor);
    sleep(1);
    printf("Arrived at floor %d.\n", floor);
    currFloor = floor;
}

void *elevator(void *arg) {
    while(1) {
        if (direction == 1) { //moving up
            for (int i = currFloor+1; i < numOfFloors; i++) {
                if (floorUp[i] > 0 || floorDown[i] > 0) { //there are people to pick up
                    pthread_mutex_lock(&lock);
                    if (floorUp[i] > 0) {
                        floorUp[i] = (floorUp[i] > capacity-currFilled) ? floorUp[i]-(capacity-currFilled) : 0;
                        currFilled += capacity-currFilled;
                        printf("Picked up %d passengers going up at floor %d.\n", capacity-currFilled, i);
                    }
                    if (floorDown[i] > 0) {
                        floorDown[i] = (floorDown[i] > capacity-currFilled) ? floorDown[i]-(capacity-currFilled) : 0;
                        currFilled += capacity-currFilled;
                        printf("Picked up %d passengers going down at floor %d.\n", capacity-currFilled, i);
                    }
                    upFlag = (floorUp[i] > 0) ? 1 : 0;
                    downFlag = (floorDown[i] > 0) ? 1 : 0;
                    if (currFilled == capacity) {
                        printf("Elevator is full. Moving to the next floor...\n");
                        sleep(1);
                        direction = (upFlag && !downFlag) ? 1 : -1;
                        if (!upFlag && !downFlag) {
                            direction = 0;
                        }
                        pthread_mutex_unlock(&lock);
                        break;
                    }
                    pthread_mutex_unlock(&lock);
                }
            }
        } else if (direction == -1) { //moving down
            for (int i = currFloor-1; i >= 0; i--) {
                if (floorUp[i] > 0 || floorDown[i] > 0) { //there are people to pick up
                    pthread_mutex_lock(&lock);
                    if (floorUp[i] > 0) {
                        floorUp[i] = (floorUp[i] > capacity-currFilled) ? floorUp[i]-(capacity-currFilled) : 0;
                        currFilled += capacity-currFilled;
                        printf("Picked up %d passengers going up at floor %d.\n", capacity-currFilled, i);
                    }
                    if (floorDown[i] > 0) {
                        floorDown[i] = (floorDown[i] > capacity-currFilled) ? floorDown[i]-(capacity-currFilled) : 0;
                        currFilled += capacity-currFilled;
                        printf("Picked up %d passengers going down at floor %d.\n", capacity-currFilled, i);
                    }
                    upFlag = (floorUp[i] > 0) ? 1 : 0;
                    downFlag = (floorDown[i] > 0) ? 1 : 0;
                    if (currFilled == capacity) {
                        printf("Elevator is full. Moving to the next floor...\n");
                        sleep(1);
                        direction = (downFlag && !upFlag) ? -1 : 1;
                        if (!upFlag && !downFlag) {
                            direction = 0;
                        }
                        pthread_mutex_unlock(&lock);
                        break;
                    }
                    pthread_mutex_unlock(&lock);
                }
            }
        } else { //direction is 0
            sleep(1);
            direction = (upFlag && !downFlag) ? 1 : -1;
            if (!upFlag && !downFlag) {
                printf("No more passengers in the queue. Elevator is idle.\n");
                pthread_exit(NULL);
            }
        }
    }
}

int main() {
    printf("Enter number of floors: ");
    scanf("%d", &numOfFloors);

    floorUp = (int*) calloc(numOfFloors, sizeof(int));
    floorDown = (int*) calloc(numOfFloors, sizeof(int));

    printf("Enter elevator capacity: ");
    scanf("%d", &capacity);

    printf("Enter number of passengers waiting to go up on each floor: ");
    for (int i = 0; i < numOfFloors; i++) {
        scanf("%d", &floorUp[i]);
    }
    printf("Enter number of passengers waiting to go down on each floor: ");
    for (int i = 0; i < numOfFloors; i++) {
        scanf("%d", &floorDown[i]);
    }

    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&tid, NULL, elevator, NULL);

    pthread_join(tid, NULL);

    pthread_mutex_destroy(&lock);

    free(floorUp);
    free(floorDown);

    return 0;
}