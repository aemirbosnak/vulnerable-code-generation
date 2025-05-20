//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define NUM_SENSORS 4
#define NUM_ACTUATORS 3

int main() {

    int sensor_values[NUM_SENSORS];
    int actuator_states[NUM_ACTUATORS];

    for (int i = 0; i < NUM_SENSORS; i++) {
        sensor_values[i] = rand() % 100;
    }

    for (int i = 0; i < NUM_ACTUATORS; i++) {
        actuator_states[i] = rand() % 2;
    }

    int user_input;

    while (1) {
        printf("Enter 1 to view sensor values, 2 to control actuators, or 0 to exit: ");
        scanf("%d", &user_input);

        if (user_input == 0) {
            break;
        }

        if (user_input == 1) {
            printf("Sensor values:\n");
            for (int i = 0; i < NUM_SENSORS; i++) {
                printf("Sensor %d: %d\n", i+1, sensor_values[i]);
            }
        } else if (user_input == 2) {
            printf("Actuator states:\n");
            for (int i = 0; i < NUM_ACTUATORS; i++) {
                printf("Actuator %d: %s\n", i+1, actuator_states[i]? "On" : "Off");
            }

            printf("Enter the actuator number you want to control (1-3): ");
            scanf("%d", &user_input);

            printf("Enter 1 to turn on, 0 to turn off: ");
            scanf("%d", &user_input);

            if (user_input == 1) {
                actuator_states[user_input-1] = 1;
            } else {
                actuator_states[user_input-1] = 0;
            }
        }
    }

    return 0;
}