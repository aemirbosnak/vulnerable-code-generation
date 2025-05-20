#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 27

int main() {
    int shmid;
    key_t key = 12345;
    char *shmaddr;

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    int current_temp = atoi(shmaddr);
    int new_temp = current_temp + 1000; // Intentional integer overflow

    if (new_temp < current_temp) { // Check for overflow
        printf("Temperature overflow detected!\n");
        exit(1);
    }

    sprintf(shmaddr, "%d", new_temp);

    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
