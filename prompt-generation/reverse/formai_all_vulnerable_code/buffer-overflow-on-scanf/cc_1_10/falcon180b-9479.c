//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3
#define PEDESTRIAN_LIGHT 4
#define NUM_LIGHTS 4

typedef struct {
    int current_light;
    int next_light;
    int duration;
    int timer;
} Light;

Light lights[NUM_LIGHTS];

void init_lights() {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].current_light = 0;
        lights[i].next_light = 0;
        lights[i].duration = 0;
        lights[i].timer = 0;
    }
}

void update_lights() {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        if (lights[i].current_light!= lights[i].next_light) {
            lights[i].current_light = lights[i].next_light;
            lights[i].timer = lights[i].duration;
        } else if (lights[i].timer > 0) {
            lights[i].timer--;
        } else {
            lights[i].current_light = 0;
            lights[i].next_light = 0;
            lights[i].duration = 0;
            lights[i].timer = 0;
        }
    }
}

void set_light(int light_num, int new_light) {
    lights[light_num].next_light = new_light;
}

int main() {
    init_lights();

    while (true) {
        system("clear");
        printf("Current traffic light settings:\n");
        for (int i = 0; i < NUM_LIGHTS; i++) {
            printf("Light %d: %s\n", i + 1, lights[i].current_light == GREEN_LIGHT? "Green" :
                    lights[i].current_light == RED_LIGHT? "Red" :
                    lights[i].current_light == YELLOW_LIGHT? "Yellow" :
                    lights[i].current_light == PEDESTRIAN_LIGHT? "Pedestrian" : "Unknown");
        }

        int choice;
        printf("\nEnter your choice:\n1. Set light 1\n2. Set light 2\n3. Set light 3\n4. Set light 4\n5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                set_light(0, GREEN_LIGHT);
                break;
            case 2:
                set_light(1, GREEN_LIGHT);
                break;
            case 3:
                set_light(2, GREEN_LIGHT);
                break;
            case 4:
                set_light(3, GREEN_LIGHT);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        update_lights();
        sleep(1);
    }

    return 0;
}