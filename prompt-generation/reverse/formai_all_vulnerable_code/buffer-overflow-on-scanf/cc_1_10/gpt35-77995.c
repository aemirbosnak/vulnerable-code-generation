//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// function to simulate smart home lighting control
void* lighting_control(void* arg) {
    bool* light_status = (bool*)arg;

    while(true) {
        int choice;
        printf("\n*** Smart Home Lighting Controls ***\n");
        printf("1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                *light_status = true;
                printf("Lights turned on.\n");
                break;

            case 2:
                *light_status = false;
                printf("Lights turned off.\n");
                break;

            case 3:
                pthread_exit(NULL);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}

// function to simulate smart home temperature control
void* temperature_control(void* arg) {
    int* temperature = (int*)arg;

    while(true) {
        int choice;
        printf("\n*** Smart Home Temperature Controls ***\n");
        printf("1. Increase temperature\n");
        printf("2. Decrease temperature\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                *temperature += 1;
                printf("Temperature increased to %d degrees.\n", *temperature);
                break;

            case 2:
                *temperature -= 1;
                printf("Temperature decreased to %d degrees.\n", *temperature);
                break;

            case 3:
                pthread_exit(NULL);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    bool light_status = false;
    int temperature = 25;

    // create threads for lighting control and temperature control
    pthread_t lighting_thread, temperature_thread;

    pthread_create(&lighting_thread, NULL, lighting_control, &light_status);
    pthread_create(&temperature_thread, NULL, temperature_control, &temperature);

    // wait for threads to complete
    pthread_join(lighting_thread, NULL);
    pthread_join(temperature_thread, NULL);

    return 0;
}