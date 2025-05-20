//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define DELAY_TIME 1000 // in milliseconds

int lights[NUM_THREADS];
int turn_on_flag[NUM_THREADS] = {0};

void *turn_on_light(void *arg) {
    int idx = *((int *) arg);
    printf("Turning on light %d\n", idx);
    lights[idx] = 1;
    sleep(DELAY_TIME);
    turn_on_flag[idx] = 1;
    return NULL;
}

void *turn_off_light(void *arg) {
    int idx = *((int *) arg);
    printf("Turning off light %d\n", idx);
    lights[idx] = 0;
    sleep(DELAY_TIME);
    turn_on_flag[idx] = 0;
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        lights[i] = 0;
        turn_on_flag[i] = 0;
    }

    printf("Enter 1 to turn on light, 0 to turn off light: ");
    scanf("%d", &i);
    printf("Enter the light number (1-3): ");
    scanf("%d", &i);

    if (i == 1) {
        pthread_create(&threads[0], NULL, turn_on_light, (void *)&i);
    } else if (i == 0) {
        pthread_create(&threads[0], NULL, turn_off_light, (void *)&i);
    } else {
        printf("Invalid option\n");
        return 0;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}