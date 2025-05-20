//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_CARS 5
#define NUM_LANES 3
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define LIGHT_CHANGE_DELAY 5000 // 5 seconds

int light_state[NUM_LANES] = {RED_LIGHT, RED_LIGHT, RED_LIGHT};
int current_lane = 0;
int num_cars_waiting = 0;

sem_t light_sem;
sem_t car_sem;

void init_semaphores() {
    sem_init(&light_sem, 0, 1);
    sem_init(&car_sem, 0, NUM_CARS);
}

void change_light() {
    int next_lane = (current_lane + 1) % NUM_LANES;
    light_state[next_lane] = GREEN_LIGHT;
    light_state[current_lane] = RED_LIGHT;
    current_lane = next_lane;
    printf("Light changed to green for lane %d\n", next_lane);
}

void wait_for_green_light(int lane) {
    sem_wait(&light_sem);
    while (light_state[lane]!= GREEN_LIGHT) {
        printf("Car waiting at lane %d\n", lane);
        sleep(1);
    }
    printf("Car passed through lane %d\n", lane);
    sem_post(&light_sem);
}

void* car_thread(void* arg) {
    int lane = *(int*) arg;
    wait_for_green_light(lane);
    return NULL;
}

int main() {
    init_semaphores();
    pthread_t threads[NUM_CARS];

    for (int i = 0; i < NUM_CARS; i++) {
        pthread_create(&threads[i], NULL, car_thread, (void*) &i);
        printf("Car arrived at lane %d\n", i);
        sleep(1);
        num_cars_waiting++;
    }

    while (num_cars_waiting > 0) {
        change_light();
        sleep(LIGHT_CHANGE_DELAY);
    }

    return 0;
}