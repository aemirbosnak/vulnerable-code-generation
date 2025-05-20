//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3
#define PEDESTRIAN_LIGHT 4
#define RED_LIGHT_TIME 30 // in seconds
#define YELLOW_LIGHT_TIME 3 // in seconds
#define GREEN_LIGHT_TIME 30 // in seconds
#define PEDESTRIAN_LIGHT_TIME 20 // in seconds
#define TOTAL_TIME (RED_LIGHT_TIME + YELLOW_LIGHT_TIME + GREEN_LIGHT_TIME + PEDESTRIAN_LIGHT_TIME)

sem_t light_semaphore;
int current_light = RED_LIGHT;
int pedestrian_light = PEDESTRIAN_LIGHT;

void *traffic_light_controller(void *arg) {
    while (1) {
        sem_wait(&light_semaphore);

        switch (current_light) {
            case RED_LIGHT:
                printf("Traffic light is red\n");
                sleep(RED_LIGHT_TIME);
                current_light = YELLOW_LIGHT;
                break;
            case YELLOW_LIGHT:
                printf("Traffic light is yellow\n");
                sleep(YELLOW_LIGHT_TIME);
                current_light = GREEN_LIGHT;
                break;
            case GREEN_LIGHT:
                printf("Traffic light is green\n");
                sleep(GREEN_LIGHT_TIME);
                current_light = RED_LIGHT;
                break;
            case PEDESTRIAN_LIGHT:
                printf("Pedestrian light is on\n");
                sleep(PEDESTRIAN_LIGHT_TIME);
                pedestrian_light =!pedestrian_light;
                break;
        }

        sem_post(&light_semaphore);
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    sem_init(&light_semaphore, 0, 1);

    pthread_t traffic_light_thread;
    pthread_create(&traffic_light_thread, NULL, traffic_light_controller, NULL);

    int choice;
    while (1) {
        printf("Press 1 to change the traffic light\n");
        printf("Press 2 to change the pedestrian light\n");
        printf("Press 3 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                current_light = (current_light + 1) % 4;
                break;
            case 2:
                pedestrian_light =!pedestrian_light;
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}