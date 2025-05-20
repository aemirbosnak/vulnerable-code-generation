//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_LIGHTS 5
#define BUFFER_SIZE 256

typedef enum { OFF, ON } LightState;

typedef struct {
    int id;
    LightState state;
    pthread_mutex_t lock;
} SmartLight;

SmartLight lights[NUM_LIGHTS];

void *control_light(void *arg) {
    SmartLight *light = (SmartLight *)arg;

    while (1) {
        pthread_mutex_lock(&light->lock);
        printf("Light %d is currently %s\n", light->id, light->state == ON ? "ON" : "OFF");
        pthread_mutex_unlock(&light->lock);
        sleep(1);
    }
    
    return NULL;
}

void toggle_light(SmartLight *light) {
    pthread_mutex_lock(&light->lock);
    light->state = (light->state == ON) ? OFF : ON;
    printf("Light %d toggled to %s\n", light->id, light->state == ON ? "ON" : "OFF");
    pthread_mutex_unlock(&light->lock);
}

void command_listener() {
    char buffer[BUFFER_SIZE];
    
    while (1) {
        printf("Enter command (toggle <light_id> or exit): ");
        if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
            int light_id;
            if (sscanf(buffer, "toggle %d", &light_id) == 1 && light_id >= 0 && light_id < NUM_LIGHTS) {
                toggle_light(&lights[light_id]);
            } else if (strncmp(buffer, "exit", 4) == 0) {
                printf("Exiting command listener.\n");
                return;
            } else {
                printf("Invalid command. Please try again.\n");
            }
        } else {
            printf("Error reading input.\n");
        }
    }
}

int main() {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].state = OFF;
        pthread_mutex_init(&lights[i].lock, NULL);
        
        pthread_t thread;
        pthread_create(&thread, NULL, control_light, (void *)&lights[i]);
    }

    command_listener();

    for (int i = 0; i < NUM_LIGHTS; i++) {
        pthread_mutex_destroy(&lights[i].lock);
    }

    return 0;
}