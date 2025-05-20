//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

int light_state = RED_LIGHT;
int light_duration[3] = {30, 5, 30};
int light_index = 0;

void *traffic_light(void *param) {
    while (1) {
        if (light_state == RED_LIGHT) {
            printf("Red Light\n");
        } else if (light_state == YELLOW_LIGHT) {
            printf("Yellow Light\n");
        } else {
            printf("Green Light\n");
        }

        sleep(light_duration[light_index]);

        if (light_index == 2) {
            light_index = 0;
        } else {
            light_index++;
        }
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    printf("Starting Traffic Light\n");

    pthread_create(&thread_id, NULL, traffic_light, NULL);

    while (1) {
        printf("Press 1 to stop the traffic light\n");
        scanf("%d", &light_state);

        if (light_state == 1) {
            break;
        }
    }

    pthread_join(thread_id, NULL);

    printf("Stopping Traffic Light\n");

    return 0;
}