//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define MAX_LIGHTS 5
#define MAX_TEMPERATURE 30
#define MIN_TEMPERATURE 15

typedef struct {
    char name[30];
    int state; // 0: off, 1: on
} Light;

typedef struct {
    char name[30];
    int temperature; // in Celsius
} Thermostat;

Light lights[MAX_LIGHTS];
Thermostat thermostat;
pthread_mutex_t lock;

void initialize_system() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light_%d", i + 1);
        lights[i].state = 0;
    }
    snprintf(thermostat.name, sizeof(thermostat.name), "Thermostat_01");
    thermostat.temperature = 22; // Default temperature
    pthread_mutex_init(&lock, NULL);
}

void toggle_light(int index) {
    pthread_mutex_lock(&lock);
    lights[index].state = !lights[index].state; // Toggle state
    printf("%s is now %s\n", lights[index].name, lights[index].state ? "ON" : "OFF");
    pthread_mutex_unlock(&lock);
}

void set_temperature(int temp) {
    pthread_mutex_lock(&lock);
    if (temp >= MIN_TEMPERATURE && temp <= MAX_TEMPERATURE) {
        thermostat.temperature = temp;
        printf("%s temperature set to %d°C\n", thermostat.name, thermostat.temperature);
    } else {
        printf("Temperature out of range! Set between %d°C and %d°C.\n", MIN_TEMPERATURE, MAX_TEMPERATURE);
    }
    pthread_mutex_unlock(&lock);
}

void* listen_commands(void* arg) {
    char command[50];
    while (1) {
        printf("Enter command (toggle <light index> / settemp <temp> / quit): ");
        fgets(command, sizeof(command), stdin);
        
        if (strncmp(command, "toggle", 6) == 0) {
            int index;
            sscanf(command + 7, "%d", &index);
            if (index < 1 || index > MAX_LIGHTS) {
                printf("Invalid light index. Please enter a number between 1 and %d.\n", MAX_LIGHTS);
            } else {
                toggle_light(index - 1);
            }
        } else if (strncmp(command, "settemp", 8) == 0) {
            int temp;
            sscanf(command + 9, "%d", &temp);
            set_temperature(temp);
        } else if (strncmp(command, "quit", 4) == 0) {
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
    return NULL;
}

void cleanup() {
    pthread_mutex_destroy(&lock);
}

int main() {
    signal(SIGINT, cleanup); // Clean up on Ctrl+C

    initialize_system();
    
    pthread_t command_thread;
    pthread_create(&command_thread, NULL, listen_commands, NULL);

    pthread_join(command_thread, NULL); // Wait for command thread to finish
    
    cleanup();
    printf("Smart Home System shutting down. Goodbye!\n");
    return 0;
}