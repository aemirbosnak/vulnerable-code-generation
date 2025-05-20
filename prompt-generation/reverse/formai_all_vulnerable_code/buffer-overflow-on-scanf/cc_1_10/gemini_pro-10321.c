//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the possible states of a light
enum light_state {
    OFF,
    ON,
    BLINKING
};

// Define the possible commands
enum command {
    TURN_ON,
    TURN_OFF,
    TOGGLE,
    BLINK,
    STATUS
};

// Define the structure of a light
struct light {
    int id;
    enum light_state state;
};

// Define the array of lights
struct light lights[MAX_LIGHTS];

// Initialize the lights
void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].state = OFF;
    }
}

// Turn on a light
void turn_on(int light_id) {
    if (light_id < 0 || light_id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", light_id);
        return;
    }

    lights[light_id].state = ON;
    printf("Light %d is now on.\n", light_id);
}

// Turn off a light
void turn_off(int light_id) {
    if (light_id < 0 || light_id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", light_id);
        return;
    }

    lights[light_id].state = OFF;
    printf("Light %d is now off.\n", light_id);
}

// Toggle a light
void toggle(int light_id) {
    if (light_id < 0 || light_id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", light_id);
        return;
    }

    if (lights[light_id].state == ON) {
        lights[light_id].state = OFF;
        printf("Light %d is now off.\n", light_id);
    } else {
        lights[light_id].state = ON;
        printf("Light %d is now on.\n", light_id);
    }
}

// Blink a light
void blink(int light_id) {
    if (light_id < 0 || light_id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", light_id);
        return;
    }

    lights[light_id].state = BLINKING;
    printf("Light %d is now blinking.\n", light_id);
}

// Get the status of a light
void get_status(int light_id) {
    if (light_id < 0 || light_id >= MAX_LIGHTS) {
        printf("Invalid light ID: %d\n", light_id);
        return;
    }

    switch (lights[light_id].state) {
        case OFF:
            printf("Light %d is off.\n", light_id);
            break;
        case ON:
            printf("Light %d is on.\n", light_id);
            break;
        case BLINKING:
            printf("Light %d is blinking.\n", light_id);
            break;
    }
}

// Handle a command
void handle_command(enum command cmd, int light_id) {
    switch (cmd) {
        case TURN_ON:
            turn_on(light_id);
            break;
        case TURN_OFF:
            turn_off(light_id);
            break;
        case TOGGLE:
            toggle(light_id);
            break;
        case BLINK:
            blink(light_id);
            break;
        case STATUS:
            get_status(light_id);
            break;
    }
}

// Simulate the lights blinking
void simulate_blinking() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].state == BLINKING) {
            if (rand() % 2 == 0) {
                lights[i].state = OFF;
            } else {
                lights[i].state = ON;
            }
        }
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the lights
    init_lights();

    // Handle commands from the user
    while (1) {
        // Get the command and light ID from the user
        int cmd, light_id;
        printf("Enter command (0: turn on, 1: turn off, 2: toggle, 3: blink, 4: status): ");
        scanf("%d", &cmd);
        printf("Enter light ID (0-%d): ", MAX_LIGHTS - 1);
        scanf("%d", &light_id);

        // Handle the command
        handle_command((enum command)cmd, light_id);

        // Simulate the lights blinking
        simulate_blinking();
    }

    return 0;
}