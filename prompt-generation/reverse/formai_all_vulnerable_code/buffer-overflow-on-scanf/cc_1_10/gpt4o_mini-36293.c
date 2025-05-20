//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

#define HEATER_ON 1
#define HEATER_OFF 0

#define TEMP_THRESHOLD 22 // Temperature threshold for heater

typedef struct {
    int light_status;
    int heater_status;
    float current_temperature;
    pthread_mutex_t lock;
} SmartHomeSystem;

void* temperature_monitor(void* arg) {
    SmartHomeSystem* system = (SmartHomeSystem*)arg;
    while (1) {
        pthread_mutex_lock(&system->lock);
        
        // Simulate temperature change
        system->current_temperature = (float)(rand() % 30); // Random temperature between 0 and 29
        printf("Current Temperature: %.2f°C\n", system->current_temperature);
        
        // Check if the heater needs to be turned on or off
        if (system->current_temperature < TEMP_THRESHOLD) {
            system->heater_status = HEATER_ON;
            printf("Heater is ON\n");
        } else {
            system->heater_status = HEATER_OFF;
            printf("Heater is OFF\n");
        }
        
        pthread_mutex_unlock(&system->lock);
        sleep(5); // Sleep for 5 seconds before checking again
    }
    return NULL;
}

void* light_control(void* arg) {
    SmartHomeSystem* system = (SmartHomeSystem*)arg;
    char command[10];
    while (1) {
        fflush(stdout);
        printf("Enter 'on' to turn on the light or 'off' to turn off the light: ");
        scanf("%s", command);

        pthread_mutex_lock(&system->lock);
        if (strcmp(command, "on") == 0) {
            system->light_status = LIGHT_ON;
            printf("Light is ON\n");
        } else if (strcmp(command, "off") == 0) {
            system->light_status = LIGHT_OFF;
            printf("Light is OFF\n");
        } else {
            printf("Invalid command. Please enter 'on' or 'off'.\n");
        }
        pthread_mutex_unlock(&system->lock);
    }
    return NULL;
}

int main() {
    SmartHomeSystem system;
    system.light_status = LIGHT_OFF;
    system.heater_status = HEATER_OFF;
    system.current_temperature = 0.0;
    
    pthread_mutex_init(&system.lock, NULL);
    
    pthread_t temp_thread, light_thread;
    
    // Create threads for temperature monitoring and light control
    pthread_create(&temp_thread, NULL, temperature_monitor, &system);
    pthread_create(&light_thread, NULL, light_control, &system);
    
    // Join threads (although they run indefinitely)
    pthread_join(temp_thread, NULL);
    pthread_join(light_thread, NULL);
    
    // Cleanup
    pthread_mutex_destroy(&system.lock);
    
    return 0;
}