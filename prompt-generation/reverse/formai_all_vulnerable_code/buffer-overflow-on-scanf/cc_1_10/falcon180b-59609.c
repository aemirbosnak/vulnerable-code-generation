//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

#define DELAY 2

// Function to print current state of traffic light
void print_state(int state) {
    switch(state) {
        case RED:
            printf("Traffic light is RED\n");
            break;
        case YELLOW:
            printf("Traffic light is YELLOW\n");
            break;
        case GREEN:
            printf("Traffic light is GREEN\n");
            break;
        default:
            printf("Invalid state\n");
            break;
    }
}

// Function to change state of traffic light
void change_state(int* state) {
    if(*state == RED) {
        *state = GREEN;
    }
    else if(*state == GREEN) {
        *state = YELLOW;
    }
    else if(*state == YELLOW) {
        *state = RED;
    }
}

// Function to simulate traffic light
void traffic_light(int duration) {
    int state = RED;
    while(duration-- > 0) {
        print_state(state);
        sleep(DELAY);
        change_state(&state);
    }
}

int main() {
    int duration;
    printf("Enter duration of traffic light (in seconds): ");
    scanf("%d", &duration);

    srand(time(NULL));
    int seed = rand();
    printf("Random seed: %d\n", seed);

    traffic_light(duration);

    return 0;
}