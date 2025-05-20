//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Creating a structure to hold the light state
    struct light_state {
        int brightness;
        int color;
    };

    // Creating an array of light states
    struct light_state lights[10];

    // Initializing the first light state
    lights[0].brightness = 50;
    lights[0].color = "white";

    // Getting the user input for the light control
    printf("Enter the light number to control (0-9): ");
    int light_num;
    scanf("%d", &light_num);

    // Setting the light state based on user input
    if (light_num == 0) {
        lights[0].brightness = 100;
        lights[0].color = "red";
    } else if (light_num == 1) {
        lights[1].brightness = 75;
        lights[1].color = "green";
    } else if (light_num == 2) {
        lights[2].brightness = 60;
        lights[2].color = "blue";
    } else if (light_num == 3) {
        lights[3].brightness = 50;
        lights[3].color = "yellow";
    } else if (light_num == 4) {
        lights[4].brightness = 40;
        lights[4].color = "purple";
    } else if (light_num == 5) {
        lights[5].brightness = 30;
        lights[5].color = "orange";
    } else if (light_num == 6) {
        lights[6].brightness = 20;
        lights[6].color = "pink";
    } else if (light_num == 7) {
        lights[7].brightness = 10;
        lights[7].color = "black";
    } else if (light_num == 8) {
        lights[8].brightness = 5;
        lights[8].color = "gray";
    } else if (light_num == 9) {
        lights[9].brightness = 0;
        lights[9].color = "silver";
    } else {
        printf("Invalid light number.\n");
        return 1;
    }

    // Printing the updated light states
    printf("Updated light states:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d, %s\n", i + 1, lights[i].brightness, lights[i].color);
    }

    // Returning 0 to indicate success
    return 0;
}