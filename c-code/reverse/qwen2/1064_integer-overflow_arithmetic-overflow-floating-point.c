#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 4096

int main() {
    int shmid;
    key_t key = 12345;
    float *shmaddr;

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (float *) -1) {
        perror("shmat");
        exit(1);
    }

    float temp = *(shmaddr + 0);
    float scale_factor = *(shmaddr + 1);

    // Vulnerable calculation that could lead to integer overflow
    float transformed_temp = temp * scale_factor;

    printf("Original Temperature: %f\n", temp);
    printf("Transformed Temperature: %f\n", transformed_temp);

    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
