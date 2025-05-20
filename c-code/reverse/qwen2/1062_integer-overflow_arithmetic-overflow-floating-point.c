#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 27

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    char *str = (char*) shmat(shmid, NULL, 0);

    srand(time(0));
    while (1) {
        int temp = rand() % 100 - 50;
        if (temp > 30) {
            sprintf(str, "Hot: 🔥");
        } else if (temp > 20 && temp <= 30) {
            sprintf(str, "Warm: 🌞");
        } else if (temp > 10 && temp <= 20) {
            sprintf(str, "Moderate: ☀️");
        } else if (temp > 0 && temp <= 10) {
            sprintf(str, "Cool: 🍃");
        } else if (temp >= -10 && temp <= 0) {
            sprintf(str, "Cold: ❄️");
        } else {
            sprintf(str, "Freezing: 🌨️");
        }
        printf("%s\n", str);
        sleep(1);
    }

    shmdt(str);
    return 0;
}
