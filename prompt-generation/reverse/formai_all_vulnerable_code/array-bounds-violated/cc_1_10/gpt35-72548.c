//FormAI DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define NUM_SENSORS 3
#define TEMP_THRESHOLD 80

pthread_mutex_t lock;
int tempReading[NUM_SENSORS];

void *readTemp(void *sensorNum) {
    int sensor = *(int *) sensorNum;
    while(1) {
        srand(time(NULL));
        int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        printf("Sensor %d Reading: %d\n", sensor, temp);
        pthread_mutex_lock(&lock);
        tempReading[sensor] = temp;
        pthread_mutex_unlock(&lock);
        sleep(2);
    }
}

void *checkTemp(void *arg) {
    while(1) {
        pthread_mutex_lock(&lock);
        int maxTemp = 0;
        int maxSensor = -1;

        for(int i = 0; i < NUM_SENSORS; i++) {
            if(tempReading[i] > maxTemp) {
                maxTemp = tempReading[i];
                maxSensor = i;
            }
        }

        if(maxTemp > TEMP_THRESHOLD) {
            printf("Warning! Temperature exceeds threshold: Sensor %d, Temperature %d\n", 
                maxSensor, maxTemp);
        }

        pthread_mutex_unlock(&lock);
        sleep(4);
    }
}

int main() {
    pthread_t sensors[NUM_SENSORS];
    int sensorNums[] = {1, 2, 3};

    pthread_t tempReader;
    
    if(pthread_mutex_init(&lock, NULL) != 0) { 
        printf("Mutex initialization failed.\n"); 
        return 1; 
    }

    for(int i = 0; i < NUM_SENSORS; i++) {
        pthread_create(&sensors[i], NULL, readTemp, &sensorNums[i]);
    }

    pthread_create(&tempReader, NULL, checkTemp, NULL);

    for(int i = 0; i < NUM_SENSORS; i++) {
        pthread_join(sensors[i], NULL);
    }

    pthread_join(tempReader, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}