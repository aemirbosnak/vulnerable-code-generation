//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 15
#define PEDESTRIAN_LIGHT_DURATION 5
#define NUM_CYCLES 10

// Function prototypes
void traffic_light_controller(int num_cycles);
void print_lights();

int main() {
    int num_cycles;

    printf("Enter the number of cycles: ");
    scanf("%d", &num_cycles);

    traffic_light_controller(num_cycles);

    return 0;
}

void traffic_light_controller(int num_cycles) {
    int cycle_count = 0;
    int light_state = 0; // 0 = red, 1 = yellow, 2 = green, 3 = pedestrian

    while (cycle_count < num_cycles) {
        switch (light_state) {
            case 0: // Red light
                printf("Red light is on!\n");
                usleep(RED_LIGHT_DURATION * 1000000); // Sleep for 10 seconds
                light_state = 1; // Transition to yellow light
                break;
            case 1: // Yellow light
                printf("Yellow light is on!\n");
                usleep(YELLOW_LIGHT_DURATION * 1000000); // Sleep for 5 seconds
                light_state = 2; // Transition to green light
                break;
            case 2: // Green light
                printf("Green light is on!\n");
                usleep(GREEN_LIGHT_DURATION * 1000000); // Sleep for 15 seconds
                light_state = 3; // Transition to pedestrian light
                break;
            case 3: // Pedestrian light
                printf("Pedestrian light is on!\n");
                usleep(PEDESTRIAN_LIGHT_DURATION * 1000000); // Sleep for 5 seconds
                light_state = 0; // Transition back to red light
                break;
        }
        cycle_count++;
    }
}

void print_lights() {
    printf("--------------------\n");
    printf("|                   |\n");
    printf("|      RED LIGHT    |\n");
    printf("|                   |\n");
    printf("--------------------\n");
}