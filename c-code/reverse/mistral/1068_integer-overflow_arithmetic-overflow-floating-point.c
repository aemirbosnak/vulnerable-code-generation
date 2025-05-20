#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define SHM_KEY 1234
#define SHM_SIZE 4096

typedef struct {
    float temperature;
    char display[256];
} TemperatureSensor;

int main() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    TemperatureSensor *sensor = (TemperatureSensor *)shmat(shmid, NULL, 0);

    float temp = 0;
    int i = 0;

    while (1) {
        temp += 1000000.0; // Introduce integer overflow
        sensor->temperature = temp /= 1000.0;
        snprintf(sensor->display, sizeof(sensor->display), "Temperature: %.2f°C", sensor->temperature);

        i++;
        if (i > 20) {
            i = 0;
            sleep(1);
        }
    }

    shmdt(sensor);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
