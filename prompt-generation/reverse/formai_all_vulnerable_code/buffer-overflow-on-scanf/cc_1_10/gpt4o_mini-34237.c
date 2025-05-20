//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define LIGHTS_ON 1
#define LIGHTS_OFF 0
#define TEMP_SET 22
#define CAMERA_ON 1
#define CAMERA_OFF 0

bool lightsStatus = LIGHTS_OFF;
int roomTemperature = 20; // Default temperature
bool cameraStatus = CAMERA_OFF;

pthread_mutex_t lock;

void* controlLights(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        if (lightsStatus) {
            printf("Lights are ON\n");
        } else {
            printf("Lights are OFF\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(2);
    }
}

void* controlThermostat(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        printf("Current temperature: %d°C\n", roomTemperature);
        pthread_mutex_unlock(&lock);
        sleep(5);
    }
}

void* controlCamera(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        if (cameraStatus) {
            printf("Security Camera is ON\n");
        } else {
            printf("Security Camera is OFF\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(3);
    }
}

void updateLights() {
    pthread_mutex_lock(&lock);
    lightsStatus = !lightsStatus; // Toggle lights
    pthread_mutex_unlock(&lock);
}

void updateThermostat(int newTemp) {
    pthread_mutex_lock(&lock);
    roomTemperature = newTemp;
    pthread_mutex_unlock(&lock);
}

void updateCamera() {
    pthread_mutex_lock(&lock);
    cameraStatus = !cameraStatus; // Toggle camera
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t lightsThread, thermostatThread, cameraThread;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&lightsThread, NULL, controlLights, NULL);
    pthread_create(&thermostatThread, NULL, controlThermostat, NULL);
    pthread_create(&cameraThread, NULL, controlCamera, NULL);

    char command;
    int newTemp;

    printf("Smart Home Automation System\n");
    printf("Commands:\n");
    printf("l: Toggle lights\n");
    printf("t <temp>: Set temperature\n");
    printf("c: Toggle camera\n");
    printf("q: Quit\n");

    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        if (command == 'l') {
            updateLights();
        } else if (command == 't') {
            printf("Enter new temperature: ");
            scanf("%d", &newTemp);
            updateThermostat(newTemp);
        } else if (command == 'c') {
            updateCamera();
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    pthread_cancel(lightsThread);
    pthread_cancel(thermostatThread);
    pthread_cancel(cameraThread);

    pthread_join(lightsThread, NULL);
    pthread_join(thermostatThread, NULL);
    pthread_join(cameraThread, NULL);

    pthread_mutex_destroy(&lock);
    printf("Exiting Smart Home Automation System.\n");

    return 0;
}