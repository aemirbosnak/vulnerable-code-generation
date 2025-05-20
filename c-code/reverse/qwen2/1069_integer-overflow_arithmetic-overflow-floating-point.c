#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <time.h>

#define SHM_SIZE 1024

typedef struct {
    int temp;
} SharedData;

void update_shape(int temp) {
    if (temp > 30) printf("Hot: 🔥🔥🔥\n");
    else if (temp > 20) printf("Warm: 🌞🌞🌞\n");
    else if (temp > 10) printf("Moderate: ☀️☀️☀️\n");
    else if (temp > 5) printf("Cold: ❄️❄️❄️\n");
    else printf("Very Cold: ⛄️🌨️🌨️\n");
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    SharedData *shared_data = (SharedData *)shmat(shmid, NULL, 0);

    if ((long)shared_data == -1) {
        perror("shmat failed");
        exit(1);
    }

    srand(time(NULL));
    while (1) {
        shared_data->temp += rand() % 11 - 5; // Random fluctuation between -5 and +5
        update_shape(shared_data->temp);
        sleep(1);
    }

    if (shmdt(shared_data) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}
