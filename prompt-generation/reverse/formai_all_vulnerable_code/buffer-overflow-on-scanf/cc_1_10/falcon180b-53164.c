//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TEMP_SENSORS 10

struct temp_sensor {
    int id;
    double temperature;
    time_t last_update;
};

struct temp_sensor sensors[MAX_TEMP_SENSORS];
int num_sensors = 0;

void *update_sensor_thread(void *arg) {
    int id = *(int *) arg;
    while (1) {
        sleep(5);
        sensors[id].temperature += 1.0;
        sensors[id].last_update = time(NULL);
    }
    return NULL;
}

int main() {
    int i;
    for (i = 0; i < MAX_TEMP_SENSORS; i++) {
        sensors[i].id = i;
        sensors[i].temperature = 0.0;
        sensors[i].last_update = 0;
    }
    num_sensors = 0;

    while (1) {
        printf("Enter sensor ID to add (-1 to stop): ");
        scanf("%d", &i);
        if (i == -1) {
            break;
        }
        if (num_sensors >= MAX_TEMP_SENSORS) {
            printf("Maximum number of sensors reached.\n");
        } else {
            sensors[num_sensors].id = i;
            sensors[num_sensors].temperature = 0.0;
            sensors[num_sensors].last_update = 0;
            num_sensors++;
        }
    }

    for (i = 0; i < num_sensors; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, update_sensor_thread, (void *) &i);
    }

    while (1) {
        printf("Enter sensor ID to display temperature: ");
        scanf("%d", &i);
        if (i >= 0 && i < num_sensors) {
            printf("Temperature for sensor %d: %.2f\n", i, sensors[i].temperature);
        } else {
            printf("Invalid sensor ID.\n");
        }
    }

    return 0;
}