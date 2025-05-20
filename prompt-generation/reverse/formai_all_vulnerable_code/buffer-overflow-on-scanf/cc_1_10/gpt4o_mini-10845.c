//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef enum { RED, GREEN, YELLOW } LightState;

typedef struct {
    LightState state;
    int duration; // Duration for each light state in seconds
} TrafficLight;

TrafficLight lights[3]; // For three directions: North-South, East-West, and Pedestrian

void *controlTrafficLights(void *arg) {
    while (1) {
        // North-South Green Light
        lights[0].state = GREEN;
        printf("\nNorth-South Light: GREEN\n");
        sleep(lights[0].duration);

        // North-South Yellow Light
        lights[0].state = YELLOW;
        printf("North-South Light: YELLOW\n");
        sleep(lights[0].duration);

        // North-South Red Light
        lights[0].state = RED;
        printf("North-South Light: RED\n");
        sleep(lights[0].duration);

        // East-West Green Light
        lights[1].state = GREEN;
        printf("East-West Light: GREEN\n");
        sleep(lights[1].duration);

        // East-West Yellow Light
        lights[1].state = YELLOW;
        printf("East-West Light: YELLOW\n");
        sleep(lights[1].duration);

        // East-West Red Light
        lights[1].state = RED;
        printf("East-West Light: RED\n");
        sleep(lights[1].duration);

        // Pedestrian Light Green
        lights[2].state = GREEN;
        printf("Pedestrian Light: GREEN (walk)\n");
        sleep(lights[2].duration);

        // Pedestrian Light Red
        lights[2].state = RED;
        printf("Pedestrian Light: RED (stop)\n");
        sleep(lights[2].duration);
    }
    return NULL;
}

void initializeTrafficLights() {
    lights[0].duration = 5;   // 5 seconds for North-South
    lights[1].duration = 5;   // 5 seconds for East-West
    lights[2].duration = 5;   // 5 seconds for Pedestrian
    lights[0].state = RED;     // Initialize states
    lights[1].state = RED;
    lights[2].state = RED;
}

int main() {
    pthread_t trafficThread;

    // Initialize the traffic lights
    initializeTrafficLights();

    // Create a thread to control the traffic lights
    if (pthread_create(&trafficThread, NULL, controlTrafficLights, NULL) != 0) {
        fprintf(stderr, "Error creating traffic control thread\n");
        return EXIT_FAILURE;
    }

    // Main loop for user input and display
    while (1) {
        printf("\n\tTraffic Light Controller");
        printf("\n1. Show Current Status of Lights");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nCurrent Status of Lights:\n");
                printf("North-South Light: %s\n", lights[0].state == GREEN ? "GREEN" : lights[0].state == YELLOW ? "YELLOW" : "RED");
                printf("East-West Light: %s\n", lights[1].state == GREEN ? "GREEN" : lights[1].state == YELLOW ? "YELLOW" : "RED");
                printf("Pedestrian Light: %s\n", lights[2].state == GREEN ? "GREEN" : "RED");
                break;
            case 2:
                printf("Exiting...\n");
                pthread_cancel(trafficThread);
                pthread_join(trafficThread, NULL);
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}