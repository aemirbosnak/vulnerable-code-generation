//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define colors for traffic lights
#define GREEN "Green"
#define YELLOW "Yellow"
#define RED "Red"

// Define a function to control the traffic light
void control_traffic_light(int light) {
    int i;
    char color[4];

    switch (light) {
        case 0:
            // Green light
            color[0] = GREEN[0];
            color[1] = GREEN[1];
            color[2] = GREEN[2];
            color[3] = GREEN[3];
            break;
        case 1:
            // Yellow light
            color[0] = YELLOW[0];
            color[1] = YELLOW[1];
            color[2] = YELLOW[2];
            color[3] = YELLOW[3];
            break;
        case 2:
            // Red light
            color[0] = RED[0];
            color[1] = RED[1];
            color[2] = RED[2];
            color[3] = RED[3];
            break;
        default:
            printf("Invalid light state\n");
            break;
    }

    // Print the color of the traffic light
    printf("%s\n", color);
}

int main() {
    int light = 0; // Default light state is Green
    int choice;
    char input[2];

    while (1) {
        printf("Select a light state (0 - Green, 1 - Yellow, 2 - Red): ");
        scanf("%s", input);
        sscanf(input, "%d", &choice);

        switch (choice) {
            case 0:
                light = 0;
                break;
            case 1:
                light = 1;
                break;
            case 2:
                light = 2;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        control_traffic_light(light);
    }

    return 0;
}