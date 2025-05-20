//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <semaphore.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

#define NUM_LANES 4
#define NUM_ROUNDS 10
#define DURATION 5

#define SEM_ID 0x1234

int main() {

    int i, j;
    int lane_status[NUM_LANES] = {RED, RED, RED, RED};
    int round_count = 0;
    int *lane_semaphore = (int *)malloc(NUM_LANES * sizeof(int));

    if (lane_semaphore == NULL) {
        printf("Error allocating memory for semaphores\n");
        exit(1);
    }

    for (i = 0; i < NUM_LANES; i++) {
        sem_init(&lane_semaphore[i], 0, 1);
    }

    srand(time(NULL));

    for (j = 0; j < NUM_ROUNDS; j++) {

        for (i = 0; i < NUM_LANES; i++) {

            if (lane_status[i] == GREEN) {
                lane_status[i] = RED;
            } else if (lane_status[i] == YELLOW) {
                lane_status[i] = GREEN;
            } else {
                lane_status[i] = YELLOW;
            }

            printf("Lane %d: ", i + 1);
            switch (lane_status[i]) {
                case RED:
                    printf("Red\n");
                    break;
                case YELLOW:
                    printf("Yellow\n");
                    break;
                case GREEN:
                    printf("Green\n");
                    break;
            }

        }

        printf("\n");

        for (i = 0; i < NUM_LANES; i++) {
            sem_wait(&lane_semaphore[i]);
        }

        printf("Round %d completed\n", round_count + 1);
        round_count++;

        for (i = 0; i < NUM_LANES; i++) {
            sem_post(&lane_semaphore[i]);
        }

        sleep(DURATION);

    }

    for (i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lane_semaphore[i]);
    }

    free(lane_semaphore);

    return 0;

}