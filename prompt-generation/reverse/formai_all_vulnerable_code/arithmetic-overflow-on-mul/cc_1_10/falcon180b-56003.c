//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_TIME 10
#define YELLOW_TIME 3
#define RED_TIME 20
#define TOTAL_TIME (GREEN_TIME + YELLOW_TIME + RED_TIME)

void traffic_light_controller(int duration) {
    int green_time = GREEN_TIME;
    int yellow_time = YELLOW_TIME;
    int red_time = RED_TIME;
    int current_time = 0;
    char *light_state = "green";

    while (current_time < duration) {
        switch (light_state[0]) {
            case 'g':
                printf("Green light is on.\n");
                if (current_time == green_time - 1) {
                    printf("Yellow light is on.\n");
                    light_state = "yellow";
                }
                break;
            case 'y':
                printf("Yellow light is on.\n");
                if (current_time == yellow_time - 1) {
                    printf("Red light is on.\n");
                    light_state = "red";
                }
                break;
            case 'r':
                printf("Red light is on.\n");
                if (current_time == red_time - 1) {
                    printf("Green light is on.\n");
                    light_state = "green";
                }
                break;
        }
        current_time++;
        sleep(1);
    }
}

int main() {
    int duration = 0;

    printf("Enter the duration of the traffic light cycle in seconds: ");
    scanf("%d", &duration);

    srand(time(NULL));
    int random_duration = rand() % (duration * 2) + 1;

    printf("The traffic light cycle will last for %d seconds.\n", random_duration);
    traffic_light_controller(random_duration);

    return 0;
}