//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

void traffic_light_controller(int light_state, int light_duration_seconds, int pedestrian_duration_seconds) {
    time_t start_time = time(NULL);
    time_t current_time = start_time;
    
    while (current_time - start_time < light_duration_seconds) {
        switch (light_state) {
            case RED_LIGHT:
                printf("Red light is on...\n");
                break;
            case YELLOW_LIGHT:
                printf("Yellow light is on...\n");
                break;
            case GREEN_LIGHT:
                printf("Green light is on...\n");
                break;
            default:
                printf("Invalid light state!\n");
                break;
        }
        
        current_time = time(NULL);
    }
    
    printf("Pedestrian crossing...\n");
    current_time = start_time;
    
    while (current_time - start_time < pedestrian_duration_seconds) {
        printf("Pedestrians are crossing...\n");
        current_time = time(NULL);
    }
    
    printf("Traffic light controller program ended.\n");
}

int main() {
    int light_state = RED_LIGHT;
    int light_duration_seconds = 60;
    int pedestrian_duration_seconds = 20;
    
    srand(time(NULL));
    
    while (true) {
        int next_light_state = rand() % 3;
        
        if (next_light_state == light_state) {
            printf("Traffic light controller program is in a loop.\n");
        } else {
            light_state = next_light_state;
            printf("Traffic light controller program is changing state.\n");
        }
        
        traffic_light_controller(light_state, light_duration_seconds, pedestrian_duration_seconds);
        
        if (light_state == GREEN_LIGHT) {
            printf("Traffic light controller program is waiting for the next green light.\n");
        } else {
            printf("Traffic light controller program is waiting for the next red light.\n");
        }
    }
    
    return 0;
}