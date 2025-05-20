//FormAI DATASET v1.0 Category: Smart home automation ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

/* Function to turn on/off lights */
void toggle_lights(bool state) {
    if (state) {
        printf("Lights turned on\n");
    } else {
        printf("Lights turned off\n");
    }
}

/* Function to adjust thermostat */
void adjust_thermostat(int temperature) {
    if (temperature > 25) {
        printf("Temperature too high\n");
    } else if (temperature < 18) {
        printf("Temperature too low\n");
    } else {
        printf("Temperature adjusted to %d\n", temperature);
    }
}

/* Function to lock/unlock doors */
void toggle_doors(bool state) {
    if (state) {
        printf("Doors locked\n");
    } else {
        printf("Doors unlocked\n");
    }
}

int main() {
    /* Initialize variables */
    bool lights_on = false;
    int temperature = 22;
    bool doors_locked = true;

    /* Welcome message */
    printf("Welcome to your smart home!\n");

    /* Menu */
    int choice;
    do {
        printf("Please select an option:\n");
        printf("1. Toggle lights\n");
        printf("2. Adjust thermostat\n");
        printf("3. Toggle doors\n");
        printf("4. Quit\n");

        /* User input */
        scanf("%d", &choice);

        /* Perform action based on user input */
        switch (choice) {
            case 1:
                lights_on = !lights_on;  /* Toggle lights */
                toggle_lights(lights_on);
                break;
            case 2:
                printf("Enter desired temperature: ");
                scanf("%d", &temperature);
                adjust_thermostat(temperature);  /* Adjust thermostat */
                break;
            case 3:
                doors_locked = !doors_locked;  /* Toggle doors */
                toggle_doors(doors_locked);
                break;
            case 4:
                printf("Exiting smart home program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}