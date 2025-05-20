//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define LIGHT_COUNT 4
#define MAX_CMD_LEN 100

typedef struct {
    int id;
    int state; // 0 for OFF, 1 for ON
} Light;

typedef struct {
    int temperature; // in degree Celsius
} Thermostat;

Light lights[LIGHT_COUNT];
Thermostat thermostat;

// Function to control lights asynchronously
void* control_lights(void* arg) {
    while (1) {
        sleep(1);
        for (int i = 0; i < LIGHT_COUNT; i++) {
            if (lights[i].state) {
                printf("Light %d is ON\n", i + 1);
            } else {
                printf("Light %d is OFF\n", i + 1);
            }
        }
        printf("\n");
    }
    return NULL;
}

// Function to control thermostat asynchronously
void* control_thermostat(void* arg) {
    while (1) {
        sleep(3);
        printf("Thermostat is set to %d degrees Celsius\n", thermostat.temperature);
        printf("\n");
    }
    return NULL;
}

// Function to process commands from the user
void process_command(const char* command) {
    if (strncmp(command, "light", 5) == 0) {
        int light_num;
        sscanf(command, "light %d", &light_num);
        if (light_num >= 1 && light_num <= LIGHT_COUNT) {
            lights[light_num - 1].state = !lights[light_num - 1].state;
            printf("Toggled Light %d\n", light_num);
        } else {
            printf("Invalid light number. Please enter a number between 1 and %d.\n", LIGHT_COUNT);
        }
    } else if (strncmp(command, "set temp", 8) == 0) {
        sscanf(command, "set temp %d", &thermostat.temperature);
        printf("Thermostat set to %d degrees Celsius\n", thermostat.temperature);
    } else {
        printf("Unknown command. Available commands: light [1-4], set temp [value]\n");
    }
}

int main() {
    pthread_t light_thread, thermostat_thread;

    // Initialize lights
    for (int i = 0; i < LIGHT_COUNT; i++) {
        lights[i].id = i + 1;
        lights[i].state = 0; // Initially OFF
    }
    
    // Initialize thermostat
    thermostat.temperature = 20; // Default temperature

    // Create threads for light control and thermostat
    pthread_create(&light_thread, NULL, control_lights, NULL);
    pthread_create(&thermostat_thread, NULL, control_thermostat, NULL);

    // Command input loop
    char command[MAX_CMD_LEN];
    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        process_command(command);
    }

    // Cleanup (will never reach here due to infinite loop)
    pthread_cancel(light_thread);
    pthread_cancel(thermostat_thread);
    pthread_join(light_thread, NULL);
    pthread_join(thermostat_thread, NULL);

    return 0;
}