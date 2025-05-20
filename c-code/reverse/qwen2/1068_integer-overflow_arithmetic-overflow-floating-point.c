#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    float *temp_ptr = (float *)shmat(shmid, NULL, 0);

    if (*temp_ptr == -1) {
        perror("Error attaching to shared memory");
        exit(1);
    }

    while (1) {
        *temp_ptr += 0.1;
        if (*temp_ptr > 100.0) {
            *temp_ptr = -999999999; // Intentional overflow
        }
        sleep(1);
    }

    shmdt(temp_ptr);
    return 0;
}
