//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define PEDESTRIAN 3
#define TRAFFIC_LIGHT_DELAY 5

enum traffic_light_state {
    STOP,
    GO
};

void traffic_light_controller(int traffic_light_id) {
    enum traffic_light_state state;
    int counter = 0;

    switch (traffic_light_id) {
        case 1:
            state = STOP;
            break;
        case 2:
            state = GO;
            break;
        case 3:
            state = STOP;
            break;
        default:
            state = STOP;
            break;
    }

    while (1) {
        if (state == STOP) {
            printf("Traffic light %d is red\n", traffic_light_id);
            fflush(stdout);
        } else if (state == GO) {
            printf("Traffic light %d is green\n", traffic_light_id);
            fflush(stdout);
        }

        counter++;

        if (counter == TRAFFIC_LIGHT_DELAY) {
            if (state == STOP) {
                state = GO;
            } else if (state == GO) {
                state = STOP;
            }

            counter = 0;
        }

        sleep(1);
    }
}

int main() {
    int traffic_light_id;

    printf("Enter the traffic light ID: ");
    scanf("%d", &traffic_light_id);

    traffic_light_controller(traffic_light_id);

    return 0;
}