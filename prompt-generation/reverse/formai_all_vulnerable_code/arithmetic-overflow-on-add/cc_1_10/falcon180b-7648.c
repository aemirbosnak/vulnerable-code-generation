//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define RED_LIGHT_SECONDS 20
#define YELLOW_LIGHT_SECONDS 5
#define GREEN_LIGHT_SECONDS 20

typedef struct {
    int light;
    time_t start_time;
    time_t end_time;
} Light;

Light lights[3] = {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}};

void change_light(int light_number, int new_light) {
    lights[light_number].light = new_light;
    lights[light_number].start_time = time(NULL);
    lights[light_number].end_time = lights[light_number].start_time + (new_light * GREEN_LIGHT_SECONDS);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        int light = rand() % 3;
        change_light(light, rand() % 3);
    }

    while (1) {
        for (int i = 0; i < 3; i++) {
            if (lights[i].light == 0) {
                change_light(i, 1);
            } else if (lights[i].light == 1) {
                if (difftime(time(NULL), lights[i].end_time) <= 0) {
                    change_light(i, 2);
                }
            } else if (lights[i].light == 2) {
                if (difftime(time(NULL), lights[i].end_time) <= 0) {
                    change_light(i, 0);
                }
            }
        }
        sleep(1);
    }

    return 0;
}