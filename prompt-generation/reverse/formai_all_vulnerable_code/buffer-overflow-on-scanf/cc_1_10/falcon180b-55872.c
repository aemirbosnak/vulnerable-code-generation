//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define NUM_LANES 4

// Initialize the traffic light to red in all lanes
void init_traffic_light(int traffic_light[NUM_LANES]) {
    for (int i = 0; i < NUM_LANES; i++) {
        traffic_light[i] = RED;
    }
}

// Change the traffic light in a lane to the next color
void change_traffic_light(int traffic_light[NUM_LANES], int lane) {
    switch (traffic_light[lane]) {
        case RED:
            traffic_light[lane] = GREEN;
            break;
        case YELLOW:
            traffic_light[lane] = RED;
            break;
        case GREEN:
            traffic_light[lane] = YELLOW;
            break;
        default:
            break;
    }
}

// Print the current state of the traffic light
void print_traffic_light(int traffic_light[NUM_LANES]) {
    for (int i = 0; i < NUM_LANES; i++) {
        switch (traffic_light[i]) {
            case RED:
                printf("R");
                break;
            case YELLOW:
                printf("Y");
                break;
            case GREEN:
                printf("G");
                break;
            default:
                break;
        }
    }
    printf("\n");
}

// Main function
int main() {
    int traffic_light[NUM_LANES] = {RED, RED, RED, RED}; // Initialize the traffic light to red in all lanes
    int lane = 0; // Start with the first lane
    bool quit = false; // Flag to exit the program

    srand(time(NULL)); // Seed the random number generator with the current time

    while (!quit) {
        print_traffic_light(traffic_light); // Print the current state of the traffic light

        int random_lane = rand() % NUM_LANES; // Choose a random lane
        if (random_lane!= lane) {
            change_traffic_light(traffic_light, random_lane); // Change the traffic light in the random lane
            lane = random_lane; // Update the current lane
        }

        int user_input;
        scanf("%d", &user_input);
        if (user_input == 'q') {
            quit = true;
        }
    }

    return 0;
}