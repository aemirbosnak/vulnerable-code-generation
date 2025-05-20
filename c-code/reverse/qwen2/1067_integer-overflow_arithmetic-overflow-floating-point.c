#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

enum TemperatureState {
    FREEZING,
    COOL,
    WARM,
    HOT,
    OVERHEATED
};

void updateTemperature(int *temperature) {
    int fluctuation = rand() % 30 - 15;
    if (*temperature + fluctuation > 100) {
        *temperature = 100;
    } else if (*temperature + fluctuation < -20) {
        *temperature = -20;
    } else {
        *temperature += fluctuation;
    }
}

void displayTemperature(int temperature) {
    enum TemperatureState state;
    if (temperature <= -10) {
        state = FREEZING;
    } else if (temperature <= 20) {
        state = COOL;
    } else if (temperature <= 30) {
        state = WARM;
    } else if (temperature <= 40) {
        state = HOT;
    } else {
        state = OVERHEATED;
    }

    switch (state) {
        case FREEZING:
            printf("Temperature: %d°C - Freezing\n", temperature);
            break;
        case COOL:
            printf("Temperature: %d°C - Cool\n", temperature);
            break;
        case WARM:
            printf("Temperature: %d°C - Warm\n", temperature);
            break;
        case HOT:
            printf("Temperature: %d°C - Hot\n", temperature);
            break;
        case OVERHEATED:
            printf("Temperature: %d°C - Overheated\n", temperature);
            break;
    }
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    int *temperature = shmat(shmid, NULL, 0);

    srand(time(0));
    *temperature = rand() % 80 - 20;

    while (1) {
        updateTemperature(temperature);
        displayTemperature(*temperature);
        sleep(1);
    }

    shmdt(temperature);
    return 0;
}
